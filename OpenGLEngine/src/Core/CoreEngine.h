#ifndef COREENGINE_H
#define COREENGINE_H

#include "Graphics/Window.h"
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

	//!GetIsRunning Getter
	/*!Returns the isRunning variable*/
	bool GetIsRunning();

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
	/*!A new Window object*/
	Window* window;

	//!isRunning boolean
	/*!Stores whether the engine is running or not*/
	bool isRunning;
};
#endif
