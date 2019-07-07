#include "novapch.h"
#include "Objects/Objects.h"
#include <glad/glad.h>
#include "Objects.h"


namespace Nova
{
	Mesh::Mesh(const std::initializer_list<Vertex>& vertices, const std::initializer_list<uint32_t>& indices, const VertexBufferLayout& layout, Shader& shader, Material& material) :
		m_Vertices(vertices), m_Indices(indices),m_Shader(shader),m_Material(material)
	{
		
		m_VertexArray.reset(VertexArray::Create());
		m_VertexBuffer.reset(VertexBuffer::Create(&(m_Vertices.begin()->vertex[0]),vertices.size()*sizeof(BufferElement)));
		m_IndexBuffer.reset(IndexBuffer::Create(&m_Indices.begin()[0], indices.size()*sizeof(uint32_t)));
		m_VertexBuffer->addLayout(layout);
		m_VertexArray->AddBuffer(m_VertexBuffer, m_IndexBuffer);


		//for (auto& k : m_Material)
		//{
		//	switch (k.type)
		//	{
			//case BufferType::Mat4: m_Shader.SetMat4(k.name, k.value);
			//default:
		//		break;
			//}
			
		//}

		for (auto& i : vertices)
		{
			for(int j =0; j<3; ++j)
			std::cout << i.vertex[j]<<std::endl;
			std::cout << std::endl;
		}

		m_Model = glm::mat4(1.0f);

	}

	void Mesh::Update() 
	{
		m_Shader.SetMat4("model", &m_Model[0][0]);

	}

}