#ifndef TESTGAME_H
#define TESTGAME_H

#include "Tools/GameInterface.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameScene.h"
class TestGame : public GameInterface
{
public:

	enum class GameScenes : unsigned int {
		StartScene = 0,
		GameScene
	};


	TestGame();

	virtual ~TestGame();

	bool OnCreate() override;
	void Update(const float deltaTime_) override;
	void Render() override;

private:
	GameScenes currentSceneName;
	Scene* currentScene;
	void BuildScene();

};

#endif

