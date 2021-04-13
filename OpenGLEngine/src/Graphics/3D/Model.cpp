#include "Model.h"



Model::Model(const std::string& objPath_, const std::string& matPath_, GLuint shaderProgram_) :
	meshes(std::vector<Mesh*>()), modelInstances(std::vector<glm::mat4>()),shaderProgram(0), objLoader(nullptr)
{
	
	shaderProgram = shaderProgram_;
	meshes.reserve(10);
	modelInstances.reserve(5);
	objLoader = new OBJLoader();

	objLoader->LoadModel(objPath_, matPath_);
	LoadModel();
}

Model::~Model()
{
	if (meshes.size() > 0) {
		for (auto mesh : meshes)
		{
			delete mesh;
			mesh = nullptr;
		}
		meshes.clear();
	}

	if (modelInstances.size() > 0) {
		modelInstances.clear();
	}
}

void Model::Render(Camera* camera_)
{
	glUseProgram(shaderProgram);
	for (auto mesh : meshes)
	{
		mesh->Render(camera_,modelInstances);
	}
}

void Model::AddMesh(Mesh* mesh_)
{
	meshes.push_back(mesh_);
}



unsigned int Model::CreateInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_)
{
	modelInstances.push_back(CreateTransform(position_, angle_, rotation_, scale_));
	return modelInstances.size() - 1;
}

void Model::UpdateInstance(unsigned int index_, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_)
{
	modelInstances[index_] = CreateTransform(position_, angle_, rotation_, scale_);
}

glm::mat4 Model::GetTransform(unsigned int index_) const
{
	return modelInstances[index_];

	

}

GLuint Model::GetShaderProgram() const
{
	return shaderProgram;
}

BoundingBox Model::GetBoundingBox() const
{
	return boundingBox;
}

glm::mat4 Model::CreateTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) const
{
	glm::mat4 model;

	model = glm::translate(model, position_);
	model = glm::rotate(model, angle_,rotation_);
	model = glm::scale(model, scale_);

	return model;

}

void Model::LoadModel()
{
	for (int i = 0; i < objLoader->GetSubMeshes().size(); i++)
	{
		meshes.push_back(new Mesh(objLoader->GetSubMeshes()[i], shaderProgram));
	}

	boundingBox = objLoader->GetBoundingBox();
	delete objLoader;
	objLoader = nullptr;
}
