#pragma once 
#include "Nova/Renderer/Buffer.h"
#include "Nova/Math.h"
#include "Nova/Renderer/Materials.h"
#include "Nova/Core.h"

namespace Nova
{
	enum class BufferType;
	struct Material_item
	{
		const char* name;
		BufferType type;

	};

	struct Vertex
	{
		Vec3 vertex;
		Vec4 color;
		Vec2 texCoords;

	};



	class Mesh
	{
	public:
		Mesh(const std::initializer_list<Vertex>& vertices, const std::initializer_list<uint32_t>& indices, const VertexBufferLayout& layout, Material& material);
		void Update();
		void Displace(const glm::vec3& displacement)
		{
			m_Model = glm::translate(m_Model, displacement);
		}

		const std::shared_ptr<VertexArray>& GetVertexArray()const { return m_VertexArray; }
		const Shader& GetShader()const { return *m_Material.m_Shader; }
		inline float* GetModel() { return &m_Model[0][0]; }

		Material& m_Material;
	private:
		Ref<VertexArray> m_VertexArray;
		Ref<VertexBuffer> m_VertexBuffer;
		Ref<IndexBuffer> m_IndexBuffer;
		std::vector<Vertex> m_Vertices;
		std::vector<uint32_t> m_Indices;


		glm::mat4 m_Model;

	};

}