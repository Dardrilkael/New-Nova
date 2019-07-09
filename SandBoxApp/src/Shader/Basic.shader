#Vertex
//#version 430 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;

uniform mat4 viewProj;
uniform mat4 model;
out vec4 vcolor;
void main()
{
   gl_Position = viewProj*model*aPos;
   vcolor = aColor;
};


#Fragment
//#version 430 core
uniform vec4 color;
out vec4 FragColor;
in vec4 vcolor;
void main()
{
	FragColor =  (vcolor+color)/2;
};
