#include "Nova/Core.h"
#include "Nova/Renderer/Texture.h"
#include <glm/glm.hpp>
#include <vector>
#include "Nova/Renderer/Shader.h"

namespace Nova
{
	enum MaterialName
	{
		STONE,IRON,WOOD
	};

	class Material
	{
	public:
		Vec3 m_Ambient;
		Texture* m_Diffuse;
		Texture* m_Especular;
		Shader* m_Shader;

		Material(glm::vec3 ambient, Texture* diffuse, Texture* especular,Shader* shader):
			m_Ambient(ambient), m_Diffuse(diffuse), m_Especular(especular),m_Shader(shader){}

		void UpdateShader()
		{
			m_Diffuse->Bind(0);
			m_Especular->Bind(1);
			m_Shader->SetVec3("material.ambient", &m_Ambient[0]);
			m_Shader->SetInt("material.especular", 0);
			m_Shader->SetInt("material.diffuse", 1);
		}
	};

	class NOVA_API MaterialStack
	{
	public:
		void AddMaterial(MaterialName index,Material& material)
		{
			s_Materials.push_back(material);
			s_MaterialIndex++;
		};
	private:
		
		static std::vector<Material> s_Materials;
		static uint32_t s_MaterialIndex;

	};

}