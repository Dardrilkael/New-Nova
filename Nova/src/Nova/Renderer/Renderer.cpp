#include "novapch.h"
#include "Renderer.h"
#include "RenderCommand.h"
#include "Camera.h"

namespace Nova
{
	bool Renderer::InScene = false;
	Camera* Renderer::s_Camera = nullptr;
	//RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;
	void Renderer::BeginScene(Camera* camera)
	{
		if (camera)
		Renderer::s_Camera = camera;
		InScene = true;
	}

	void Renderer::EndScene()
	{
		NOVA_CORE_ASSERT(InScene, "EndScene should end an open Scene");
		InScene = false;
	}

	void Renderer::Submit(Mesh& mesh)
	{
	
		mesh.GetShader().Bind();
		mesh.GetShader().SetMat4("viewProj", Renderer::s_Camera->GetViewProjection());
		mesh.Update();
		NOVA_CORE_ASSERT(InScene, "A Scene should be started before rendering");
		RenderCommand::DrawIndexed(mesh.GetVertexArray());

		
	}
}