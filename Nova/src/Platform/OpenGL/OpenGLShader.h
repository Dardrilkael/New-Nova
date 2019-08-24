#pragma once
#include "Nova/Renderer/Shader.h"
#include <unordered_map>
#include "Nova/Log.h"
#include <set>
namespace Nova
{
#ifndef NOVA_DIST
	struct ShaderData {
		std::string vs; std::string fs;
		std::string Debugvs; std::string Debugfs;
	};

#define Structitems mutable std::unordered_map<std::string,std::vector<std::string>> structs;
#define itemStruct structs

#define Used_Uniforms_Impl mutable std::set<std::string> used_uniforms;
#define Count_Impl void Counting(std::string name)const{if(m_Locations.find(name)== m_Locations.end()){NOVA_CORE_LOG_WARN(name+" Does not exist is this Shader\n");}else{ used_uniforms.emplace(name);}}
#define Count(name) Counting(name);


#define Uniforms_Impl std::set<std::string> uniforms;
#define Uniforms uniforms
#define DebugShader void Debug()\
	{\
	for (auto i : m_Locations)\
	{\
		NOVA_CORE_LOG_WARN(("%s \n",i.first));\
		NOVA_CORE_LOG_WARN("\n");\
		if (used_uniforms.find(i.first) == used_uniforms.end())\
		{\
			NOVA_CORE_LOG_WARN((i.first));\
			NOVA_CORE_LOG_WARN(" is never being used\n");\
		}\
	}\
	}

#else
	struct ShaderData {
		std::string vs; std::string fs;


	};
#define CountUniform
#define AddCount()
#define	Count(name)
#define	DebugShader

#endif
	class OpenGLShader : public Shader
	{
	public:

		//friend static Shader* Shader::Create(const char* path);

		int GetUniformLocation(const char* name)const;

		virtual void SetInt(const char* name, int value) const override;

		virtual void SetVec3(const char* name, float a, float b, float c) const override;
		virtual void SetVec3(const char* name, float* value) const override;
		
		
		virtual void SetVec4(const char* name, float a, float b, float c, float d) const override;
		virtual void SetVec4(const char* name, float* value) const override;

		virtual void SetMat4(const char* name, float* value) const override;

		OpenGLShader(const char* path);
	protected:
	private:
		mutable std::unordered_map<std::string,int32_t> m_Locations;
		uint32_t m_RendererID;
		ShaderData Load(const char* path);
		// Herdado por meio de Shader
		virtual void Bind() const override;
		virtual void UnBind() const override;

	public:
		
		DebugShader;
		Used_Uniforms_Impl;
		Count_Impl;
		Structitems;
		Uniforms_Impl;



	};



}