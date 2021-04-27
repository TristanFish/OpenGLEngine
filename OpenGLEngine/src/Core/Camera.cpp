#include "Camera.h"
#include "Graphics/3D/GameObject.h"
#include "Core/CoreEngine.h"

Camera::Camera() : position(glm::vec3()), perspective(glm::mat4()), orthographic(glm::mat4()), view(glm::mat4()),
fieldOfView(0.0f),yaw(0.0f), pitch(0.0f),nearPlane(0.0f),farPlane(0.0f), forward(glm::vec3()), up(glm::vec3()),
right(glm::vec3()), worldUp(glm::vec3())
{
	fieldOfView = 45.0f;
	forward = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = up;
	nearPlane = 2.0f;
	farPlane = 50.0f;
	yaw = -90.0f;
	pitch = 0.0f;

	

	perspective = glm::perspective(fieldOfView, CoreEngine::GetInstance()->GetScreenWidth() / CoreEngine::GetInstance()->GetScreenHeight(), nearPlane, farPlane);

	orthographic = glm::ortho(0.0f, CoreEngine::GetInstance()->GetScreenWidth(), 0.0f, CoreEngine::GetInstance()->GetScreenHeight(), -1.0f, 1.0f);

	UpdateCameraVectors();
}

Camera::~Camera()
{
	if (lightSources.size() > 0)
	{
		for (auto l : lightSources)
		{
			delete l;
			l = nullptr;
		}
		lightSources.clear();
	}
}

void Camera::SetPosition(glm::vec3 position_)
{
	position = position_;
	UpdateCameraVectors();
}

void Camera::SetRotation(float yaw_, float pitch_)
{
	yaw = yaw_;
	pitch = pitch_;
	UpdateCameraVectors();
}

glm::mat4 Camera::GetView() const
{
	return view;
}

glm::mat4 Camera::GetPerspective() const
{
	return perspective;
}

glm::mat4 Camera::GetOrthographic() const
{
	return orthographic;
}

glm::vec3 Camera::GetPosition() const
{
	return position;
}

void Camera::AddLightSource( LightSource* lightSource_) 
{
	lightSources.push_back(lightSource_);
}

std::vector<LightSource*> Camera::GetLightSources() const
{
	return lightSources;
}

void Camera::ProcessMouseMovement(glm::vec2 offset_)
{
	offset_ *= 0.05f;

	yaw += offset_.x;
	pitch += offset_.y;
	
	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}
	//glm::clamp(pitch, -89.0f, 89.0f);

	if (yaw < 0.0f) {
		yaw += 360.0f;
	}
	if (yaw > 360.0f) {
		yaw -= 360.0f;
	}
	//glm::clamp(yaw, 0.0f, 360.0f);


	UpdateCameraVectors();
}

void Camera::ProcessMouseZoom(int y_)
{
	if (y_ < 0 || y_ > 0) {
		position += static_cast<float>(y_) * (forward * 2.0f);
	}
	UpdateCameraVectors();
}

float Camera::GetNearPlane() const
{
	return nearPlane;
}

float Camera::GetFarPlane() const
{
	return farPlane;
}

void Camera::UpdateCameraVectors()
{
	forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward.y = sin(glm::radians(pitch));
	forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forward = glm::normalize(forward);

	right = glm::normalize(glm::cross(forward, worldUp));

	up = glm::normalize(glm::cross(right, forward));

	view = glm::lookAt(position, position + forward, up);

	float tang = (float)tan(ANG2RAD * fieldOfView * 0.5f);


	CalulateFrustrum();
}

void Camera::ObjectInFrustum(const GameObject& object_)
{
	int Result = 0;

	for (int i = 0; i < 6; i++) {

		glm::vec3 objPos = object_.GetPosition();
		 if (planes[i].Distance(objPos) < 0.0) {
			std::cout << " Can't See An Object: " << object_.GetName() <<  std::endl;
		}
	}
}

void Camera::CalulateFrustrum()
{

	glm::mat4 PVM = perspective * view;

	planes[TOP].UpdatePlane(PVM[3].x - PVM[1].x, PVM[3].y - PVM[1].y, PVM[3].z - PVM[1].z, PVM[3].w - PVM[1].w);

	planes[BOTTOM].UpdatePlane(PVM[3].x + PVM[1].x, PVM[3].y + PVM[1].y, PVM[3].z + PVM[1].z, PVM[3].w + PVM[1].w);

	planes[LEFT].UpdatePlane(PVM[3].x + PVM[0].x, PVM[3].y + PVM[0].y, PVM[3].z + PVM[0].z, PVM[3].w + PVM[0].w);

	planes[RIGHT].UpdatePlane(PVM[3].x - PVM[0].x, PVM[3].y - PVM[0].y, PVM[3].z - PVM[0].z, PVM[3].w - PVM[0].w);

	planes[NEARP].UpdatePlane(PVM[3].x + PVM[2].x, PVM[3].y + PVM[2].y, PVM[3].z + PVM[2].z, PVM[3].w + PVM[2].w);

	planes[FARP].UpdatePlane(PVM[3].x - PVM[2].x, PVM[3].y - PVM[2].y, PVM[3].z - PVM[2].z, PVM[3].w - PVM[2].w);

}
