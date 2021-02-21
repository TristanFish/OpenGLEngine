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

	//!GameObject Destructor
	/*!Deletes any pointers this class uses*/
	~GameObject();

	//!Render Function
	/*!Renders the gameobjects mesh*/
	void Render(Camera* camera_);

private:

	//!Model Pointer
	/*!Holds a pointer too the model the gameobject uses*/
	Model* model;
};

#endif;

