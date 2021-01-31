#include "GameScene.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

bool GameScene::OnCreate()
{
	Debug::Info("Game Scene Has Been Created", "GameScene.cpp", __LINE__);
	return true;
}

void GameScene::Update(const float deltaTime_)
{
	Debug::Trace("DeltaTime: " + std::to_string(deltaTime_), "CoreEngine.cpp", __LINE__);
}

void GameScene::Render()
{

}
