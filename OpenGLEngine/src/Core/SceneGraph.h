#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <memory>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "Graphics/3D/GameObject.h"

//!SceneGraph Class
/*!Handle's all of the objects in a scene*/
class SceneGraph
{
public:
	// Makes sure this class can not be copied or another instance can not be created
	SceneGraph(const SceneGraph&) = delete;
	SceneGraph(SceneGraph&&) = delete;
	SceneGraph& operator=(const SceneGraph&) = delete;
	SceneGraph& operator=(const SceneGraph&&) = delete;

	//!GetInstance Getter
	/*!Return's the instance of this class if one exists. If one doesn't then it creates it*/
	static SceneGraph* GetInstance();

	//!Update Function
	/*!Update's all of the gameobjects in the scene*/
	void Update(const float deltatime_);

	//!Render Function
	/*!Renders all of the gameobjects in the scene*/
	void Render(Camera* camera_);

	//!OnDestroy Function
	/*!Deletes and clears the gameobjects and models*/
	void OnDestroy();

	//!AddModel Function
	/*!Add's a model to the vector of sceneModels*/
	void AddModel(Model* model_);

	//!AddGameObject Function
	/*!Add's a gameobject to the vector of sceneModels*/
	void AddGameObject(GameObject* go_, std::string name_ = "");

	//!GetGameObject Function
	/*!Return's a gameobject with the given name*/
	GameObject* GetGameObject(std::string name_);

private:
	//!SceneGraph Constructor
	/*!Default constructor*/
	SceneGraph();

	//!SceneGraph Destructor
	/*!Call's the OnDestroy Function*/
	~SceneGraph();
	
	

	//!SceneGraph unique pointer
	/*!Holds a pointer to this class*/
	static std::unique_ptr<SceneGraph> sceneInstance;

	//!SceneGraph default delete
	/*!Allows us to call the destructor when the instance of this class goes out of scope*/
	friend std::default_delete<SceneGraph>;

	//!sceneModels unorderedMap
	/*!Contain's all of the models in our scene*/
	static std::unordered_map<GLuint, std::vector<Model*>> sceneModels;

	//!sceneGameObjects Map
	/*!Contain's all of the gameObjects in our scene*/
	static std::map<std::string, GameObject*> sceneGameObjects;
};
#endif
