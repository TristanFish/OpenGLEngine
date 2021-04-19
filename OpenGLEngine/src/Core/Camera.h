#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Graphics/FX/LightSource.h"
#include "Math/Plane.h"
#include <vector>

#define ANG2RAD 3.14159265358979323846/180.0

class GameObject;
//!Camera Class
/*!Control's how our camera works in our engine*/
class Camera
{
public:

	//!Camera Constructor
	/*!Initializes all of the classes variables*/
	Camera();

	//!Camera Destructor
	/*!Empty*/
	~Camera();

	//!SetPosition Setter
	/*!Sets the camera's position*/
	void SetPosition(glm::vec3 position_);

	//!SetRotation Setter
	/*!Sets the camera's rotation*/
	void SetRotation(float yaw_, float pitch_);

	//!GetView Getter
	/*!Returns the camera's view matrix*/
	glm::mat4 GetView() const;

	//!GetPerspective Getter
	/*!Returns the camera's perspective matrix*/
	glm::mat4 GetPerspective() const;

	//!GetOrthographic Getter
	/*!Returns the camera's orthographic matrix*/
	glm::mat4 GetOrthographic() const;

	//!GetPosition Getter
	/*!Returns the camera's position vector*/
	glm::vec3 GetPosition() const;

	//!AddLightSource Function 
	/*!Add's a new light source to the vector of light sources*/
	void AddLightSource(LightSource* lightSource_);

	//!GetLightSources Getter 
	/*!Returns a vector of light sources in our scene*/
	std::vector<LightSource*> GetLightSources() const;

	void ObjectInFrustum(const GameObject& object_);


	void ProcessMouseMovement(glm::vec2 offset_);
	void ProcessMouseZoom(int y_);

	float GetNearPlane() const;
	float GetFarPlane() const;

private:

	enum {

		TOP = 0,
		BOTTOM,
		LEFT,
		RIGHT,
		NEARP,
		FARP
	};

	//!UpdateCameraVectors Function
	/*!Updates all of the cameras directional vectors*/
	void UpdateCameraVectors();
	void CalulateFrustrum();

	//!Position vector3
	/*!Stores this cameras position*/
	glm::vec3 position;

	//!Perspective, Orthographic and View matrices
	/*!Stores all of the cameras needed matrices*/
	glm::mat4 perspective, orthographic, view;

	//!FieldOfView float
	/*!Stores this cameras Field Of View*/
	float fieldOfView;

	//!Yaw and Pitch floats
	/*!Stores the camera's yaw/pitch rotation*/
	float yaw, pitch;

	//!Near Plane and Far Plane floats
	/*!Stores how close/far away we want the camera to be able to see things*/
	float nearPlane, farPlane;

	//!Directional vector3's
	/*!Stores all of the camera's directional vectors*/
	glm::vec3 forward, up, right, worldUp;

	//!Planes Array
	/*!Hold's all of the planes in the camera's frustrum*/
	Plane planes[6];

	//!Vector lightSources 
	/*!Holds a list of light sources in our scene*/
	std::vector<LightSource*> lightSources;



};
#endif
