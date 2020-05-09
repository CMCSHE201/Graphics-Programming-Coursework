#version 400

layout (location = 0) in vec3 VertexPosition;
layout (location = 2) in vec3 VertexNormal;

uniform mat4 transform;

varying vec3 normal;

out vec3 Position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	if(VertexPosition.x < 500)
	{
		normal = VertexNormal;
		gl_Position = transform * vec4(VertexPosition, 1.0);
	}
	else
	{
		normal = mat3(transpose(inverse(model))) * VertexNormal;
		Position = vec3(model * vec4(VertexPosition, 1.0));
		gl_Position = projection * view * model * vec4(VertexPosition, 1.0);	
	}
}