#version 400

layout(location = 0) out vec4 fragcolor;

in vec2 TexCoords;

uniform sampler2D diffuse;

void main()
{
	gl_FragColor = texture2D(diffuse, TexCoords); 
}