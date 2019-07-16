#include "novapch.h"
#include "TextRenderer.h"
#include "glad/glad.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include "Application.h"
using namespace std::literals::chrono_literals;

namespace Nova

{

	

	Text::Text(const char* shaderpath)
	{
		m_Shader = Shader::Create(shaderpath);
		m_Shader->Bind();
		m_VAO.reset(VertexArray::Create());
		uint32_t indices[] = { 0,1,2,1,2,3 };
		m_IBO.reset(IndexBuffer::Create(indices, sizeof(indices)));
		m_Layout = new VertexBufferLayout(
			{
			{ "aPos",BufferType::Float2 },
			{ "aTexCoords",BufferType::Float2 },
			}
		);
		m_Proj = glm::ortho(0.0f, (float)Application::Get()->GetWindow().GetWidth(),
		(float)Application::Get()->GetWindow().GetHeight(),0.0f);
		m_Shader->SetMat4("proj", &m_Proj[0][0]);
		m_VBO = nullptr;
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	void Text::AddFont(std::string name, const char* path)
	{
		m_Fonts.push_back({ name, Texture::Create(TextureType::NOVA_TEXTURE_2D, path) });
	}
	void Text::RenderText(const std::string& text, const std::string& font, uint32_t size, glm::vec2 pos)
	{
		Texture* selectedTexture = nullptr;
		for (auto& i : m_Fonts)
		{
			if (i.name == font)
			{
				selectedTexture = i.texture;
				//NOVA_CORE_LOG_FATAL("TEXTURE SELECTED");
				break;
			}
		}
		m_Shader->Bind();
		selectedTexture->Bind(0);
		m_Shader->SetInt("texture1", 0);

		char c = 64;
		char b = c;
		float w = size;
		float h = size;
		Log::SetCoreLevel(Log::level_log::info);
		float xpos = pos.x;
		float ypos = pos.y;
		for (int i = 0; i < text.length(); i++)
		{
			
			//NOVA_CORE_LOG_SPECIAL("    : {0}  {1}", (int)c - 64,c);
			//std::this_thread::sleep_for(1s);
			
			c = text[i];
			b = c-1;
			NOVA_CORE_LOG_WARN("    : {0}  {1}", (int)c - 64, c);
			

			
			
			float vertices[24] = {
				xpos,     ypos,       ((int)b - 64)/7.0f, 0.0f,
				xpos,     ypos + h,   ((int)b - 64)/7.0f, 1.0f/4 + 0.03f,
				xpos + w, ypos,       ((int)c - 64)/7.0f, 0.0f,
				xpos + w, ypos + h,   ((int)c - 64)/7.0f, 1.0f/4+0.03f
			};
			
			m_VAO->Bind();
			m_VBO.reset(VertexBuffer::Create(vertices, sizeof(vertices), MemoryPlace::Dynamic));
			m_VBO->Bind();
			m_VBO->addLayout(*m_Layout);
			m_IBO->Bind();
			m_VAO->AddBuffer(m_VBO, m_IBO);
			
			glDrawElements(GL_TRIANGLES, m_VAO->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, NULL);
			
			xpos += size;
		}
		
	}

}