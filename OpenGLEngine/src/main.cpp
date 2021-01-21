#include "Graphics/Window.h"
#include "Core/CoreEngine.h"

int main(int argc, char* argv[])
{


	 if (!CoreEngine::GetInstance()->OnCreate("OpenGL Engine", 800, 600))
	 {
		 std::cout << "Engine Failed to initialize" << std::endl;
		 return 0;
	 }

	 CoreEngine::GetInstance()->Run();

	return 0;
}

 