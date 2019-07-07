#pragma once
#include "RendererAPI.h"

namespace Nova
{
	class RenderCommand
	{
	public:
		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}
		inline static RendererAPI* GetAPI() { return s_RendererAPI; }
	private:
		static RendererAPI* s_RendererAPI;
	};
}
