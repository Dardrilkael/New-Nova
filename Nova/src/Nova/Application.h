#pragma once
#include "Core.h"
#include "Renderer/Shader.h"
#include <memory>

#include "Window.h"

#include "Renderer/Buffer.h"
#include "Renderer/Renderer.h"

#include "Objects/Objects.h"
#include "Renderer/Camera.h"
#include "Platform/OpenGL/TextRenderer.h"

#include "Layer.h"
#include "LayerStack.h"

#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/EventCode.h"
#include "Events/WindowEvent.h"
#include "Events/MouseEvent.h"
#include "Nova/Clock.h"

namespace Nova
{
	

class NOVA_API Application
{
public:
	Application();
	~Application();
public:
	void Run();
	inline Window& GetWindow()const { return *m_Window; }
	inline static Application* Get() { return s_Instance; } 
	//
	Renderer* GetRenderer() { return m_Renderer; }
	Camera* GetCamera() { return &m_Camera; }
	//
	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);

	Camera m_Camera;
private:
	bool m_Running = true;
private:
	static Application* s_Instance;
	std::shared_ptr<Window> m_Window;
	LayerStack m_LayerStack;

	Shader* m_Shader;
	Mesh* m_Object;
	Renderer* m_Renderer;

	Text* m_Text;
private:
	bool OnClose(WindowCloseEvent& e);
public:
	Clock m_Clock;
};


Application* CreateApplication();

}
