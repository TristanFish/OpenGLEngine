#ifndef SHADERHANDLER_H
#define SHADERHANLDER_H

#include <sstream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <glew.h>
#include "Tools/Debug.h"

class ShaderHandler
{
public:
	// Makes sure this class can not be copied or another instance can not be created
	ShaderHandler(const ShaderHandler&) = delete;
	ShaderHandler(ShaderHandler&&) = delete;
	ShaderHandler& operator=(const ShaderHandler&) = delete;
	ShaderHandler& operator=(ShaderHandler&&) = delete;


	static ShaderHandler* GetInstance();

	void CreateProgram(const std::string& shaderName_, const std::string& vertexShaderFile_, const std::string& fragmentShaderFile_);
	GLuint GetShader(const std::string& shaderName_);

	 void OnDestroy();

private:

	ShaderHandler();
	~ShaderHandler();

	static std::unique_ptr<ShaderHandler> shaderInstance;
	friend std::default_delete<ShaderHandler>;

	std::string ReadShader(const std::string& filePath_);
	GLuint CreateShader(GLenum shaderType_, const std::string& source_, const std::string& shaderName_);

	static std::unordered_map<std::string, GLuint> programs;
};

#endif

