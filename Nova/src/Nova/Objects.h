#pragma once 
#include "Nova/Renderer/Buffer.h"
#include <glm/glm.hpp>

namespace Nova
{

struct Vertex
{
	glm::vec3 vertex;
	glm::vec4 color;

};

class Mesh
{
public:
	Mesh(const std::initializer_list<Vertex>& vertices, const std::initializer_list<uint32_t>& indices, const VertexBufferLayout& layout);

	void Draw();

	VertexArray& GetVertexArray()const { return *m_VertexArray; }

private:
	std::unique_ptr<VertexArray> m_VertexArray;
	std::unique_ptr<VertexBuffer> m_VertexBuffer;
	std::unique_ptr<IndexBuffer> m_IndexBuffer;
	std::vector<Vertex> m_Vertices;
	std::vector<uint32_t> m_Indices;


};

}