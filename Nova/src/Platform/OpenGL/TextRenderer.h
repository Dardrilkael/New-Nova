#pragma once
#include "novapch.h"
#include "Platform/OpenGL/OpenGLTexture.h"
#include "Renderer/Buffer.h"
#include "glm/glm.hpp"
#include "novapch.h"

#include "Renderer/Shader.h"

namespace Nova
{
	struct FontTex
	{
		std::string name;
		Texture* texture;
	};

	class Text
	{
	public:
		Text(const char* shaderpath);
		void AddFont(std::string name, const char* path);
	
		void RenderText(const std::string& text, const std::string& font, uint32_t size, glm::vec2 pos);
	
	private:
		VertexBufferLayout* m_Layout;
		std::shared_ptr <VertexArray> m_VAO;
		std::shared_ptr<IndexBuffer> m_IBO;
		std::shared_ptr<VertexBuffer> m_VBO;
		std::vector<FontTex> m_Fonts;
		//static Text* s_Text;
		Shader* m_Shader;
		glm::mat4 m_Proj;
	};
	
}