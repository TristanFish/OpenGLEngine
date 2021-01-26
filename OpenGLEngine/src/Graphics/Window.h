#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <string>
#include <iostream>
#include "Tools/Debug.h"

//! Window Class
/*!Control's the SDL/OpenGL window that our engine uses*/
class Window
{
public:

	//! Window Constructor
	/*!Initializes class specific variables that will be used*/
	Window();

	//! Window Destructor
	/*!Calls the OnDestroy method*/
	~Window();

	//! OnCreate Function
	/*!Initializes and creates a SDL/OpenGL window for use*/
	bool OnCreate(std::string name_, int width_, int height_);

	//! OnDestroy Function
	/*!Calls SDL/OpenGL destroy methods and deletes any class specific pointers*/
	void OnDestroy();


	//! GetWidth Getter
	/*!Returns our 'width' variable*/
	int GetWidth() const;

	//! GetHeight Getter
	/*!Returns our 'height' variable*/
	int GetHeight() const;


	//! GetWindow Getter
	/*!Returns a pointer to our SDL_Window*/
	SDL_Window* GetWindow() const;

private:

	//! SetPreAttributes Function
	/*!Set's the SDL/OpenGL rendering attributes before the window is created*/
	void SetPreAttributes();

	//! SetPostAttributes Function
	/*!Set's the SDL/OpenGL rendering attributes after the window is created*/
	void SetPostAttributes();

	//! Width Integer
	/*!Contains the width of our window*/
	int width;

	//! Height Integer
	/*!Contains the height of our window*/
	int height;

	//! SDL_Window Pointer
	/*!Window that is being used by our engine*/
	SDL_Window* window;

	//! SDL_GLContext 
	/*!Allows us to bind SDL & OpenGL together*/
	SDL_GLContext context;

};

#endif