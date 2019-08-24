#include "novapch.h"
#include "WindowsWindow.h"
#include "Nova/Core.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "Nova/Log.h"

#include "Nova/Events/KeyEvent.h"
#include "Nova/Events/MouseEvent.h"
#include "Nova/Events/WindowEvent.h"

namespace Nova
{
	static bool GLFW_INITIALIZED = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	void WindowsWindow::SetAspectRatio(uint32_t x, uint32_t y)
	{
		glfwSetWindowAspectRatio(m_Window, x, y);
	}

	void WindowsWindow::SetTitle(const char* title)
	{
		m_Data.Title = title;
		glfwSetWindowTitle(m_Window, title);
	}

	void WindowsWindow::SetVsync(bool state)
	{
		m_Data.Vsync = state;
		if (state)glfwSwapInterval(1);
		else glfwSwapInterval(0);

	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
{
	if (!GLFW_INITIALIZED)
	{
		NOVA_CORE_ASSERT(glfwInit(),"Could not initialize GLFW\n");
		GLFW_INITIALIZED = true;
	}
	m_Data.Height = props.Height;
	m_Data.Width = props.Width;
	m_Data.Title = props.Title;

	m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
	m_Context = new OpenGLContext(m_Window);
	m_Context->Init();
	
	glfwSetWindowUserPointer(m_Window, (void*)&m_Data);


	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent e(key);
				data.EventCallback(e);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent e(key);
				data.EventCallback(e);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent e(key);
				data.EventCallback(e);
				break;
			}
			}

		});



	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			//glViewport(0, 0, width, height);
		});


	glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent e(codepoint);
			data.EventCallback(e);
		});




	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent e;
			data.EventCallback(e);

		});


	glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowMovedEvent e(xpos, ypos);
			data.EventCallback(e);
		});



	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			WindowResizeEvent e(width, height);
			data.EventCallback(e);

		});

	glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			if (focused)
			{
				WindowFocusEvent e;
				data.EventCallback(e);
			}
			else
			{
				WindowLostFocusEvent e;
				data.EventCallback(e);
			}

		});


	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent e(button);
				data.EventCallback(e);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent e(button);
				data.EventCallback(e);
				break;
			}
			}


		});

	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent e((float)xoffset, (float)yoffset);
			data.EventCallback(e);
		});

	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent e((float)xpos, (float)ypos);
			data.EventCallback(e);

		});






}

WindowsWindow::~WindowsWindow()
{
	
}


void WindowsWindow::Update()
{
	glfwPollEvents();							
	m_Context->SwapBuffers();
}



}