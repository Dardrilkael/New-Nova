#include "novapch.h"
#include "OpenGLRendererAPI.h"
#include <glad/glad.h>

Nova::OpenGLRenderer::OpenGLRenderer()
{
	//
}

void Nova::OpenGLRenderer::SetColor(const glm::vec4& color)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(color[0], color[1], color[2], color[3]);
}

void Nova::OpenGLRenderer::Clear()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Nova::OpenGLRenderer::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
{
	vertexArray->Bind();
	
	glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, NULL);
}
