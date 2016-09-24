#include "window.h"

namespace MASCHINE { namespace graphics {

	void window_resize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Height = height;
		m_Width = width;
		if (!init())
			glfwTerminate();
		
		for (int i = 0; i < MAX_KEYS; i++)
			m_Keys[i] = false;
		for (int i = 0; i < MAX_BUTTONS; i++)
			m_Buttons[i] = false;
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
	}

	bool Window::init()
	{	
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GFLW" << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);			//Establish context before initializing GLEW
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW" << std::endl;
			return false;
		}

		std::cout << "OpenGL"  << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void window_resize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		MASCHINE::graphics::Window* win = (MASCHINE::graphics::Window*) glfwGetWindowUserPointer(window);
		win->m_Keys[key] = (action != GLFW_RELEASE);
	}

	void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
	{
		MASCHINE::graphics::Window* win = (MASCHINE::graphics::Window*) glfwGetWindowUserPointer(window);
		win->m_Buttons[button] = (action != GLFW_RELEASE);
	}

	void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
	{
		MASCHINE::graphics::Window* win = (MASCHINE::graphics::Window*) glfwGetWindowUserPointer(window);
		win->mouse_x = xpos;
		win->mouse_y = ypos;
	}

	void Window::getMousePosition(double& x, double& y) const
	{
		x = mouse_x;
		y = mouse_y;
	}

	bool Window::isKeyPressed(unsigned int keycode) const
	{
		//TODO: Logging system
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int button) const
	{
		//TODO: Logging system
		if (button >= MAX_BUTTONS)
			return false;

		return m_Buttons[button];
	}

} }