#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <sstream>
#include <iostream>
#include "3D/Mesh.h"
#include "TextureHandler.h"
#include "FX/MTLoader.h"
#include "Math/BoundingBox.h"
//! OBJLoader Class
/*!Load's in obj files for use in our engine*/
class OBJLoader
{
public:

	//!OBJLoader Constructor
	/*!Initializes this classes variables*/
	OBJLoader();

	//!OBJLoader Destructor
	/*!Clear's all of this classes std::vectors*/
	~OBJLoader();

	//!LoadModel Function
	/*!Load's a model and material when given file paths*/
	void LoadModel(const std::string& objFilePath_, const std::string& mtlFilePath_);

	//!GetSubMeshes Getter
	/*!Return's the vector of submeshes*/
	std::vector<SubMesh> GetSubMeshes();

	BoundingBox GetBoundingBox() const;

private:

	//!PostProcessing Functions
	/*!Updates a meshes verticies and submeshes*/
	void PostProcessing();

	//!LoadModel Functions
	/*!Load's a model from a obj file*/
	void LoadModel(const std::string& filePath_);

	//!LoadMaterial Functions
	/*!Load's a material from a mtl file*/
	void LoadMaterial(const std::string& matName_);

	//!LoadMaterialLibrary Functions
	/*!Load's a material for the loaded mesh to uses*/
	void LoadMaterialLibrary(const std::string& matFilePath_);


	//!Vertices std::vector
	/*!Hold's a list of vertices's for our loaded in object*/
	std::vector<glm::vec3> vertices;

	//!Normals std::vector
	/*!Hold's a list of normal's for our loaded in object*/
	std::vector<glm::vec3> normals;

	//!TextureCoords std::vector
	/*!Hold's a list of texture coordinates for our loaded in object*/
	std::vector<glm::vec2> textureCoords;

	//!Indicies std::vector's
	/*!Hold's all of the needed indices for our obj to load in information*/
	std::vector<unsigned int> indices, normalIndices, textureIndices;

	//!MeshVerticies std::vector
	/*!Hold's all of the vertex data for each mesh*/
	std::vector<Vertex> meshVerticies;

	//!SubMeshes std::vector
	/*!Hold's all of the Sub Meshes for each mesh*/
	std::vector<SubMesh> subMeshes;

	//!currentMaterial Gluint
	/*!Hold's the current material being used by the loaded mesh*/
	Material currentMaterial;

	//!BoundingBox 
	/*!Hold's a bounding box object for our OBJLoader to use and pass on to loaded objects*/
	BoundingBox boundingBox;
};

#endif
