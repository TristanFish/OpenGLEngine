#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::instance = nullptr;

CoreEngine::CoreEngine() : window(nullptr), isRunning(false), fps(60)
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
	window = new Window();
	if (!window->OnCreate(name_, width_, height_))
	{
		std::cout << "Window failed to initialize" << std::endl;
		OnDestroy();
		return isRunning = false;
	}
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

void CoreEngine::Update(const float deltatime_)
{

}

void CoreEngine::Render()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapWindow(window->GetWindow());
}

void CoreEngine::OnDestroy()
{
	delete window;
	window = nullptr;
	SDL_Quit();
	exit(0);
	
}
