
#include "LightSource.h"

LightSource::LightSource(glm::vec3 position_, glm::vec3 colour_, float ambient_, float diffuse_, float specular_) : 
	position(glm::vec3()), colour(glm::vec3()), ambient(0), diffuse(0), specular(0)
{
	position = position_;
	colour = colour_;
	ambient = ambient_;
	diffuse = diffuse_;
	specular = specular_;
}


LightSource::~LightSource()
{

}

glm::vec3 LightSource::GetPosition() const
{
	return position;
}

glm::vec3 LightSource::GetColour() const
{
	return colour;
}

float LightSource::GetAmbient() const
{
	return ambient;
}

float LightSource::GetDiffuse() const
{
	return diffuse;
}

float LightSource::GetSpecular() const
{
	return specular;
}
