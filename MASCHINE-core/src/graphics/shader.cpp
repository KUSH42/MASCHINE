#include <iostream>
#include <vector>
#include "shader.h"

namespace MASCHINE { namespace graphics {

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
		: m_vertexPath(vertexPath), m_fragmentPath(fragmentPath)
	{
		m_shaderID = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_shaderID);
	}

	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);


		std::string vertexSourceString = FileUtils::read_file(m_vertexPath);
		std::string fragmentSourceString = FileUtils::read_file(m_fragmentPath);
		const char* vertexSource = vertexSourceString.c_str();
		const char* fragmentSource = fragmentSourceString.c_str();

		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile vertex shader!" << &error[0] << std::endl;
			glDeleteShader(vertex);

			return 0;			//failed
		}

		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader!" << &error[0] << std::endl;
			glDeleteShader(fragment);

			return 0;			//failed
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}


	void Shader::enable() const
	{
		glUseProgram(m_shaderID);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

} }