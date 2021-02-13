#include "Model.h"

Model::Model(GLuint shaderProgram_) : meshes(std::vector<Mesh*>()),shaderProgram(0)
{
	shaderProgram = shaderProgram_;
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
}

void Model::Render()
{
	glUseProgram(shaderProgram);
	for (auto mesh : meshes)
	{
		mesh->Render();
	}
}

void Model::AddMesh(Mesh* mesh_)
{
	meshes.push_back(mesh_);
}
