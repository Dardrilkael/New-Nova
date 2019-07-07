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

#include "Events/KeyEvent.h"
#include <thread>
#include <chrono>
bool should[10];
#define speed 0.001f
namespace Nova
{
	
	Application* Application::s_Instance = nullptr;
	Application::Application():
	m_Camera()
	{
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Renderer = new Renderer;
		m_Window->SetAspectRatio(16, 9);
		m_Window->SetVsync(true);
		m_Shader = Shader::Create("D:/users/GABRIEL/Programming/c++/Nova/SandBoxApp/src/Shader/Basic.shader");
	
		m_Object = new Mesh(
			{
				{glm::vec3(-0.5f, -0.5f, 0.0f),	glm::vec4(0.8f, 0.0f, 0.0f, 1.0f)},
				{glm::vec3(0.0f,  0.5f, 0.0f),	glm::vec4(0.0f, 0.8f, 0.0f, 1.0f)},
				{glm::vec3(0.5f, -0.5f,0.0f),	glm::vec4(0.0f, 0.0f, 0.8f, 1.0f)}
			},
			{ 0,1,2 },
			{
			{ "aPos",BufferType::Float3 },
			{ "color",BufferType::Float4 },
			
			}
			,*m_Shader,
			Material()
			);
		m_Object->Move(glm::vec3(0.0f, 0.0f, -0.5f));


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
		float deltatime = 0.0f;
		float previous = 0;
		float now = 0.0f;

		float time = 0;

		while (m_Running)
		{
			now = glfwGetTime();
			deltatime = now-previous;
			previous = now;

			RenderCommand::GetAPI()->SetColor(glm::vec4(abs(1 - sin(time)), abs(1 - sin(time + 2.095)), abs(1 - sin(time + 4.19)), 1.0f));
			RenderCommand::GetAPI()->Clear();

			m_Camera.Update();


			m_Window->SetTitle(std::to_string(1/deltatime).c_str());
			if (should[0])m_Camera.Displace(glm::vec3(speed, 0.0f, 0.0f));
			if (should[1])m_Camera.Displace(glm::vec3(-speed, 0.0f, 0.0f));
			if (should[2])m_Camera.Displace(glm::vec3(0.0f, 0.0f, speed));
			if (should[3])m_Camera.Displace(glm::vec3(0.0f, 0.0f, -speed));

			time = glfwGetTime();
			m_Shader->SetVec4("color", sin(time), sin(time + 2.095), sin(time + 4.19),1.0f);


			m_Renderer->BeginScene(&m_Camera);
			m_Renderer->Submit(*m_Object);
			m_Renderer->EndScene();
			
			m_Window->Update();

		}
	}
	

	Application::~Application()
	{
	}

}