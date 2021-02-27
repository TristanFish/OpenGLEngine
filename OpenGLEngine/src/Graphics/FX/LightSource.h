#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <glm/glm.hpp>

//!LightSource Class
/*!Hold's all of the needed variables and functions to enable lighting in the engine*/
class LightSource
{
public:

	//!LightSource Constructor
	/*!Initializes all of the classes variables*/
	LightSource(glm::vec3 position_, glm::vec3 colour_, float ambient_, float diffuse_, float specular_);

	//!LightSource Destructor
	/*!Empty function*/
	~LightSource();

	//!GetPosition Getter
	/*!Returns the position variable*/
	 glm::vec3 GetPosition() const;


	 //!GetColour Getter
	/*!Returns the colour variable*/
	 glm::vec3 GetColour() const;

	 //!GetAmbient Getter
	/*!Returns the ambient variable*/
	 float GetAmbient() const;

	 //!GetDiffuse Getter
	/*!Returns the diffuse variable*/
	 float GetDiffuse() const;

	 //!GetSpecular Getter
   /*!Returns the specular variable*/
	 float GetSpecular() const;


private:

	//!Vec3 Colour
   /*!Hold's the colour of the light source*/
	glm::vec3 colour;

	//!Vec3 Position
	/*!Hold's the position of the light source*/
	glm::vec3 position;

	//!float Ambient,Diffuse,Specular
	/*!Used to simuate how the light will react with objects*/
	float ambient, diffuse, specular;


};

#endif

