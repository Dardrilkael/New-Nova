#include "novapch.h"
#include "Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Nova/Renderer/Renderer.h"

namespace Nova
{
Shader* Shader::Create(const char* path)
{
	switch (Renderer::GetAPI())
	{
	case RendererAPI::API::None:  NOVA_CORE_ASSERT(0,"Not one API is selected"); break;
	case RendererAPI::API::OpenGL: return new OpenGLShader(path); break;
	
	default:
		NOVA_CORE_ASSERT(0,"Not one API is selected");
		return nullptr;
		break;
	}
	

}


}