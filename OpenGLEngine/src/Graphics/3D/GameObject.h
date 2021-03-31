#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"

//!GameObject class
/*!Hold's all the information that a GameObject needs */
class GameObject
{
public:
	//!GameObject Constructor
	/*!Initializes the classes variables */
	GameObject(Model* model_);

	//!GameObject Constructor
	/*!Initializes the classes variables */
	GameObject(Model* model_, glm::vec3 position_);

	//!GameObject Destructor
	/*!Deletes any pointers this class uses*/
	~GameObject();

	//!Render Function
	/*!Renders the gameobjects mesh*/
	void Update(const float deltaTime_);

	//!Render Function
	/*!Renders the gameobjects mesh*/
	void Render(Camera* camera_);

	//!GetPosition Getter
	/*!Returns this gameobjects location*/
	glm::vec3 GetPosition() const;

	//!GetAngle Getter
	/*!Returns this gameobjects angle*/
	float GetAngle() const;

	//!GetRotation Getter
	/*!Returns this gameobjects rotation*/
	glm::vec3 GetRotation() const;

	//!GetScale Getter
	/*!Returns this gameobjects scale*/
	glm::vec3 GetScale() const;

	std::string GetName() const;

	//!SetPosition Setter
	/*!Sets this gameobjects position*/
	void SetPosition(glm::vec3 positiom_);

	//!SetAngle Setter
	/*!Sets this gameobjects angle*/
	void SetAngle(float angle_);

	//!SetRotation Setter
	/*!Sets this gameobjects rotation*/
	void SetRotation(glm::vec3 rotation_);

	//!SetScale Setter
	/*!Sets this gameobjects scale*/
	void SetScale(glm::vec3 scale_);

	//!SetName Setter
	/*!Sets this gameobjects name*/
	void SetName(std::string name_);

private:

	void UpdateModelInstance() const;

	//!Position vector3
	/*!Holds our gameobjects position*/
	glm::vec3 position;

	//!ModelInstance unsigned int
	/*!Holds our gameobjects model instance*/
	unsigned int modelInstance;

	//!Angle float
	/*!Holds our gameobjects angle*/
	float angle;

	//!Rotation vector3
	/*!Holds our gameobjects rotation*/
	glm::vec3 rotation;

	//!Scale vector3
	/*!Holds our gameobjects scale*/
	glm::vec3 scale;

	//!Model Pointer
	/*!Holds a pointer too the model the gameobject uses*/
	Model* model;

	//!Name string
	/*!Hold's the gameobjects name*/
	std::string name;
};

#endif;

