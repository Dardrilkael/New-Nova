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


#include "Nova/ImGui/ImGuiLayer.h"

namespace Nova
{
	

class NOVA_API Application
{
public:
	Application();
	~Application();
public:
	void Run();
	inline static Window& GetWindow(){ return *s_Instance->m_Window; }
	inline static Application& Get() { return *s_Instance; } 
	//

	float GetDeltaTime() { return m_Clock.GetDeltaTime(); }
	//
	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);


private:
	bool m_Running = true;
	ImGuiLayer* m_ImGuiLayer;
private:
	static Application* s_Instance;
	std::shared_ptr<Window> m_Window;
	LayerStack m_LayerStack;

	


private:
	bool OnClose(WindowCloseEvent& e);
public:
	Clock m_Clock;
};


Application* CreateApplication();

}
