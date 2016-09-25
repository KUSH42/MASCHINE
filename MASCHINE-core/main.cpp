#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main()
{
	using namespace MASCHINE;
	using namespace graphics;
	using namespace maths;

	Window window("MASCHINE", 1440, 900);
	glClearColor(0.2f, 0.3f, 0.9f, 1.0f);

	GLuint vao;									//GL Version Testing
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 vector(1.0f, 2.0f);
	vec2 vectorb(1.0f, 2.0f);
	vec3 vectorc(1.0f, 2.0f, 3.0f);
	vec3 vectord(1.0f, 2.0f, 3.0f);
	vec4 vectore(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 vectorf(1.0f, 2.0f, 3.0f, 4.0f);

	vec2 vx = vector + vectorb;
	vec3 vy = vectorc + vectord;
	vec4 vz = vectore + vectorf;

	vy = vectorc+vectord;


	std::cout << vy << std::endl;
	std::cout << vectorc << std::endl;
	std::cout << vectord << std::endl;

	while (!window.closed())
	{
		window.clear();
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "Key pressed" << std::endl;
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;

#if 1
		glBegin(GL_QUADS);						//draw basic rectangle
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);	//GLEW test
#endif
		window.update();
	}
	return 0;
}
