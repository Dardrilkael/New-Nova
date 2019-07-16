#Vertex
//#version 430 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoords;

uniform mat4 proj;
out vec2 texCoords;
void main()
{
	gl_Position = proj*vec4(aPos,1.0f,1.0F);
	texCoords = aTexCoords;
};


#Fragment
//#version 430 core
out vec4 FragColor;
uniform sampler2D texture1;
in vec2 texCoords;
void main()
{
	FragColor = texture(texture1, texCoords);// +color + vcolor;
};
