#ifndef MODEL_H
#define MODEL_H

#include "Graphics/OBJLoader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <string>

//! Model Class
/*!Handles how a Model will work in our engine*/
class Model
{
public:
	//! Model Constructor
	/*!Initializes class specific variables*/
	Model(const std::string& objPath_, const std::string& matPath, GLuint shaderProgram_);

	//!Model Destructor
	/*!Loops through the meshes vector and deletes all the pointers*/
	~Model();

	//!Render Function
	/*!Loops through and Renders all of the meshes in the meshes vector*/
	void Render(Camera* camera_);

	//!AddMesh Function
	/*!Adds a mesh to the vector of meshes*/
	void AddMesh(Mesh* mesh_);

	//!CreateInstance Function
	/*!Creates a instance of this model and add's it to the modelinstances*/
	unsigned int CreateInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);

	//!UpdateInstance Function
	/*!Updates a instance of this model with a given index*/
	void UpdateInstance(unsigned int index, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);

	//!GetTransform getter
	/*!Returns our models transform matrix*/
	glm::mat4 GetTransform(unsigned int index_) const;


	//!GetShaderProgram Getter
	/*!Returns the shader program the model is using*/
	GLuint GetShaderProgram() const;

	BoundingBox GetBoundingBox() const;

private:

	//!CreateTransform Function
	/*!Create's a transform when given the parameters*/
	glm::mat4 CreateTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) const;

	//!LoadModel Function
	/*!Updates the meshes vector with the object loaders sub mesh*/
	void LoadModel();

	//! std::vector meshes
	/*!Holds all of the meshes that this model contains*/
	std::vector<Mesh*> meshes;

	//!ModelInstances vector
	/*!Stores all the instances of this model*/
	std::vector<glm::mat4> modelInstances;

	//! Shader Program Unsigned Integer
	/*!Contains the shader that this model uses*/
	GLuint shaderProgram;

	//!OBJLoader pointer
	/*!Allows us to load in models from obj files*/
	OBJLoader* objLoader;


	//!BoundingBox 
	/*!Hold's a bounding box object for our model*/
	BoundingBox boundingBox;
};
#endif
