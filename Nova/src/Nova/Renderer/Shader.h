#pragma once 

namespace Nova
{
	class Shader
	{
	public:

		virtual void SetVec3(const char* name, float a, float b, float c) const = 0;
		virtual void SetVec3(const char* name, float* value) const = 0;
		virtual void SetVec4(const char* name, float a, float b, float c, float d) const = 0;
		virtual void SetVec4(const char* name, float* value) const = 0;

		virtual void SetMat4(const char* name, float* value) const = 0;

		virtual void Bind()const= 0;
		virtual void UnBind() const = 0;
		static Shader* Create(const char* path);
		
	private:

	};
}