#include "Graphics/Window.h"
#include "Core/CoreEngine.h"
#include "../Game/TestGame.h"
int main(int argc, char* argv[])
{
	CoreEngine::GetInstance()->SetGameInterface(new TestGame);

	 if (!CoreEngine::GetInstance()->OnCreate("OpenGL Engine", 800, 600))
	 {
		 Debug::FatalError("Engine Has Failed To Initialize", "main.cpp", __LINE__);
		 return 0;
	 }

	 CoreEngine::GetInstance()->Run();

	return 0;
}

 