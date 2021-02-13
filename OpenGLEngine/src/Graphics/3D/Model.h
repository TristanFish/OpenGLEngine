#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"

//! Model Class
/*!Handles how a Model will work in our engine*/
class Model
{
public:
	//! Model Constructor
	/*!Initializes class specific variables*/
	Model(GLuint shaderProgram_);

	//! Model Destructor
	/*!Loops through the meshes vector and deletes all the pointers*/
	~Model();

	//! Render Function
	/*!Loops through and Renders all of the meshes in the meshes vector*/
	void Render();

	//! AddMesh Function
	/*!Adds a mesh to the vector of meshes*/
	void AddMesh(Mesh* mesh_);

private:

	//! std::vector meshes
	/*!Holds all of the meshes that this model contains*/
	std::vector<Mesh*> meshes;

	GLuint shaderProgram;
};
#endif
