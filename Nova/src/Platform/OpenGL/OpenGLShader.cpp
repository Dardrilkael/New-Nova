#include "novapch.h"
#include "OpenGLShader.h"

#include "glad/glad.h"
#include <sstream>
#include <string>
#include <fstream>
#include "Log.h"

namespace Nova
{

	enum ShaderType
	{
		None = -1, VertexShader, FragmentShader
	};


	ShaderData OpenGLShader::Load(const char * path)
	{
		ShaderType type = ShaderType::None;
		std::string line;
		std::stringstream ss[2];
		std::ifstream file;
		file.open(path);

		while (getline(file, line))
		{
			if (line.find("#Vertex") != std::string::npos)
				type = ShaderType::VertexShader;
			else if (line.find("#Fragment") != std::string::npos)
				type = ShaderType::FragmentShader;
			else
				ss[type] << line << "\n";

		}
		std::cout << line;
		return { ss[0].str(),ss[1].str() };
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::UnBind() const
	{
		glUseProgram(0);
	}


	OpenGLShader::OpenGLShader(const char * path)
	{
		ShaderData ShaderSource = Load(path);

		const char* vssrc = ShaderSource.vs.c_str();
		const char* fssrc = ShaderSource.fs.c_str();
		NOVA_CORE_LOG_DEBUG("\n\n ---------- ___Vertex Shader___ ---------- ");
		NOVA_CORE_LOG_DEBUG(vssrc);
		
		NOVA_CORE_LOG_DEBUG("\n\n ---------- ___Fragment Shader___ ---------- ");
		NOVA_CORE_LOG_DEBUG(fssrc);

		uint32_t vs, fs;

		m_RendererID = glCreateProgram();

		vs = glCreateShader(GL_VERTEX_SHADER);
		fs = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vs, 1, &vssrc, NULL);
		glShaderSource(fs, 1, &fssrc, NULL);

		glCompileShader(vs);
		glCompileShader(fs);

		char infoLog[2][512];
		int success;

		glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vs, 512, NULL, infoLog[0]);
			NOVA_CORE_LOG_CRITICAL("\n\nERROR::SHADER::VERTEX::COMPILATION_FAILED\n \n{0}", infoLog[0]);
		}

		glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fs, 512, NULL, infoLog[1]);
			NOVA_CORE_LOG_CRITICAL("\n\nERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n \n{0}",infoLog[1]);
		}
		
		

		glAttachShader(m_RendererID, vs);
		glAttachShader(m_RendererID, fs);

		glLinkProgram(m_RendererID);
		glValidateProgram(m_RendererID);

		glDeleteShader(vs);
		glDeleteShader(fs);


	}

	Shader * Shader::Create(const char* path)
	{
		return new OpenGLShader(path);



	}



	int OpenGLShader::GetUniformLocation(const char* name)const { return glGetUniformLocation(m_RendererID, name); }
	
	void OpenGLShader::SetInt(const char* name, int value)const { glUniform1d(GetUniformLocation(name),value); }


	void OpenGLShader::SetVec3(const char* name, float a, float b, float c)const { glUniform3f(GetUniformLocation(name), a, b, c); }
	void OpenGLShader::SetVec3(const char* name, float* value)const { glUniform3fv(GetUniformLocation(name), 1, value); }
	
	void OpenGLShader::SetVec4(const char* name, float a, float b, float c, float d)const { glUniform4f(GetUniformLocation(name), a, b, c,d); }
	void OpenGLShader::SetVec4(const char* name, float* value)const { glUniform4fv(GetUniformLocation(name), 1,value); }

	void OpenGLShader::SetMat4(const char* name, float* value)const
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, false, value);
	}

}