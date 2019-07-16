#include "novapch.h"
#include "OpenGLTexture.h"
#include "stb_image.h"
#include "glad/glad.h"


int GetOpengGLTextureType(TextureType type)
{
	switch (type)
	{
	case TextureType::NOVA_TEXTURE_2D:
		return GL_TEXTURE_2D;

	default:
		break;
	}

}

namespace Nova
{


	OpenGLTexture::OpenGLTexture(TextureType type, const std::string& path) :
		m_Width(0), m_Height(0), m_nrChannels(0),m_Type(GetOpengGLTextureType(type))
	{
		glGenTextures(1, &m_RendererID);
		Bind(m_RendererID);
		glTexParameteri(m_Type, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(m_Type, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(m_Type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(m_Type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//stbi_set_flip_vertically_on_load(true);
		m_Data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_nrChannels, 4);
		if (m_Data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

	}
	void OpenGLTexture::Bind(int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}


	Texture* Texture::Create(TextureType type, const std::string& path)
	{
		return new OpenGLTexture(type, path);
	}
}