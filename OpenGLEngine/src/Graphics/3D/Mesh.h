#ifndef MESH_H
#define MESH_H


#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Core/Camera.h"
class CoreEngine;

//!Vertex Struct
/*!Hold's all the information that a vertex needs */
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textureCoordinates;
	glm::vec3 colour;

};


//!SubMesh Struct
/*!Hold's a meshes basic information*/
struct SubMesh {
	std::vector<Vertex> vertexList;
	std::vector<unsigned int> meshIndices;
	GLuint textureID;

};


//! Mesh Class
/*!Handles the functionality of Meshes in our engine*/
class Mesh
{

public:
	//! Mesh Constructor
	/*!Initializes the class specific variables*/
	Mesh(SubMesh& subMesh_, GLuint shaderProgram_);

	//! Mesh Destructor
	/*!Deletes buffers and clears the vertexList*/
	~Mesh();

	//!Render Function
	/*!Binds the vertex buffer and draws the vertices's*/
	void Render(Camera* camera_,std::vector<glm::mat4>& instances_);

private:


	//!GenerateBuffers Function
	/*!Generates the buffers that are needed to render the vertices's*/
	void GenerateBuffers();

	//!GLuint Vertex Array Object & Vertex Buffer Object
	/*!Holds the buffers needed to render the vertices on screen*/
	GLuint VAO, VBO;

	//!Submesh 
	/*!Stores stores this meshes main vertex information*/
	SubMesh subMesh;

	//!GLuint Shader Program
	/*!Stores the shader program that this mesh is using*/
	GLuint shaderProgram;


	//!GLuint Model, Vie, Projection Locations
	/*!Stores the locations of our different matricies needed to render this mesh*/
	GLuint modelLoc, viewLoc, projectionLoc, textureLoc;
	

	//!GLuint Position, LightPosition, LightAmbient, LightSpecular, LightDiffuse and LightColour locations
	/*!Stores all of the needed locations that allows us to incorporate lighting*/
	GLuint posLoc, lightPosLoc, lightAmbLoc, lightSpecLoc, lightDiffLoc, lightColLoc, lightsInGameLoc;
};

#endif

