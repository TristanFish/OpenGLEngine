#include "Model.h"

Model::Model() : meshes(std::vector<Mesh*>())
{

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
	for (auto mesh : meshes)
	{
		mesh->Render();
	}
}

void Model::AddMesh(Mesh* mesh_)
{
	meshes.push_back(mesh_);
}
