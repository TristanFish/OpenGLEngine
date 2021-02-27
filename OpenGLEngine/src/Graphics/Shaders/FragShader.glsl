#version 450 core

in vec3 Normal;
in vec2 TexCoords;
in vec3 Colour;
in vec3 FragPosition;

struct Light
{
	vec3 position;
	vec3 colour;
	float ambient;
	float diffuse;
	float specular;
};

uniform sampler2D meshTexture;
uniform vec3 viewPosition;
uniform Light light[2];

out vec4 fColour;


vec3 GeneratePhong(Light light_)
{
	vec3 ambient = light_.ambient * texture(meshTexture,TexCoords).rgb * light_.colour;

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light_.position - FragPosition);
	float diff = max(dot(norm,lightDir),0.0);
	vec3 diffuse = (diff * light_.diffuse) * texture(meshTexture,TexCoords).rgb * light_.colour;

	vec3 viewDir = normalize(viewPosition - FragPosition);
	vec3 reflectDir = reflect(-lightDir,norm);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),32);
	vec3 specular = (spec * light_.specular) * light_.colour;

	vec3 result = ambient + diffuse + specular;

	return result;
}

void main()
{
	vec3 finalColor;
	for(int i = 0; i < 2; i++)
	{
		finalColor += GeneratePhong(light[i]);
	}

	fColour = vec4(finalColor ,1.0f);
}