#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src\utils\file_utils.h"
#include "src\graphics\shader.h"

int main()
{
	using namespace MASCHINE;
	using namespace graphics;
	using namespace maths;

	Window window("MASCHINE", 1440, 900);
	glClearColor(0.2f, 0.3f, 0.9f, 1.0f);


	GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
	 	 0.5f, 0.5f, 0.0f,
		 0.5f, 0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	GLuint vbo;		
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	glUniformMatrix4fv(shader.m_shaderID, 1, GL_FALSE, ortho.elements);

	while (!window.closed())
	{

		window.clear();
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "Key pressed" << std::endl;
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;

		glDrawArrays(GL_TRIANGLES, 0, 6);	//GLEW test

		window.update();
	}

	return 0;
}
