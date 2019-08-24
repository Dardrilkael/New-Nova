#include "novapch.h"
#include <Nova.h>
#include <D:/users/GABRIEL/Programming/c++/Nova/Nova/vendor/glfw/include/GLFW/glfw3.h>
#include "Platform/Opengl/OpenGLShader.h"
bool should[10];
#define speed 1.0f
glm::vec2 previous;
bool FIRST = true;
int s  =0;
class GameLayer : public Nova::Layer
{
private:
	Nova::Shader* m_Shader;
	Nova::Texture* t1;
	Nova::Mesh* m_Object;
	Nova::Camera* m_Camera;
	//Nova::Text* m_Text;
	Nova::Texture* t2;
public:
	GameLayer() :
		Layer()
	{
		//glfwSetInputMode((GLFWwindow*)Nova::Application::GetWindow().GetNativeWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		t2 = Nova::Texture::Create(Nova::Texture::TextureType::NOVA_TEXTURE_2D, "./src/texture/box.jpg");

		//Nova::Text::Init("D:/users/GABRIEL/Programming/c++/Nova/SandBoxApp/src/Shader/cheider.shader");
		//Nova::Text::AddFont("Arial", "./src/font/alphabet.png");
		m_Shader = Nova::Shader::Create("D:/users/GABRIEL/Programming/c++/Nova/SandBoxApp/src/Shader/Basic.shader");
		m_Camera = new Nova::Camera();

		m_Shader->SetVec4("color", 0.314f, 0.2789f, 0.168f, 1.0f);

		m_Object = new Nova::Mesh(
			{
				{{-0.5f,-0.5f, 0.0f}, {0.8f, 0.0f, 0.0f, 1.0f},{0.0f,0.0f}},
				{{-0.5f, 0.5f, 0.0f}, {0.0f, 0.8f, 0.0f, 1.0f},{0.0f,1.0f}},
				{{ 0.5f,-0.5f, 0.0f}, {0.0f, 0.0f, 0.8f, 1.0f},{1.0f,0.0f}},
				{{ 0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 0.8f, 1.0f},{1.0f,1.0f}},

				{{-0.5f,-0.5f, -1.0f}, {0.8f, 0.0f, 0.0f, 1.0f},{0.0f,0.0f}},
				{{-0.5f, 0.5f, -1.0f}, {0.0f, 0.8f, 0.0f, 1.0f},{1.0f,0.0f}},
				{{ 0.5f,-0.5f, -1.0f}, {0.0f, 0.0f, 0.8f, 1.0f},{1.0f,0.0f}},
				{{ 0.5f, 0.5f, -1.0f}, {0.0f, 0.0f, 0.8f, 1.0f},{1.0f,1.0f}},



			},
			{
			0,1,2,
			1,2,3,

			4,5,7,
			//4,7,6,
			
			0,4,2,
			4,6,2,

			1,5,7,
			1,7,3
			},

			{
				{ "aPos",       Nova::BufferType::Float3 },
				{ "color",      Nova::BufferType::Float4 },
				{ "textcoords", Nova::BufferType::Float2 },
			},
			*(new Nova::Material({ 1.0f,1.0f,1.0f }, t2, t2, m_Shader))
		);

		m_Object->Displace(glm::vec3(0.0f, 0.0f, -0.5f));

	}



	virtual void OnAttach() override
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}


	virtual void OnDetach() override
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}


	virtual void OnEvent(Nova::Event& e) override
	{
		Nova::EventDispatcher dispatcher(e);
		dispatcher.Dispatch<Nova::MouseMovedEvent>(NOVA_BIND_EVENT_FN(GameLayer::RotCamera));

	}
	bool RotCamera(Nova::MouseMovedEvent& e)
	{
		glm::vec2 now = glm::vec2(e.GetXpos(), e.GetYpos());
		glm::vec2 delta = now - previous;
		delta *= 6.0f;
		previous = now;
		if (FIRST)
		{
			//previous = glm::vec2(0.0f);
			delta = glm::vec2(0.0f);
			FIRST = false;
		}
		delta *= (Nova::Application::Get().GetDeltaTime());
		m_Camera->Rotate({ -delta.y,delta.x,0.0f });

		return true;
	}


	virtual void OnUpdate() override
	{
		float speedy = speed * Nova::Application::Get().GetDeltaTime();
		if (Nova::Input::IsKeyPressed(NOVA_KEY_A))m_Camera->Displace({ -speedy, 0.0f, 0.0f });
		if (Nova::Input::IsKeyPressed(NOVA_KEY_D))m_Camera->Displace({ +speedy, 0.0f, 0.0f });
		if (Nova::Input::IsKeyPressed(NOVA_KEY_W))m_Camera->Displace({ 0.0f, 0.0f, +speedy });
		if (Nova::Input::IsKeyPressed(NOVA_KEY_S))m_Camera->Displace({ 0.0f, 0.0f, -speedy });
		if (Nova::Input::IsKeyPressed(NOVA_KEY_SPACE))m_Camera->Displace({ 0.0f, speedy, 0.0f });
		if (Nova::Input::IsKeyPressed(NOVA_KEY_LEFT_SHIFT))m_Camera->Displace({ 0.0f, -speedy, 0.0f });
		Nova::Renderer::BeginScene(m_Camera);
		m_Camera->Update();
		Nova::Renderer::Submit(*m_Object);
		//Nova::Text::DrawText("LETRAS\nASD", "Arial", 25.0f, { 10.0f,0.0f });
		//m_Shader->SetInt("nao_funciona", 32);
		Nova::Renderer::EndScene();
		if (s<1)
		{
		((Nova::OpenGLShader*)m_Shader)->Debug();
		s ++;
		}
		
		
	}

	

};

class SandBoxApp : public Nova::Application
{
public:
	SandBoxApp()
	{
		this->PushLayer(new GameLayer);
	}
	~SandBoxApp(){}
};

Nova::Application* Nova::CreateApplication()
{
	return new SandBoxApp;
}