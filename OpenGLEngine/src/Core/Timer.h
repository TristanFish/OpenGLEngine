#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

constexpr float MILLI_TO_SEC = 1000.0f;

class Timer
{
public:

	// Makes sure this class can not be copied or another instance can not be created
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator=(const Timer&) = delete;
	Timer& operator=(Timer&&) = delete;

	Timer();
	~Timer();

	void Start();
	void UpdateFrameTricks();
	

	float GetDeltaTime() const;

	unsigned int GetSleepTime(const unsigned int fps_) const;
	float GetCurrentTickMilli() const;
	float GetCurrentTickSec() const;

private:

	unsigned int prevTicks;
	unsigned int currentTicks;
};

#endif