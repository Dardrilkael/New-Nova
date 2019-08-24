#include "novapch.h"
#include "OpenGLShader.h"

#include "glad/glad.h"
#include <sstream>
#include <string>
#include <fstream>
#include "Nova/Log.h"
#include <array>

namespace Nova
{

	enum ShaderType
	{
		None = -1, VertexShader, FragmentShader
	};

	enum ShaderAction
	{
		Nough = -1, DefineStruct, InstantiateStruct
	};

	ShaderData OpenGLShader::Load(const char * path)
	{
		ShaderType type = ShaderType::None;
		std::string line;
		std::stringstream ss[2];
		std::ifstream file(path);
		//--------------------Debug--------------------//
		std::stringstream DebugSS[2];
		std::array<int, 2> nb_line = {-1,-1};

		bool struct_on = false;
		std::string SelectStruct;
		ShaderAction action = Nough;
		//-------------------Debug_End-------------------//

		while (getline(file, line))
		{
			if (line.find("#Vertex") != std::string::npos)
				type = ShaderType::VertexShader;
			else if (line.find("#Fragment") != std::string::npos)
				type = ShaderType::FragmentShader;
			else
			{
				nb_line[type] += 1;
				if (nb_line[type] < 1000)DebugSS[type] << " ";
				if (nb_line[type] < 10)DebugSS[type] << "0";
				DebugSS[type] << nb_line[type] << "|  " << "" << line << '\n';
				ss[type] << line << '\n';
			}


			if (line.find("struct") != std::string::npos)
			{
				action = DefineStruct;
				int position = line.find(" ");
				std::string name = line.substr(position + 1);
				itemStruct[name];
				SelectStruct = name;
			}
			else if (action == DefineStruct)
			{
				int position = line.find(" ");
				std::string name = line.substr(position + 1);
				name.pop_back();
				itemStruct[SelectStruct].emplace_back(name);

				if (line.find("}") != std::string::npos)action = Nough;
			}

			else if (line.find("uniform") != std::string::npos)
			{
				int position = line.find(" ", 8);
				std::string name = line.substr(position + 1);
				name.pop_back();
				bool ok = false;
				for (auto& i : itemStruct)
				{
					if (line.find(i.first))
					{
						for (auto& k : i.second)
						{
							if (k != "")
							{
								std::string other = name + "." + k;
								uniforms.emplace(other);
							}
						}
						ok = true;
					}

				}
				if (!ok)
				{
					uniforms.emplace(name);
				}
				//GetUniformLocation(name.c_str());

			}

		
		}
	#ifndef NOVA_DIST
		return { ss[0].str(),ss[1].str(),DebugSS[0].str(),DebugSS[1].str() };
	#else
		return { ss[0].str(),ss[1].str() };
		#endif

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
		NOVA_CORE_LOG_SPECIAL("____________________________________________________________________________________________________")
		NOVA_CORE_LOG_INFO("\n\n ---------- ___Vertex Shader___ ---------- \n");
		NOVA_CORE_LOG_DEBUG(ShaderSource.Debugvs + '\n');

		NOVA_CORE_LOG_INFO("\n\n ---------- ___Fragment Shader___ ---------- \n");
		NOVA_CORE_LOG_DEBUG(ShaderSource.Debugfs + '\n');
		NOVA_CORE_LOG_SPECIAL("____________________________________________________________________________________________________")
		NOVA_CORE_LOG_SPECIAL("\n\n\n");
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
			NOVA_CORE_LOG_CRITICAL(("\n\nERROR::SHADER::VERTEX::COMPILATION_FAILED\n \n{0}", infoLog[0])
);
		}

		glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fs, 512, NULL, infoLog[1]);
			NOVA_CORE_LOG_CRITICAL(("\n\nERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n \n{0}",infoLog[1]));
		}
		
		

		glAttachShader(m_RendererID, vs);
		glAttachShader(m_RendererID, fs);

		glLinkProgram(m_RendererID);
		glValidateProgram(m_RendererID);

		glDeleteShader(vs);
		glDeleteShader(fs);

		for(auto& name: Uniforms)
		{
		int32_t loc = glGetUniformLocation(m_RendererID, name.c_str());
		if (loc != -1)

			m_Locations[name] = loc;

		}
	}


	int OpenGLShader::GetUniformLocation(const char* name)const
	{
		if (m_Locations.find(name) != m_Locations.end())
		{
			if(m_Locations[name]!=-1)
			return m_Locations[name];
		}
		return -1;
		//uint32_t loc = glGetUniformLocation(m_RendererID, name);
		//m_Locations[name] = loc;
		//return loc;
	}
	
	void OpenGLShader::SetInt(const char* name, int value)const {
		Count(name);
		glUniform1d(GetUniformLocation(name),value); }


	void OpenGLShader::SetVec3(const char* name, float a, float b, float c)const { Count(name);
	glUniform3f(GetUniformLocation(name), a, b, c); }
	void OpenGLShader::SetVec3(const char* name, float* value)const { Count(name);
	glUniform3fv(GetUniformLocation(name), 1, value); }
	
	void OpenGLShader::SetVec4(const char* name, float a, float b, float c, float d)const { Count(name); 
	glUniform4f(GetUniformLocation(name), a, b, c,d); }
	void OpenGLShader::SetVec4(const char* name, float* value)const { Count(name); 
	glUniform4fv(GetUniformLocation(name), 1,value); }

	void OpenGLShader::SetMat4(const char* name, float* value)const
	{
		Count(name);
		glUniformMatrix4fv(GetUniformLocation(name), 1, false, value);
	}

}