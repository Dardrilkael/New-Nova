#pragma once
#include "Nova/Renderer/RendererAPI.h"

namespace Nova
{
	class OpenGLRenderer: public RendererAPI
	{
		// Herdado por meio de RendererAPI
		
		virtual void SetColor(const glm::vec4& color) override;
		virtual void Clear() override;
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	public:
		OpenGLRenderer();
	};

}