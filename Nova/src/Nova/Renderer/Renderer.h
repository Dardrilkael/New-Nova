#pragma once
#include "RenderCommand.h"
#include "Nova/Objects/Objects.h"


namespace Nova
{
class Camera;

	class Renderer
	{
	public:
		
		static void BeginScene(Camera* camera);
		static void EndScene();
		static void Submit(Mesh& mesh);

		inline static RendererAPI::API GetAPI(){ return RendererAPI::GetApi(); }

	private:
		static bool InScene;
		static Camera* s_Camera;
	};
	

}