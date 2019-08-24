#pragma once
#include "Nova/Core.h"
#include <string>



namespace Nova
{
	class NOVA_API Texture
	{
	public:
		enum class TextureType
		{
			NOVA_TEXTURE_2D
		};
		virtual void Bind(int slot = 0) = 0;
		virtual operator int() = 0;
		static Texture* Create(TextureType type, const std::string& path) ;
	};
}