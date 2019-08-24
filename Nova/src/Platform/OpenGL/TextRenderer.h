#pragma once
#include "novapch.h"
#include "Platform/OpenGL/OpenGLTexture.h"
#include "Nova/Renderer/Buffer.h"
#include "glm/glm.hpp"
#include "novapch.h"

#include "Nova/Renderer/Shader.h"

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
		void AddFont_impl(std::string name, const char* path);
		void RenderText_impl(const std::string& text, const std::string& font, uint32_t size, glm::vec2 pos);
	
	private:
		VertexBufferLayout* m_Layout;
		std::shared_ptr <VertexArray> m_VAO;
		std::shared_ptr<IndexBuffer> m_IBO;
		std::shared_ptr<VertexBuffer> m_VBO;
		std::vector<FontTex> m_Fonts;

		Shader* m_Shader;
		glm::mat4 m_Proj;
	public:
		inline static void Init(const char* shaderpath)
		{
			new Text(shaderpath);
		}
		inline static void DrawText(const std::string& text, const std::string& font, uint32_t size, glm::vec2 pos)
		{
			s_Instance->RenderText_impl(text, font, size, pos);
		}
		inline static void AddFont(std::string name, const char* path)
		{
			s_Instance->AddFont_impl(name, path);
		}
		static Text* s_Instance;
	};
	
}