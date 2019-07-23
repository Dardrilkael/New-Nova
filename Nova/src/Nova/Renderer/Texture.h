#pragma once
#include "Nova/Core.h"
#include <string>

enum class TextureType
{
	NOVA_TEXTURE_2D
};

namespace Nova
{
	class NOVA_API Texture
	{
	public:
		virtual void Bind(int slot = 0) = 0;
		virtual operator unsigned int() = 0;
		static Texture* Create(TextureType type, const std::string& path) ;
	};
}