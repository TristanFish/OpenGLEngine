#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

constexpr float MILLI_TO_SEC = 1000.0f;

//!Timer Class
/*!Keep's track of how quick everything in the engine is being updated*/
class Timer
{
public:

	// Makes sure this class can not be copied or another instance can not be created
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator=(const Timer&) = delete;
	Timer& operator=(Timer&&) = delete;

	//!Timer Constructor
	/*!Initializes some local variables*/
	Timer();

	//!Timer Destructor
	/*!Empty*/
	~Timer();

	//!Start Function
	/*!Initializes the prevTicks variable*/
	void Start();

	//!UpdateFrameTricks Function
	/*!Updates the prev/current ticks variables*/
	void UpdateFrameTricks();
	
	//!GetDeltaTime Getter
	/*!Returns the engines Delta time(Time Between Frames)*/
	float GetDeltaTime() const;

	//!GetSleepTime Getter
	/*!Returns the time we want the engine to sleep for */
	unsigned int GetSleepTime(const unsigned int fps_) const;

	//!GetCurrentTickMilli Getter
	/*!Returns the currentTicks variable in milliseconds*/
	float GetCurrentTickMilli() const;

	//!GetCurrentTickSec Getter
	/*!Returns the currentTicks variable in seconds*/
	float GetCurrentTickSec() const;

private:

	//!prevTicks variable
	/*!Hold's a older version of currentTicks*/
	unsigned int prevTicks;

	//!currentTicks variable
	/*!Hold's the number of miliseconds since sdl has been initialized*/
	unsigned int currentTicks;
};

#endif