#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <memory>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Tools/Debug.h"
#include <glew.h>

//!Texture Struct
/*!Hold's all of the needed information for a texture*/
struct Texture {
	GLuint textureID = 0;
	float width = 0.0f;
	float height = 0.0f;
	std::string textureName = "";
};

//!TextureHandler class
/*!Handles how textures can be created and used in our engine*/
class TextureHandler
{
public:
	// Makes sure this class can not be copied or another instance can not be created
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler(TextureHandler&&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;
	TextureHandler& operator=(const TextureHandler&&) = delete;

	//!GetInstance Getter
    /*!Returns the instance of this TextureHandler since it is a singleton*/
	static TextureHandler* GetInstance();

	//!OnDestroy Function
	/*!Deletes the textures in the std::vector<Texture*>*/
	void OnDestroy();

	//!CreateTexture Function
	/*!Creates a new texture with the functions paremeters*/
	void CreateTexture(const std::string& textureName_, const std::string& textureFilePath_);

	//!GetTexture Getter
	/*!Returns a textureID depedning on the name that is given*/
	const GLuint GetTexture(const std::string& textureName_);

	//!GetTextureData Getter
	/*!Returns a texture struct depedning on the name that is given*/
	const Texture* GetTextureData(const std::string textureName_);

private:

	//!TextureHandler Constructor
	/*!Initializes this classes variables*/
	TextureHandler();

	//!TextureHandler Destructor
	/*!Call's the OnDestroy function*/
	~TextureHandler();


	//!TextureHandler unique pointer
	/*!Holds a pointer to this class*/
	static std::unique_ptr<TextureHandler> textureInstance;

	//!TextureHandler default delete
	/*!Allows us to call the destructor when the instance of this class goes out of scope*/
	friend std::default_delete<TextureHandler>;

	//!Vector textures
	/*!Hold's a vector of textures that the engine is currently using*/
	static std::vector<Texture*> textures;

};

#endif

