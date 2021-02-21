#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

//! Model Class
/*!Handles how a Model will work in our engine*/
class Model
{
public:
	//! Model Constructor
	/*!Initializes class specific variables*/
	Model(GLuint shaderProgram_, glm::vec3 position_ = glm::vec3(), 
		float angle_ = 0.0f, glm::vec3 rotation_ = glm::vec3(0.0f,1.0f,0.0f), 
		glm::vec3 scale_ = glm::vec3(1.0f));

	//!Model Destructor
	/*!Loops through the meshes vector and deletes all the pointers*/
	~Model();

	//!Render Function
	/*!Loops through and Renders all of the meshes in the meshes vector*/
	void Render(Camera* camera_);

	//!AddMesh Function
	/*!Adds a mesh to the vector of meshes*/
	void AddMesh(Mesh* mesh_);

	//!GetPosition Getter
	/*!Returns this models location*/
	glm::vec3 GetPosition() const;

	//!GetAngle Getter
	/*!Returns this models angle*/
	float GetAngle() const;

	//!GetRotation Getter
	/*!Returns this models rotation*/
	glm::vec3 GetRotation() const;

	//!GetScale Getter
	/*!Returns this models scale*/
	glm::vec3 GetScale() const;

	//!SetPosition Setter
	/*!Sets this models position*/
	void SetPosition(glm::vec3 positiom_);

	//!SetAngle Setter
	/*!Sets this models angle*/
	void SetAngle(float angle_);

	//!SetRotation Setter
	/*!Sets this models rotation*/
	void SetRotation(glm::vec3 rotation_);

	//!SetScale Setter
	/*!Sets this models scale*/
	void SetScale(glm::vec3 scale_);


private:

	//! std::vector meshes
	/*!Holds all of the meshes that this model contains*/
	std::vector<Mesh*> meshes;

	//! Shader Program Unsigned Integer
	/*!Contains the shader that this model uses*/
	GLuint shaderProgram;

	//!Position vector3
	/*!Holds our models position*/
	glm::vec3 position;

	//!Angle float
	/*!Holds our models angle*/
	float angle;

	//!Rotation vector3
	/*!Holds our models rotation*/
	glm::vec3 rotation;

	//!Scale vector3
	/*!Holds our models scale*/
	glm::vec3 scale;

	//!GetTransform getter
	/*!Returns our models transform matrix*/
	glm::mat4 GetTransform() const;

};
#endif
