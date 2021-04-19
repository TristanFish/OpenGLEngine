#ifndef RAY_H
#define RAY_H

#include "BoundingBox.h"
#include "CollisionDetection.h"

//!Ray Struct
/*!Hold's all of the needed information for a Ray in the engine*/
struct Ray {

	//!Vec3 origin
	/*!Stores's where the ray is coming from (Position)*/
	glm::vec3 origin;

	//!Vec3 Direction
	/*!Store's the direction the ray is pointing*/
	glm::vec3 direction;

	float intersectionDist;

	//!Ray Empty Constructor
	/*!Set's defaults for everything*/
	inline Ray() {

		origin = glm::vec3();
		direction = glm::vec3();
		intersectionDist = 0.0f;
	}

	//!Ray Parameterized Constructor
	/*!Set's defaults for everything with the given parameters*/
	inline Ray(glm::vec3 origin_, glm::vec3 direction_)
	{
		origin = origin_;
		direction = direction_;
		intersectionDist = 0.0f;
	}

	//!Ray equals operator
	/*!Allow's us to set a ray to another ray*/
	inline Ray& operator = (const Ray& ray_)
	{
		origin = ray_.origin;
		direction = ray_.direction;
		intersectionDist = 0.0f;
	}

	//!IsColliding Function
	/*!Return's if a ray is intersecting a OBB/Box*/
	inline bool IsColliding(BoundingBox* box_)
	{
		intersectionDist = -1.0f;
		return CollisionDetection::RayOBBIntersection(this, box_);
	}

};



#endif // RAY_H
