#include "GameObject.h"

GameObject::GameObject(Model* model_) : model(nullptr), position(glm::vec3()), rotation(glm::vec3(0.0f, 1.0f, 0.0f)), 
scale(glm::vec3(1.0f)), angle(0), modelInstance(0)
{
	model = model_;

	if (model)
	{
		modelInstance = model->CreateInstance(position, angle, rotation, scale);
	}
}

GameObject::GameObject(Model* model_, glm::vec3 position_) : model(nullptr), position(glm::vec3()), rotation(glm::vec3(0.0f, 1.0f, 0.0f)), 
scale(glm::vec3(1.0f)), angle(0), modelInstance(0)
{
	model = model_;
	position = position_;

	if (model)
	{
		modelInstance = model->CreateInstance(position, angle, rotation, scale);
	}
}

GameObject::~GameObject()
{
	if (model) {
		delete model;
	}
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

void GameObject::SetPosition(glm::vec3 positiom_)
{
	position = positiom_;
	UpdateModelInstance();

}

void GameObject::SetAngle(float angle_)
{
	angle = angle_;
	UpdateModelInstance();

}

void GameObject::SetRotation(glm::vec3 rotation_)
{
	rotation = rotation_;
	UpdateModelInstance();

}

void GameObject::SetScale(glm::vec3 scale_)
{
	scale = scale_;
	UpdateModelInstance();
}

void GameObject::UpdateModelInstance() const
{
	if (model)
	{
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
	}
}
