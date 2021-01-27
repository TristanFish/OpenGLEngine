#ifndef TESTGAME_H
#define TESTGAME_H

#include "Tools/GameInterface.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameScene.h"
class TestGame : public GameInterface
{
public:
	TestGame();

	virtual ~TestGame();

	bool OnCreate() override;
	void Update(const float deltaTime_) override;
	void Render() override;

private:
	int currentSceneNum;
	Scene* currentScene;
	void BuildScene();

};

#endif

