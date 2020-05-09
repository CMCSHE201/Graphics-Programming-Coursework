uniform vec3 lightDir;
varying vec3 normal;

in vec3 Position;

uniform vec3 cameraPos;
uniform samplerCube skybox;


vec4 intensityCheck(float intensity)
{
	if (intensity > 0.95)
		return vec4(1.0,0.5,0.5,1.0);
	else if (intensity > 0.5)
		return vec4(0.6,0.3,0.3,1.0);
	else if (intensity > 0.25)
		return vec4(0.4,0.2,0.2,1.0);
	else
		return vec4(0.2,0.1,0.1,1.0);
}

void main()
{
	float intensity;
	intensity = dot(lightDir,normal);

	float ratio = 1.00 / 1.52;
    vec3 I = normalize(Position - cameraPos);
    vec3 R = refract(I, normalize(normal), ratio);

	if(gl_FragCoord.x < 500)
	{
		gl_FragColor = intensityCheck(intensity);
	}
	else
	{
		gl_FragColor = vec4(texture(skybox, R).rgb, 1);
	}	
}