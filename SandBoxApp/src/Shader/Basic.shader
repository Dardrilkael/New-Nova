#Vertex
#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 2) in vec2 aTexCoords;

uniform vec2 kk;
uniform mat4 viewProj;
uniform mat4 model;
out vec4 vcolor;
out vec2 vTexCoords;
void main()
{
   gl_Position = viewProj*model*aPos;
   vTexCoords = aTexCoords;
};


#Fragment
#version 330 core

struct Material
{
	vec3 ambient;
	sampler2D especular;
	sampler2D diffuse;
};
in vec2 vTexCoords;

uniform Material material;
out vec4 FragColor;

//in vec4 vcolor;
void main()
{
	FragColor = texture(material.diffuse, vTexCoords);// + vcolor;
};
