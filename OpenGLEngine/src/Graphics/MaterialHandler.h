#ifndef MATERIALHANDLER_H
#define MATERIALHANDLER_H

#include <glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <memory>


//!Material Struct
/*!Hold's all the info a material needs*/
struct Material
{
	inline Material() : diffuseMap(0), shininess(32.0f), transparency(1.0f), ambient(glm::vec3(1.0f)),
		diffuse(glm::vec3(1.0f)), specular(glm::vec3(1.0f)), name("")
	{

	}

	GLuint diffuseMap;

	float shininess;
	float transparency;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	std::string name;
};

//!MaterialHandler Class
/*!Handle's all the materials in the engine*/
class MaterialHandler
{

public:
	// Makes sure this class can not be copied or another instance can not be created
	MaterialHandler(const MaterialHandler&) = delete;
	MaterialHandler(MaterialHandler&&) = delete;
	MaterialHandler& operator=(const MaterialHandler&) = delete;
	MaterialHandler& operator=(MaterialHandler&&) = delete;

	//!GetInstance Getter
	/*!Return's the instance of this class if one exists. If one doesn't then it creates it*/
	static MaterialHandler* GetInstance();

	//!AddMaterial Function
	/*!Add's a new material to the vector of materials*/
	void AddMaterial(Material& mat_);

	//!GetMaterial Getterc
	/*!Return's the material with the current name*/
	const Material GetMaterial(const std::string& matName_) const;

	//!OnDestroy Function
	/*!Clear's the materials vector*/
	void OnDestroy();

private:

	//!MaterialHandler Constructor
	/*!Initalizes any of the classes variables*/
	MaterialHandler();

	//!MaterialHandler Destructor
	/*!Call's the classes OnDestroy Function*/
	~MaterialHandler();

	//!MaterialHandler unique pointer
	 /*!Holds a pointer to this class*/
	static std::unique_ptr<MaterialHandler> materialInstance;

	//!MaterialHandler default delete
	/*!Allows us to call the destructor when the instance of this class goes out of scope*/
	friend std::default_delete<MaterialHandler>;

	//!Materials vector
	/*!Hold's a vector of materials that are currently in use by the engine*/
	static std::vector<Material> materials;

};
#endif
