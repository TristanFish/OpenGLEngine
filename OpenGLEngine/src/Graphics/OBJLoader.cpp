#include "OBJLoader.h"

OBJLoader::OBJLoader() : vertices(std::vector<glm::vec3>()), normals(std::vector<glm::vec3>()), textureCoords(std::vector<glm::vec2>()),
indices(std::vector<unsigned int>()), normalIndices(std::vector<unsigned int>()), textureIndices(std::vector<unsigned int>()),
meshVerticies(std::vector<Vertex>()), subMeshes(std::vector<SubMesh>()), currentMaterial(Material())
{
	vertices.reserve(200);
	normals.reserve(200);
	textureCoords.reserve(200);
	indices.reserve(200);
	normalIndices.reserve(200);
	textureIndices.reserve(200);
	meshVerticies.reserve(200);
	subMeshes.reserve(10);


}

OBJLoader::~OBJLoader()
{
	vertices.clear();
	normals.clear();
	textureCoords.clear();
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVerticies.clear();
	subMeshes.clear();

}

void OBJLoader::PostProcessing()
{
	for (unsigned int i = 0; i < indices.size(); i++)
	{
		Vertex vert;

		vert.position = vertices[indices[i]];
		vert.normal = normals[normalIndices[i]];
		vert.textureCoordinates = textureCoords[textureIndices[i]];


		meshVerticies.push_back(vert);
	}
	SubMesh mesh;
	mesh.vertexList = meshVerticies;
	mesh.meshIndices = indices;
	mesh.material = currentMaterial;

	subMeshes.push_back(mesh);

	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVerticies.clear();

	currentMaterial = Material();
}

void OBJLoader::LoadModel(const std::string& objFilePath_, const std::string& mtlFilePath_)
{
	LoadMaterialLibrary(mtlFilePath_);
	LoadModel(objFilePath_);
}

void OBJLoader::LoadModel(const std::string& filePath_)
{
	std::ifstream in(filePath_.c_str(), std::ios::in);
	if (!in) {
		Debug::Error("Cannot open OBJ file" + filePath_, "OBJLoader.cpp", __LINE__);
		return;
	}

	std::string line;

	while (std::getline(in, line)) {

		if (line.substr(0, 2) == "v ") {
			std::stringstream v(line.substr(2));
			float x, y, z;
			v >> x >> y >> z;

			boundingBox.minVert = glm::vec3(
				std::min(boundingBox.minVert.x, x), 
				std::min(boundingBox.minVert.y, y), 
				std::min(boundingBox.minVert.z, z));

			boundingBox.maxVert = glm::vec3(
				std::max(boundingBox.maxVert.x, x),
				std::max(boundingBox.maxVert.y, y),
				std::max(boundingBox.maxVert.z, z));

			vertices.push_back(glm::vec3(x, y, z));
		}
		else if (line.substr(0, 2) == "vn") {
			std::stringstream v(line.substr(2));
			float x, y, z;
			v >> x >> y >> z;

			normals.push_back(glm::vec3(x, y, z));
		}
		else if (line.substr(0, 2) == "vt") {
			std::stringstream v(line.substr(2));
			float x, y;
			v >> x >> y;
			textureCoords.push_back(glm::vec2(x, y));
		}

		else if (line.substr(0, 2) == "f ") {

			std::stringstream f_1(line.substr(2));
			char slash;			

			std::vector<unsigned int> pos = std::vector<unsigned int>(3);
			std::vector<unsigned int> texCoord = std::vector<unsigned int>(3);
			std::vector<unsigned int> norm = std::vector<unsigned int>(3);


			f_1 >> pos[0] >> slash >> texCoord[0] >> slash >> norm[0] >>
				   pos[1] >> slash >> texCoord[1] >> slash >> norm[1] >>
				   pos[2] >> slash >> texCoord[2] >> slash >> norm[2];
				  
			for (int i = 0; i < pos.size(); i++)
			{
				indices.push_back(pos[i] - 1);
				textureIndices.push_back(texCoord[i] - 1);
				normalIndices.push_back(norm[i] - 1);
			}
		}


		else if (line.substr(0, 7) == "usemtl ")
		{
			if (indices.size() > 0) {
				PostProcessing();
			}
			LoadMaterial(line.substr(7));
		}
	}


	PostProcessing();
}

void OBJLoader::LoadMaterial(const std::string& matName_)
{
	currentMaterial = MaterialHandler::GetInstance()->GetMaterial(matName_);
	
}

void OBJLoader::LoadMaterialLibrary(const std::string& matFilePath_)
{
	MTLoader::LoadMaterial(matFilePath_);

}

std::vector<SubMesh> OBJLoader::GetSubMeshes()
{
	return subMeshes;
}

BoundingBox OBJLoader::GetBoundingBox() const
{
	return boundingBox;
}
