#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Core/CoreEngine.h"

//!GameScene Class
/*!Control's our game scene and inheritress from Scene*/
class GameScene : public Scene
{
public:

	//!GameScene Constructor
	/*!Initializes any class specific variables*/
	GameScene();

	//!Virtual GameScene Destructor
	/*!Add's the GameScene destructor to this classes Vtable*/
	virtual ~GameScene();

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

