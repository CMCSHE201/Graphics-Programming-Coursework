#version 400

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexTexCoords;
layout (location = 2) in vec3 VertexNormal;

out VS_OUT {
	vec2 texCoords;
} vs_out;

uniform mat4 transform;

varying vec3 normal;

out vec3 v_norm;
out vec4 v_pos; 

void main()
{
	v_norm = VertexNormal;
	v_pos = vec4(VertexPosition, 1.0);

	normal = VertexNormal;

	vs_out.texCoords = VertexTexCoords;

	gl_Position = transform * vec4(VertexPosition, 1.0);
}