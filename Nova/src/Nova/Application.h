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
private:
	bool m_Running = true;
private:
	static Application* s_Instance;
	std::shared_ptr<Window> m_Window;

	Shader* m_Shader;
	Mesh* m_Object;
	Renderer* m_Renderer;
	Camera m_Camera;
	Text* m_Text;
};


Application* CreateApplication();

}
