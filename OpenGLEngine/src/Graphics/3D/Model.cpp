#include "Model.h"



Model::Model(GLuint shaderProgram_, glm::vec3 position_ , float angle_ , glm::vec3 rotation_ , glm::vec3 scale_) : 
	meshes(std::vector<Mesh*>()), shaderProgram(0), position(glm::vec3()), rotation(glm::vec3(0.0f,1.0f,0.0f)), scale(glm::vec3(1.0f))
{
	
	shaderProgram = shaderProgram_;
	position = position_;
	angle = angle_;
	rotation = rotation_;
	scale = scale_;
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

void Model::Render(Camera* camera_)
{
	glUseProgram(shaderProgram);
	for (auto mesh : meshes)
	{
		mesh->Render(camera_,GetTransform());
	}
}

void Model::AddMesh(Mesh* mesh_)
{
	meshes.push_back(mesh_);
}

glm::vec3 Model::GetPosition() const
{
	return position;
}

float Model::GetAngle() const
{
	return angle;
}

glm::vec3 Model::GetRotation() const
{
	return rotation;
}

glm::vec3 Model::GetScale() const
{
	return scale;
}

void Model::SetPosition(glm::vec3 positiom_)
{
	position = positiom_;
}

void Model::SetAngle(float angle_)
{
	angle = angle_;
}

void Model::SetRotation(glm::vec3 rotation_)
{
	rotation = rotation_;
}

void Model::SetScale(glm::vec3 scale_)
{
	scale = scale_;
}

glm::mat4 Model::GetTransform() const
{
	glm::mat4 model;

	model = glm::translate(model, position);
	model = glm::rotate(model,angle ,rotation);
	model = glm::scale(model, scale);
	return model;

}
