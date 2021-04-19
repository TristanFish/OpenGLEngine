#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H
#include "Core/Camera.h"


struct Ray;
struct BoundingBox;


//!CollisionDetection Class
/*!Handle's the detection of all collisions in our engine*/
class CollisionDetection
{
public:

	// Makes sure this class can not be copied or another instance can not be created
	CollisionDetection(const CollisionDetection&) = delete;
	CollisionDetection(CollisionDetection&&) = delete;
	CollisionDetection& operator=(const CollisionDetection&) = delete;
	CollisionDetection& operator=(CollisionDetection&&) = delete;


	//!CollisionDetection Constructor
	/*!Make's sure we can't crate an instance of this class*/
	CollisionDetection() = delete;

	//!CollisionDetection Destructor
	/*!Empty Function*/
	~CollisionDetection();
public:

	//!MousePosToWorldRay Function
	/*!Convert's the mouse screen position to a location in world space*/
	static Ray MousePosToWorldRay(glm::vec2 mouseCoords, float screenWidth_, float screenHeight_, Camera* camera_);

	//!RayOBBIntersection Function
	/*!Check's if a Ray is intersecting a OBB*/
	static bool RayOBBIntersection(Ray* ray_, BoundingBox* box_);

};
#endif

