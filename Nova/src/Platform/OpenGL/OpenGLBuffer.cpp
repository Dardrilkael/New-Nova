#include "novapch.h"
#include "OpenGLBuffer.h"
#include "glad/glad.h"
#include "Nova/Core.h"


namespace Nova
{

	static GLenum GetGLType(BufferType tipo)
	{
		switch (tipo)
		{
		case Nova::BufferType::Float1:
			return GL_FLOAT;
			break;
		case Nova::BufferType::Float2:
			return GL_FLOAT;
			break;
		case Nova::BufferType::Float3:
			return GL_FLOAT;
			break;
		case Nova::BufferType::Float4:
			return GL_FLOAT;
			break;
		default:
			NOVA_CORE_ASSERT(false, "Unknown Type");
			break;
		}
	}



//--------------------\Vertex Buffer/--------------------//


OpenGLVertexBuffer::OpenGLVertexBuffer(float * vertices, uint32_t size, MemoryPlace place)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void OpenGLVertexBuffer::Bind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void OpenGLVertexBuffer::UnBind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLVertexBuffer::addLayout(const VertexBufferLayout& layout)
{

	int count = 0;
	int stride = 0;
	int offset = 0;

	for (auto& item : layout) {
		stride += GetSizeOfData(item.type);

	}
	for (auto& item : layout)
	{

		glVertexAttribPointer(count, GetCountOfData(item.type), GetGLType(item.type), item.normalized, stride, (void*)offset);
		glEnableVertexAttribArray(count);

		count++;
		offset += GetSizeOfData(item.type);

	}
}

//--------------------/Vertex Buffer\--------------------//



//------------------------------------------------------------//


//--------------------\Index Buffer/--------------------//

OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t * indices, uint32_t size):
	m_Count(0)
{
	m_Count = size/sizeof(uint32_t);
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void OpenGLIndexBuffer::Bind()const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void OpenGLIndexBuffer::UnBind()const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

//--------------------/Index Buffer\--------------------//



//------------------------------------------------------------//




//--------------------\Vertex Array/--------------------//


OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
	glBindVertexArray(m_RendererID);
}

void OpenGLVertexArray::Bind()
{
	glBindVertexArray(m_RendererID);
}

void OpenGLVertexArray::UnBind()
{
	glBindVertexArray(0);
}

void OpenGLVertexArray::AddBuffer(const std::shared_ptr<VertexBuffer>& vb, const std::shared_ptr<IndexBuffer>& ib)
{
	m_VertexBuffer = &vb;
	m_IndexBuffer = &ib;

	glBindVertexArray(m_RendererID);
	vb->Bind();
	ib->Bind();
}





//--------------------/Vertex Array\--------------------//

}





