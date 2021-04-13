#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "MouseEventListener.h"

//!EventListener Class   
/*!Handle's all of the event's in the engine*/
class EventListener
{
public:

	// Makes sure this class can not be copied or another instance can not be created
	EventListener(const EventListener&) = delete;
	EventListener(EventListener&&) = delete;
	EventListener& operator=(const EventListener&) = delete;
	EventListener& operator=(const EventListener&&) = delete;
	EventListener() = delete;


	//!EventListener Destructor
	/*!Empty Destructor*/
	~EventListener();


	//!Update Function
	/*!Updates the available input's that the engine can have*/
	static void Update();
};
#endif

