#pragma once
#include "Core.h"

#include "Renderer/Texture.h"

namespace Nova
{ 
	class OpenGLTexture: public Texture
	{
	public:
		OpenGLTexture(TextureType type, const std::string& path);
		void Bind(int slot =0);


		operator unsigned int() { return m_RendererID; }
	private:
		uint32_t m_RendererID;
		int32_t m_Width, m_Height, m_nrChannels;
		uint8_t* m_Data;
		int32_t m_Type;
	};
}