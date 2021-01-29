#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H


//!GameInterface Abstract Class
/*!Enables us to create a link between the engine and the game */
class GameInterface
{
public:
	//!GameInterface Constructor
	/*!Blank Constructor */
	GameInterface() {}

	//!Virtual GameInterface Destructor
	/*!Add's the GameInterface destructor to this classes Vtable */
	virtual ~GameInterface() {}

	//!Pure Virtual OnCreate Function
	/*!Add's the OnCreate function to this classes Vtable and makes it pure so we know it has to be implemented by a inherited class.
	After this function has been overridden it will handle all of the initialization that will need to occur in the game classes*/
	virtual bool OnCreate() = 0;

	//!Pure Virtual Update Function
	/*!Add's the Update function to this classes Vtable and makes it pure so we know it has to be implemented by a inherited class.
	After this function has been overridden it will handle all of the updating that will need to occur in the game classes*/
	virtual void Update(const float deltaTime_) = 0;

	//!Pure Virtual Render Function
	/*!Add's the Render function to this classes Vtable and makes it pure so we know it has to be implemented by a inherited class 
	After this function has been overridden it will handle all of the rendering that will need to occur in the game classes*/
	virtual void Render() = 0;

};
#endif
