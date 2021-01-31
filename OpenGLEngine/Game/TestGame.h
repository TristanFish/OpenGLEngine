#ifndef TESTGAME_H
#define TESTGAME_H

#include "Tools/GameInterface.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameScene.h"

//!TestGame Class
/*!Acts as our interface between the engine and the game by inheriting Game Interface. As well as updates/renders the current scene*/
class TestGame : public GameInterface
{
public:


	//!GameScenes enum class
	/*!Holds all the scenes that the game will have*/
	enum class GameScenes : unsigned int {
		StartScene = 0,
		GameScene
	};

	//!TestGame constructor
	/*!Initializes class specific variables*/
	TestGame();

	//!Virtual TestGame destructor
	/*!Add's the TestGame destructor to this classes Vtable\*/
	virtual ~TestGame();

	//!OnCreate Function overrider
	/*!Overrides the GameInterface OnCreate and initializes any needed variables*/
	bool OnCreate() override;

	//!Update Function overrider
	/*!Overrides the GameInterface Update and updates our current scene*/
	void Update(const float deltaTime_) override;

	//!Render Function overrider
	/*!Overrides the GameInterface Render and renders our current scene*/
	void Render() override;

private:

	//!Current Scene Name
	/*!Holds the name of the current scene that the game is in via enum*/
	GameScenes currentSceneName;

	//!CurrentScene pointer
	/*!Holds a pointer to the current scene that the game is in*/
	Scene* currentScene;

	//!BuildScene Function
	/*!Initializes a new scene depending on our currentSceneName*/
	void BuildScene();

};

#endif

