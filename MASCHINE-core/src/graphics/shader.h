#ifndef __SHADER_H_
#define __SHADER_H_

#include <GL/glew.h>
#include "../utils/file_utils.h"

namespace MASCHINE { namespace graphics {

	class Shader
	{
	public:
		GLuint m_shaderID;
		const char* m_vertexPath;
		const char* m_fragmentPath;
	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void enable() const;
		void disable() const;

	private:
		GLuint load();
	};

} }

#endif // !__SHADER_H_
