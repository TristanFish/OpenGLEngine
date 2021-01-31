#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "Core/CoreEngine.h"

//!StartScene Class
/*!Control's our start scene and inheritress from Scene*/
class StartScene : public Scene
{
public:
	//!StartScene Constructor
	/*!Initializes any class specific variables*/
	StartScene();

	//!Virtual StartScene Destructor
	/*!Add's the StartScene destructor to this classes Vtable*/
	virtual ~StartScene();

	//!OnCreate Function overrider
	/*!Overrides the Scene OnCreate and initializes any needed variables*/
	bool OnCreate() override;

	//!Update Function overrider
	/*!Overrides the Scene Update and updates our current scene*/
	void Update(const float deltaTime_) override;

	//!Render Function overrider
	/*!Overrides the Scene Render and renders our current scene*/
	void Render() override;


};

#endif
