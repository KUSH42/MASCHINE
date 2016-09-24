#ifndef __WINDOW_H_
#define __WINDOW_H_

#include <GL\glew.h>		//requires GLEW_STATIC preprocessor flag, include before GLFW
#include <GLFW\glfw3.h>
#include <iostream>

#define MAX_KEYS	448
#define MAX_BUTTONS	64

namespace MASCHINE { namespace graphics {

	class Window
	{
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;

		bool m_Keys[MAX_KEYS];
		bool m_Buttons[MAX_BUTTONS];
		double mouse_x, mouse_y;
	public:
		static Window* INSTANCE;
		Window(const char *title, int width, int height);
		~Window();
		bool closed() const;
		void update();
		void clear() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int button) const;
		void getMousePosition(double& x, double& y) const;
	private:
		bool init();
		friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
	};

} }

#endif // !__WINDOW_H_

