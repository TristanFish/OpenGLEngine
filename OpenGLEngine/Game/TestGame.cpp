#include "TestGame.h"

TestGame::TestGame() : GameInterface(), currentSceneName(GameScenes::StartScene), currentScene(nullptr)
{

}

TestGame::~TestGame()
{
	delete currentScene; currentScene = nullptr;
}

bool TestGame::OnCreate()
{
	if (CoreEngine::GetInstance()->GetCurrentScene() == 0)
	{
		currentScene = new StartScene();
		currentSceneName = GameScenes::StartScene;
		return currentScene->OnCreate();
	}
	Debug::Error("Engine's scene is not initialized to 0", "TestGame.cpp", __LINE__);
	return false;
}

void TestGame::Update(const float deltaTime_)
{
	if (currentSceneName != static_cast<GameScenes>(CoreEngine::GetInstance()->GetCurrentScene()))
	{
		BuildScene();
	}
	currentScene->Update(deltaTime_);
}

void TestGame::Render()
{
	currentScene->Render();
}

void TestGame::BuildScene()
{
	delete currentScene;
	currentScene = nullptr;

	switch (CoreEngine::GetInstance()->GetCurrentScene())
	{
	case 1:
		currentScene = new GameScene();
		break;

	default:
		currentScene = new StartScene();
		break;
	}

	currentSceneName = static_cast<GameScenes>(CoreEngine::GetInstance()->GetCurrentScene());

	if (!currentScene->OnCreate())
	{
		Debug::Error("Scene has failed to be created", "TestGame.cpp", __LINE__);
		CoreEngine::GetInstance()->Exit();
	}

}
