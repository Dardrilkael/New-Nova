#include "novapch.h"
#include <Nova.h> 

class GameLayer : public Nova::Layer
{
private:
	Nova::Shader* m_Shader;
	Nova::Texture* t1;
	Nova::Mesh* m_Object;
public:
	GameLayer():
		Layer()
	{
		m_Shader = Nova::Shader::Create("D:/users/GABRIEL/Programming/c++/Nova/SandBoxApp/src/Shader/Basic.shader");


		m_Shader->SetVec4("color", 0.314f, 0.2789f, 0.168f, 1.0f);

		m_Object = new Nova::Mesh(
			{
				{glm::vec3(-0.5f, -0.5f, 0.0f),	glm::vec4(0.8f, 0.0f, 0.0f, 1.0f)},
				{glm::vec3(-0.5f,  0.5f, 0.0f),	glm::vec4(0.0f, 0.8f, 0.0f, 1.0f)},
				{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec4(0.0f, 0.0f, 0.8f, 1.0f)},
				{glm::vec3(0.5f,  0.5f, 0.0f), glm::vec4(0.0f, 0.0f, 0.8f, 1.0f)}
			},
			{ 0,1,2,
			  1,2,3
			},
		{
			{ "aPos",Nova::BufferType::Float3 },
			{ "color",Nova::BufferType::Float4 },
			{ "textcoords",Nova::BufferType::Float2 },
		}
		, *m_Shader,
			Nova::Material()
		);
		m_Object->Move(glm::vec3(0.0f, 0.0f, -0.5f));
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
		//NOVA_LOG_CRITICAL("{0}",e);
	}


	virtual void OnUpdate() override
	{

		Nova::Application::Get()->GetRenderer()->BeginScene(Nova::Application::Get()->GetCamera());

		Nova::Application::Get()->GetRenderer()->Submit(*m_Object);
		//m_Text->RenderText("LETRAS\nASD", "Arial", 25.0f, { 10.0f,0.0f });
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Nova::Application::Get()->GetRenderer()->EndScene();
		//m_Text->AddFont("Arial", "D:/users/GABRIEL/Programming/c++/Nova/SandBoxApp/src/font/alphabet.png");
	}

	

};

class SandBoxApp : public Nova::Application
{
public:
	SandBoxApp()
	{
		this->PushOverlay(new GameLayer());
	}
	~SandBoxApp(){}
};

Nova::Application* Nova::CreateApplication()
{
	return new SandBoxApp;
}