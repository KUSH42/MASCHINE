#include "src/graphics/window.h"

int main()
{
	using namespace MASCHINE;
	using namespace graphics;

	Window window("MASCHINE", 800, 600);
	glClearColor(0.2f, 0.3f, 0.9f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}
	return 0;
}
