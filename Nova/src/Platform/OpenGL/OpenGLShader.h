#pragma once
#include "Nova/Renderer/Shader.h"

namespace Nova
{
	struct ShaderData { std::string vs; std::string fs; };
	class OpenGLShader : public Shader
	{
	public:

		friend static Shader* Shader::Create(const char* path);

		int GetUniformLocation(const char* name)const;

		virtual void SetInt(const char* name, int value) const override;

		virtual void SetVec3(const char* name, float a, float b, float c) const override;
		virtual void SetVec3(const char* name, float* value) const override;
		
		
		virtual void SetVec4(const char* name, float a, float b, float c, float d) const override;
		virtual void SetVec4(const char* name, float* value) const override;

		virtual void SetMat4(const char* name, float* value) const override;

	protected:
		OpenGLShader(const char* path);
	private:
		
		uint32_t m_RendererID;
		ShaderData Load(const char* path);
		// Herdado por meio de Shader
		virtual void Bind() const override;
		virtual void UnBind() const override;



		// Herdado por meio de Shader


	};

}