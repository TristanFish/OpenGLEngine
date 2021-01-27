#include "TestGame.h"

TestGame::TestGame() : GameInterface(), currentSceneNum(0), currentScene(nullptr)
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
		currentSceneNum = 0;
		return currentScene->OnCreate();
	}
	Debug::Error("Engine's scene is not initialized to 0", "TestGame.cpp", __LINE__);
	return false;
}

void TestGame::Update(const float deltaTime_)
{
	if (currentSceneNum != CoreEngine::GetInstance()->GetCurrentScene())
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

	currentSceneNum = CoreEngine::GetInstance()->GetCurrentScene();

	if (!currentScene->OnCreate())
	{
		Debug::Error("Scene has failed to be created", "TestGame.cpp", __LINE__);
		CoreEngine::GetInstance()->Exit();
	}

}
