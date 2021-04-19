#ifndef PLANE_H
#define PLANE_H

#include <glm/glm.hpp>
#include "BoundingBox.h"
#include <math.h>

struct Plane
{
	glm::vec4 plane;

	glm::vec3 normal;

	inline Plane() {

		plane = glm::vec4(0.0f);
		normal = glm::vec3(0.0f);
	}

	inline Plane(const glm::vec3 normal_, const glm::vec3 point_) {


		glm::vec3 normalizedNorm = glm::normalize(normal_);
		plane.x = normalizedNorm.x;
		plane.y = normalizedNorm.y;
		plane.z = normalizedNorm.z;

		plane.w = -glm::dot(point_, normalizedNorm);
	}

	inline Plane(const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2)
	{
		glm::vec4 ExtV0;
		glm::vec3 e1 = v1 - v0;
		glm::vec3 e2 = v2 - v1;
		normal = glm::cross(e1,e2);
		normal = glm::normalize(normal);

		//The extension vector from Vec3 to Vec4
		ExtV0.x = v0.x;
		ExtV0.y = v0.y;
		ExtV0.z = v0.z;
		ExtV0.w = 1.0;

		//Calculating the plane 
		plane.x = normal.x * ExtV0.x;
		plane.y = normal.y * ExtV0.y;
		plane.z = normal.z * ExtV0.z;
		plane.w = plane.w * ExtV0.w;
	}


	inline float Distance(glm::vec3& p_) {
		
		float topValue = plane.x + plane.y + plane.z + plane.w;

		float botValue = sqrt(pow(p_.x, 2.0f) + pow(p_.y, 2.0f) + pow(p_.z, 2.0f));

		return topValue / botValue;
	}

	inline int OBBIntersection(BoundingBox box)
	{
		glm::vec3 centre = (box.maxVert + box.minVert) * 0.5f;

		glm::vec3 extent = box.minVert - centre;

		glm::vec3 oExtent = box.maxVert - centre;


		//float r = extent.x * glm::dot(abs(normal.x),extent.y) + extent.y * abs(normal.y) + extent.z * abs(normal.z);

		float r = extent.x * glm::dot(abs(normal.x), oExtent.x) + extent.y * glm::dot(abs(normal.y), oExtent.y) + extent.z * glm::dot(abs(normal.z), oExtent.z);

		float distCentre = glm::dot(normal, centre) - plane.w;


		return abs(distCentre) > r;
	}


	inline void CreateFromPoints(const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2)
	{
		glm::vec3 Normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));
		normal = Normal;
		CreateFromNormal(v0, Normal);
	}
	inline void CreateFromNormal(const glm::vec3& p, const glm::vec3& normal)
	{
		
		glm::vec3 NormalizedNormal = glm::normalize(normal);
		plane.x = NormalizedNormal.x;
		plane.y = NormalizedNormal.y;
		plane.z = NormalizedNormal.z;
		plane.w = -glm::dot(p, normal);
	}
	inline void UpdatePlane(float x_, float y_, float z_, float w_) {

		plane = glm::vec4(x_, y_, z_, w_);

		normal = glm::vec3(normalize(plane));
		plane = plane;
	}
};

#endif