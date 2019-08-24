#include "novapch.h"
#include "Core.h"

#include "Application.h"
#include "Platform/Windows/WindowsWindow.h"
#include "glad/glad.h"

#include "Nova/Log.h"

#include "Platform/Opengl/OpenGLShader.h"
#include "Math.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"



#include <thread>
#include <chrono>

#include "Platform/OpenGL/OpenGLTexture.h"

#include "Platform/OpenGL/TextRenderer.h"

#include <conio.h>


namespace Nova
{
	
	bool Application::OnClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}


	Application* Application::s_Instance = nullptr;
	Application::Application() 
	{
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetAspectRatio(16, 9);
		m_Window->SetVsync(true);
		m_Window->SetEventCallback(NOVA_BIND_EVENT_FN(Application::OnEvent));
		m_ImGuiLayer = new ImGuiLayer();
		//PushOverlay(m_ImGuiLayer);

	}

	void Application::Run()
	{

		RenderCommand::GetAPI()->SetColor(glm::vec4(1.0f, 0.12f, 0.5f, 1.0f));

		float PreviousTime = 0.0f;
	
		while (m_Running)
		{
			float CurrentTime = (float)glfwGetTime();
			m_Clock.SetDeltaTime(CurrentTime - PreviousTime);
			PreviousTime = CurrentTime;
			
			
			RenderCommand::GetAPI()->Clear();

			for (Layer* layer : m_LayerStack)
			{
		
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

	

			m_Window->SetTitle(std::to_string(1/m_Clock.GetDeltaTime()).c_str());
			
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