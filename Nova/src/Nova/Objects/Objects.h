#pragma once 
#include "Nova/Renderer/Buffer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Nova/Renderer/Shader.h"

namespace Nova
{
	extern enum class BufferType;
	struct Material_item
	{
		const char* name;
		BufferType type;

	};
	struct Material
	{
		//std::vector

	};

class Mesh
{
public:
	struct Vertex
	{
		glm::vec3 vertex;
		glm::vec4 color;
		glm::vec2 texCoords;

	};



	Mesh(const std::initializer_list<Mesh::Vertex>& vertices, const std::initializer_list<uint32_t>& indices, const VertexBufferLayout& layout, Shader& shader, Material& material);
	void Update();
	const std::shared_ptr<VertexArray>& GetVertexArray()const { return m_VertexArray; }
	void Move(const glm::vec3& displacement)
	{
		m_Model = glm::translate(m_Model, displacement);
	}

	const Shader& GetShader()const { return m_Shader; }
private:
	std::shared_ptr<VertexArray> m_VertexArray;
	std::shared_ptr<VertexBuffer> m_VertexBuffer;
	std::shared_ptr<IndexBuffer> m_IndexBuffer;
	std::vector<Vertex> m_Vertices;
	std::vector<uint32_t> m_Indices;

	glm::mat4 m_Model;

	Material& m_Material;
	Shader& m_Shader;



};

}