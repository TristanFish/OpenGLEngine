#include "GameObject.h"


GameObject::GameObject(Model* model_, glm::vec3 position_) : model(nullptr), position(glm::vec3()), rotation(glm::vec3(0.0f, 1.0f, 0.0f)), 
scale(glm::vec3(1.0f)), angle(0), modelInstance(0)
{
	model = model_;
	position = position_;

	if (model)
	{
		modelInstance = model->CreateInstance(position, angle, rotation, scale);
		boundingBox = model->GetBoundingBox();
		boundingBox.transform = model->GetTransform(modelInstance);


		std::cout << "Min: " << glm::to_string(boundingBox.minVert);
		std::cout << ", Max: " << glm::to_string(boundingBox.maxVert) << std::endl;
	}
}

GameObject::~GameObject()
{
	model = nullptr;
}

void GameObject::Update(const float deltaTime_)
{
	SetAngle(angle + 0.005);

}

void GameObject::Render(Camera* camera_)
{
	if (model) {
		model->Render(camera_);
	}
}


glm::vec3 GameObject::GetPosition() const
{
	return position;
}

float GameObject::GetAngle() const
{
	return angle;
}

glm::vec3 GameObject::GetRotation() const
{
	return rotation;
}

glm::vec3 GameObject::GetScale() const
{
	return scale;
}

std::string GameObject::GetName() const
{
	return name;
}

void GameObject::SetPosition(glm::vec3 positiom_)
{
	position = positiom_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingBox.transform = model->GetTransform(modelInstance);
	}


}

void GameObject::SetAngle(float angle_)
{
	angle = angle_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingBox.transform = model->GetTransform(modelInstance);
	}

}

void GameObject::SetRotation(glm::vec3 rotation_)
{
	rotation = rotation_;
	UpdateModelInstance();

}

void GameObject::SetScale(glm::vec3 scale_)
{
	scale = scale_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingBox.transform = model->GetTransform(modelInstance);
		boundingBox.minVert *= scale.x * 1.0f ? scale : (scale / 2.0f);
		boundingBox.maxVert *= scale.x * 1.0f ? scale : (scale / 2.0f);

	}
}

void GameObject::SetName(std::string name_)
{
	name = name_;
}

BoundingBox GameObject::GetBoundingBox() const
{
	return boundingBox;
}

void GameObject::UpdateModelInstance() const
{
	if (model)
	{
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
	}
}
