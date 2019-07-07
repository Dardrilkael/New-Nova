#pragma once
#include "novapch.h"
#include <glm/glm.hpp>
#include "Renderer/Buffer.h"

namespace Nova
{

class RendererAPI
{public:
	enum class API
	{
		None   = 0, 
		OpenGL = 1,
	};
	virtual void SetColor(const glm::vec4& color) = 0;
	virtual void Clear() = 0;

	virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

	inline static API GetApi() { return s_API; }
private:
	static API s_API;
};

}

