#include "src/graphics/window.h"

int main()
{
	using namespace MASCHINE;
	using namespace graphics;

	Window window("MASCHINE", 1440, 900);
	glClearColor(0.2f, 0.3f, 0.9f, 1.0f);

	GLuint vao;									//GL Version Testing
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


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
