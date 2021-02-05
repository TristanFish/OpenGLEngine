#ifndef MESH_H
#define MESH_H


#include <glew.h>
#include <vector>
#include <glm/glm.hpp>

//!Vertex Struct
/*!Hold's all the information that a vertex needs */
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textureCoordinates;
	glm::vec3 colour;

};


//! Mesh Class
/*!Handles the functionality of Meshes in our engine*/
class Mesh
{

public:
	//! Mesh Constructor
	/*!Initializes the class specific variables*/
	Mesh(std::vector<Vertex>& vertexList_);

	//! Mesh Destructor
	/*!Deletes buffers and clears the vertexList*/
	~Mesh();

	//!Render Function
	/*!Binds the vertex buffer and draws the vertices's*/
	void Render();

private:

	//!GenerateBuffers Function
	/*!Generates the buffers that are needed to render the vertices's*/
	void GenerateBuffers();

	//!GLuint Vertex Array Object & Vertex Buffer Object
	/*!Holds the buffers needed to render the vertices on screen*/
	GLuint VAO, VBO;

	//!Vector of vertices's
	/*!Stores all the vertices's in our Mesh*/
	std::vector<Vertex> vertexList;

};

#endif

