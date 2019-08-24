#include "novapch.h"
#include "Nova/Objects/Objects.h"
#include <glad/glad.h>
#include "Objects.h"


namespace Nova
{
	Mesh::Mesh(const std::initializer_list<Vertex>& vertices, const std::initializer_list<uint32_t>& indices, const VertexBufferLayout& layout, Material& material) :
		m_Vertices(vertices), m_Indices(indices), m_Material(material)
	{
		
		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(&(m_Vertices.begin()->vertex[0]),vertices.size()*sizeof(BufferElement));
		m_IndexBuffer = IndexBuffer::Create(&m_Indices.begin()[0], indices.size()*sizeof(uint32_t));
		m_VertexBuffer->addLayout(layout);
		m_VertexArray->AddBuffer(m_VertexBuffer, m_IndexBuffer);

		m_Model = glm::mat4(1.0f);

	}

	void Mesh::Update() 
	{
		m_Material.m_Shader->SetMat4("model", &m_Model[0][0]);

	}

}