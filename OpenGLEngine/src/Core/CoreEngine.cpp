#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::instance = nullptr;

CoreEngine::CoreEngine() : window(nullptr), isRunning(false), fps(60), gameInterface(nullptr)
{

}

CoreEngine::~CoreEngine()
{

}

CoreEngine* CoreEngine::GetInstance()
{
	if (instance.get() == nullptr)
	{
		instance.reset(new CoreEngine);
	}
	return instance.get();
}

bool CoreEngine::OnCreate(std::string name_, int width_, int height_)
{
	Debug::OnCreate();
	window = new Window();
	if (!window->OnCreate(name_, width_, height_))
	{
		Debug::FatalError("Window Has Failed To Initialize", "CoreEngine.cpp", __LINE__);
		OnDestroy();
		return isRunning = false;
	}

	if (gameInterface)
	{
		if (!gameInterface->OnCreate())
		{
			Debug::FatalError("Game Has Failed To Initialize", "CoreEngine.cpp", __LINE__);
			OnDestroy();
			return isRunning = false;
		}
	}


	Debug::Info("Engine Has Been Successfully Created ", "CoreEngine.cpp", __LINE__);
	timer.Start();
	return isRunning = true;
}

void CoreEngine::Run()
{
	while (isRunning)
	{
		timer.UpdateFrameTricks();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}

	OnDestroy();
}

bool CoreEngine::GetIsRunning()
{
	return isRunning;
}

void CoreEngine::SetGameInterface(GameInterface* gameInterface_)
{
	gameInterface = gameInterface_;
}

void CoreEngine::Update(const float deltatime_)
{
	if (gameInterface)
	{
		gameInterface->Update(deltatime_);
		Debug::Trace("DeltaTime: " + std::to_string(deltatime_), "CoreEngine.cpp", __LINE__);

	}
}

void CoreEngine::Render()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gameInterface)
	{
		gameInterface->Render();
	}

	SDL_GL_SwapWindow(window->GetWindow());
}

void CoreEngine::OnDestroy()
{
	delete gameInterface;
	gameInterface = nullptr;

	delete window;
	window = nullptr;
	SDL_Quit();
	exit(0);
	
}
