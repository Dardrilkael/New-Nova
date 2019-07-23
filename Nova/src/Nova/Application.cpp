#include "novapch.h"
#include "Core.h"

#include "Application.h"
#include "Platform/Windows/WindowsWindow.h"
#include "glad/glad.h"

#include "Nova/Log.h"

#include "Platform/Opengl/OpenGLShader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_access.hpp"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"



#include <thread>
#include <chrono>

#include "Platform/OpenGL/OpenGLTexture.h"

#include "Platform/OpenGL/TextRenderer.h"

#include <conio.h>

bool should[10];
#define speed 1.0f
namespace Nova
{
	
	bool Application::OnClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}


	Application* Application::s_Instance = nullptr;
	Application::Application() :
	m_Camera()
	{
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Renderer = new Renderer;
		m_Window->SetAspectRatio(16, 9);
		//m_Window->SetVsync(true);
		m_Window->SetEventCallback(NOVA_BIND_EVENT_FN(Application::OnEvent));
		m_Text = new Text("D:/users/GABRIEL/Programming/c++/Nova/SandBoxApp/src/Shader/cheider.shader");


		
		glfwSetKeyCallback((GLFWwindow*)m_Window->GetNativeWindow(), [](GLFWwindow * window, int key, int scancode, int action, int mods)
		{
				if (key == GLFW_KEY_D && action == GLFW_PRESS)
					should[0] = true;
				if (key == GLFW_KEY_D && action == GLFW_RELEASE)
					should[0] = false;


				if (key == GLFW_KEY_A && action == GLFW_PRESS)
					should[1] = true;
				if (key == GLFW_KEY_A && action == GLFW_RELEASE)
					should[1] = false;

				if (key == GLFW_KEY_S && action == GLFW_PRESS)
					should[2] = true;
				if (key == GLFW_KEY_S && action == GLFW_RELEASE)
					should[2] = false;


				if (key == GLFW_KEY_W && action == GLFW_PRESS)
					should[3] = true;
				if (key == GLFW_KEY_W && action == GLFW_RELEASE)
					should[3] = false;
		});

	}



	

	void Application::Run()
	{

		float PreviousTime = 0.0f;
		float DeltaTime =0.0f;
		float FPS = 1000 / 60.0f;
		float time = 0;
		m_Clock.SetDeltaTime(60.0f);
		while (m_Running)
		{

			
			float CurrentTime = (float)glfwGetTime();
			DeltaTime = CurrentTime - PreviousTime;
			PreviousTime = CurrentTime;
			NOVA_CORE_LOG_DEBUG("Sleep Time: {0}", (int)(FPS - (1000 * DeltaTime)));
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(FPS - (1000 * DeltaTime))));

			
			RenderCommand::GetAPI()->SetColor(glm::vec4(abs(1 - sin(time)), abs(1 - sin(time + 2.095)), abs(1 - sin(time + 4.19)), 1.0f));
			RenderCommand::GetAPI()->Clear();

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Camera.Update();

			m_Window->SetTitle(std::to_string(1/DeltaTime).c_str());

			if (should[0])m_Camera.Displace(glm::vec3(speed, 0.0f, 0.0f));
			if (should[1])m_Camera.Displace(glm::vec3(-speed, 0.0f, 0.0f));
			if (should[2])m_Camera.Displace(glm::vec3(0.0f, 0.0f, speed));
			if (should[3])m_Camera.Displace(glm::vec3(0.0f, 0.0f, -speed));




			

			
			m_Window->Update();

		}
	}
	

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(NOVA_BIND_EVENT_FN(Application::OnClose));
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	Application::~Application()
	{
	}

}