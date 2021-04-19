#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Ray.h"
#include "Graphics/3D/GameObject.h"

//!CollisionHandler Class
/*!Handle's all of the collisions that can occour in the game/engine*/
class CollisionHandler
{
public:
	// Makes sure this class can not be copied or another instance can not be created
	CollisionHandler(const CollisionHandler&) = delete;
	CollisionHandler(CollisionHandler&&) = delete;
	CollisionHandler& operator=(const CollisionHandler&) = delete;
	CollisionHandler& operator=(CollisionHandler&&) = delete;

	//!GetInstance Function
	/*!Get's the instance of this class (Singleton)*/
	static CollisionHandler* GetInstance();

	//!OnCreate Function
	/*!Initializes all of the needed variables*/
	void OnCreate();

	//!AddObject Function
	/*!Add's a gameobject to the list of possible collisions*/
	void AddObject(GameObject* go_);

	//!MouseUpdate Function
	/*!Does the check to see if the mouse is intersecting one of the possible colliders*/
	void MouseUpdate(glm::vec2 mousePosition_, int buttonType_);

	//!OnDestroy Function
	/*!Clear's and deletes all of the pointers that are being used*/
	void OnDestroy();

private:

	//!CollisionHandler Constructor
	/*!Empty Function*/
	CollisionHandler();

	//!CollisionHandler Destructor
	/*!Empty Function*/
	~CollisionHandler();


	//!CollisionHandler unique pointer
	/*!Holds a pointer to this class*/
	static std::unique_ptr<CollisionHandler> collisionInstance;

	//!CollisionHandler default delete
	/*!Allows us to call the destructor when the instance of this class goes out of scope*/
	friend std::default_delete<CollisionHandler>;


	//!Colliders Vector
	/*!Hold's all of the possible gameobjects that can be collided/intersected with*/
	static std::vector<GameObject*> colliders;
	static std::vector<GameObject*> prevCollisions;

};
#endif
