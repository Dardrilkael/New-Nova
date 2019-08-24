#include "novapch.h"
#include "Buffer.h"
#include "Nova/Renderer/Renderer.h"
#include "Nova/Core.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Nova
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: return nullptr; break;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexArray>(); break;
		default:
			return nullptr;
			break;
		}
	}


	Ref<VertexBuffer> VertexBuffer::Create(float * vertices, uint32_t size, MemoryPlace place)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: return nullptr; break;
		case RendererAPI::API::OpenGL: return std::make_shared <OpenGLVertexBuffer>(vertices, size, place); break;
		default:
			return nullptr;
			break;
		}
	}
	Ref<IndexBuffer> IndexBuffer::Create(uint32_t * indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: return nullptr; break;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLIndexBuffer>(indices, size); break;
		default:
			return nullptr;
			break;
		}
	}


	VertexBufferLayout::VertexBufferLayout(const std::initializer_list<BufferElement>& elements):
		m_data(elements){}


	

	uint8_t GetCountOfData(BufferType type)
	{
		switch (type)
		{
		case BufferType::Float1: return 1;
		case BufferType::Float2: return 2;
		case BufferType::Float3: return 3;
		case BufferType::Float4: return 4;

		}
	}

	uint8_t GetSizeOfData(BufferType type)
	{
		return (uint8_t)type;
	}



}