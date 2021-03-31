#ifndef MTLOADER_H
#define MTLOADER_H

#include "Graphics/MaterialHandler.h"
#include "Graphics/TextureHandler.h"
#include <sstream>

//!MTLoader class
/*!Handle's loading of .mtl files in our engine*/
class MTLoader
{
public:
	// Makes sure this class can not be copied or another instance can not be created
	MTLoader(const MTLoader&) = delete;
	MTLoader(MTLoader&&) = delete;
	MTLoader& operator=(const MTLoader&) = delete;
	MTLoader& operator=(MTLoader&&) = delete;


	MTLoader() = delete;


	~MTLoader();

	//!LoadMaterial Function
	/*!Load's a material from a file path and adds it too the Material Handler*/
	static void LoadMaterial(std::string filePath_);
private:

	//!LoadTexture Function
	/*!Load's a texture from a file path and add's it too the TextureHandler*/
	static GLuint LoadTexture(std::string fileName_);
};
#endif
