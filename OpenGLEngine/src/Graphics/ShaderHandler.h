#ifndef SHADERHANDLER_H
#define SHADERHANLDER_H

#include <sstream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <glew.h>
#include "Tools/Debug.h"


//! Shader Handler Class
/*!Control's how shaders are constructed and handled*/
class ShaderHandler
{
public:
	// Makes sure this class can not be copied or another instance can not be created
	ShaderHandler(const ShaderHandler&) = delete;
	ShaderHandler(ShaderHandler&&) = delete;
	ShaderHandler& operator=(const ShaderHandler&) = delete;
	ShaderHandler& operator=(ShaderHandler&&) = delete;

	//!GetInstance Getter
	/*!Returns the current instance of this object*/
	static ShaderHandler* GetInstance();

	//!CreateProgram Function
	/*!Creates a new shader program and add's it too the programs unordered_map*/
	void CreateProgram(const std::string& shaderName_, const std::string& vertexShaderFile_, const std::string& fragmentShaderFile_);

	//!GetShader Function
	/*!Returns the shader that correlates to the functions input*/
	GLuint GetShader(const std::string& shaderName_);

	//!OnDestroy Function
	/*!Deletes all of the shaders in the programs unordered map*/
	 void OnDestroy();

private:

	//!ShaderHandler Constructor
	/*!Empty function*/
	ShaderHandler();

	//!ShaderHandler Destructor
	/*!Call's the classes onDestroy method*/
	~ShaderHandler();

	//!ShaderHandler unique pointer
	/*!Holds a pointer to this class*/
	static std::unique_ptr<ShaderHandler> shaderInstance;

	//!ShaderHandler default delete
	/*!Allows us to call the destructor when the instance of this class goes out of scope*/
	friend std::default_delete<ShaderHandler>;

	//!ReadShader Function
	/*!Read's the shader file and converts it into a string then returns it*/
	std::string ReadShader(const std::string& filePath_);

	//!CreateShader Function
	/*!Creates a shader and then returns it*/
	GLuint CreateShader(GLenum shaderType_, const std::string& source_, const std::string& shaderName_);

	//!programs unordered_map
	/*!Hold's all of programs within it's key/value pairs*/
	static std::unordered_map<std::string, GLuint> programs;
};

#endif

