#ifndef COREENGINE_H
#define COREENGINE_H

#include <memory>
#include "Graphics/Window.h"
class CoreEngine
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(const CoreEngine&&) = delete;

	static CoreEngine* GetInstance();
	bool OnCreate(std::string name_, int width_, int height_);


	void Run();
	bool GetIsRunning();

private:
	CoreEngine();
	~CoreEngine();
	void Update(const float deltatime_);
	void Render();
	void OnDestroy();

	static std::unique_ptr<CoreEngine> instance;
	friend std::default_delete<CoreEngine>;

	Window* window;
	bool isRunning;
};
#endif
