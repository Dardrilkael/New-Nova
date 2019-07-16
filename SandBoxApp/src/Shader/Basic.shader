#Vertex
//#version 430 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoords;

uniform mat4 viewProj;
uniform mat4 model;
out vec4 vcolor;
out vec2 texCoords;
void main()
{
   gl_Position = viewProj*model*aPos;
   vcolor = aColor;
   texCoords = aTexCoords;
};


#Fragment
//#version 430 core
uniform vec4 color;
out vec4 FragColor;
in vec4 vcolor;
uniform sampler2D texture1;
in vec2 texCoords;
void main()
{
	FragColor = texture(texture1, texCoords);// +color + vcolor;
};
