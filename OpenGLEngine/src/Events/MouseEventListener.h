#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include <SDL.h>
#include <glm/glm.hpp>

class CoreEngine;

//!MouseEventListener  
/*!Handle's all of the mouse events in our engine*/
class MouseEventListener
{
public:

	// Makes sure this class can not be copied or another instance can not be created
	MouseEventListener(const MouseEventListener&) = delete;
	MouseEventListener(MouseEventListener&&) = delete;
	MouseEventListener& operator=(const MouseEventListener&) = delete;
	MouseEventListener& operator=(const MouseEventListener&&) = delete;

	MouseEventListener() = delete;
	~MouseEventListener();

	//!RegisterEngineObject Function  
	/*!Initalizes the Core Engine pointer*/
	static void RegisterEngineObject(CoreEngine* engine_);

	//!Update Function  
	/*!Check's the mouse state and updates what is needed*/
	static void Update(SDL_Event e_);


	//!NotifyOfMousePressed Function  
	/*!Call's the engine's instance notify pressed function*/
	static void NotifyOfMousePressed(int buttonType_);

	//!NotifyOfMouseReleased Function  
	/*!Call's the engine's instance notify released function*/
	static void NotifyOfMouseReleased(int buttonType_);

	//!NotifyOfMouseMove Function  
	/*!Call's the engine's instance notify MouseMoved function*/
	static void NotifyOfMouseMove();

	//!NotifyOfMouseScroll Function  
	/*!Call's the engine's instance notify MouseScroll function*/
	static void NotifyOfMouseScroll(int y_);

	//!GetPreviousMousePosition Getter  
	/*!Get's the previous mouse position*/
	static glm::ivec2 GetPreviousMousePosition();

	//!GetMousePosition Getter  
	/*!Get's the mouse position*/
	static glm::ivec2 GetMousePosition();

	//!GetMousePosition Getter  
	/*!Get's the offset*/
	static glm::ivec2 GetMouseOffset();

private:

	//!CoreEngine Pointer  
	/*!Hold's a pointer to the coreEnigne*/
	static CoreEngine* engineInstance;

	//!Mouse Positions   
	/*!Hold's the previous and current mouse positions*/
	static glm::ivec2 mouse, prevMouse;

	//!FirstUpdate Bool   
	/*!*/
	static bool firstUpdate;

	//!UpdateMousePosition Function   
	/*!Update's the mouses current and previous position*/
	static void UpdateMousePosition(); 


};

#endif