#ifndef SCENE_H
#define SCENE_H

//!Abstract Scene Class
/*!Hold's all of the needed functions for a scene to be created*/
class Scene {
public:
	
	//!Class Constructor
	/*!Blank Constructor*/
	Scene() {};

	//!Virtual Scene Destructor
	/*!Add's the GameInterface destructor to this classes Vtable */
	virtual ~Scene() {};

	//!Pure Virtual OnCreate Function
	/*!Add's the OnCreate function to this classes Vtable and makes it pure so we know it has to be implemented by a inherited class.
	After this function has been overridden it will handle all of the initialization that will need to occur our scene classes*/
	virtual bool OnCreate() = 0;

	//!Pure Virtual Update Function
	/*!Add's the Update function to this classes Vtable and makes it pure so we know it has to be implemented by a inherited class.
	After this function has been overridden it will handle all of the updating that will need to occur in our scene classes*/
	virtual void Update(const float deltaTime_) = 0;

	//!Pure Virtual Render Function
	/*!Add's the Render function to this classes Vtable and makes it pure so we know it has to be implemented by a inherited class
	After this function has been overridden it will handle all of the rendering that will need to occur in our scene classes*/
	virtual void Render() = 0;
};
#endif