#ifndef COREENGINE_H
#define COREENGINE_H

#include "Graphics/Window.h"
#include "Tools/Debug.h"
#include "Tools/GameInterface.h"
#include "Timer.h"
#include "Scene.h"
#include "Graphics/3D/GameObject.h"
#include "Graphics/ShaderHandler.h"
#include "Graphics/TextureHandler.h"
#include "Camera.h"
#include <memory>

//! CoreEngine Class
/*!Control's the SDL/OpenGL window that our engine uses*/
class CoreEngine
{
public:

	// Makes sure this class can not be copied or another instance can not be created
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(const CoreEngine&&) = delete;


	//!GetInstance Getter
	/*!Returns the current instance of this object*/
	static CoreEngine* GetInstance();

	//!OnCreate Function
	/*!Initializes the engine*/
	bool OnCreate(std::string name_, int width_, int height_);

	//!Run Function
	/*!Calls the Engines essential functions*/
	void Run();

	//!Exit Function
	/*!*/
	void Exit();

	//!GetIsRunning Getter
	/*!Returns the isRunning variable*/
	bool GetIsRunning() const;

	//!GetCurrentScene Getter
	/*!Returns the current scene number*/
	int GetCurrentScene() const;

	//!GetScreenWidth Getter
	/*!Returns the screens width*/
	float GetScreenWidth() const;

	//!GetScreenHeight Getter
	/*!Returns the screens height*/
	float GetScreenHeight() const;

	//!GetCamera Getter
	/*!Returns a pointer to our camera*/
	Camera* GetCamera() const;

	//!SetGameInterface Setter
	/*!Sets our gameInterface pointer*/
	void SetGameInterface(GameInterface* gameInterface_);

	//!SetCurrentScene Function
	/*!Set's the current scene*/
	void SetCurrentScene(unsigned int sceneNum_);

	//!GetCamera Setter
	/*!Set's the camera to the Camera* parameter*/
	void SetCamera(Camera* camera_);

private:

	//!CoreEngine Constructor
	/*!Initializes class specific variables that will be used*/
	CoreEngine();

	//!CoreEngine Destructor
	/*!Empty Function*/
	~CoreEngine();

	//!Update Function
	/*!Updates all of the engines components*/
	void Update(const float deltatime_);

	//!Render Function
	/*!Renders all of the engines components*/
	void Render();

	//!OnDestroy Function
	/*!Deletes any of the class specific pointers & calls and other needed destroy functions*/
	void OnDestroy();

	//!CoreEngine unique pointer
	/*!Holds a pointer to this class*/
	static std::unique_ptr<CoreEngine> instance;

	//!CoreEngine default delete
	/*!Allows us to call the destructor when the instance of this class goes out of scope*/
	friend std::default_delete<CoreEngine>;

	//!Window Pointer
	/*!A new Window object that we use for our CoreEngine loop*/
	Window* window;

	//!isRunning boolean
	/*!Stores whether the engine is running or not*/
	bool isRunning;

	//!Timer Instance
	/*!The timer that our engine runs off of*/
	Timer* timer;

	//!Frame's Per Second
	/*!The FPS we want our engine to run at*/
	unsigned int fps;

	//!GameInterface Pointer
	/*!Used to link the game too th engine*/
	GameInterface* gameInterface;

	//!unsigned int currentSceneNum
	/*!The scene number that our engine is currently on*/
	unsigned int currentSceneNum;

	Camera* camera;
};
#endif
