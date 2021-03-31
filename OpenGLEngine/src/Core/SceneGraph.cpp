#include "SceneGraph.h"

std::unique_ptr<SceneGraph> SceneGraph::sceneInstance = nullptr;
std::unordered_map<GLuint, std::vector<Model*>> SceneGraph::sceneModels = std::unordered_map<GLuint, std::vector<Model*>>();
std::map<std::string, GameObject*> SceneGraph::sceneGameObjects = std::map<std::string, GameObject*>();


SceneGraph::SceneGraph()
{

}

SceneGraph::~SceneGraph()
{
	OnDestroy();
}

SceneGraph* SceneGraph::GetInstance()
{
	if (sceneInstance.get() == nullptr)
	{
		sceneInstance.reset(new SceneGraph);
	}

	return sceneInstance.get();
}



void SceneGraph::OnDestroy()
{
	if(sceneGameObjects.size() > 0) {
		for (auto go : sceneGameObjects)
		{
			delete go.second;
			go.second = nullptr;
		}
		sceneGameObjects.clear();
	}

	if (sceneModels.size() > 0) {
		for (auto entry : sceneModels)
		{
			if (entry.second.size() > 0)
			{
				for (auto m : entry.second) {
					delete m;
					m = nullptr;
				}
				entry.second.clear();
			}
		}
		sceneModels.clear();
	}

}

void SceneGraph::AddModel(Model* model_)
{
	GLuint shader = model_->GetShaderProgram();
	if (sceneModels.find(shader) == sceneModels.end()) {

		sceneModels.insert(std::pair<GLuint, std::vector<Model*>>(shader, std::vector<Model*>()));
		sceneModels[shader].reserve(10);
	}
	sceneModels[shader].push_back(model_);
}

void SceneGraph::AddGameObject(GameObject* go_, std::string name_)
{
	if (name_ == "") {

		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		go_->SetName(newName);
		sceneGameObjects[newName] = go_;
	}
	else if (sceneGameObjects.find(name_) == sceneGameObjects.end()) {

		go_->SetName(name_);
		sceneGameObjects[name_] = go_;
	}
	else
	{
		Debug::Error("Trying to add a gameobject with a name " + name_ + " that already exists", "SceneGraph.cpp", __LINE__);
		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		go_->SetName(newName);
		sceneGameObjects[newName] = go_;
	}
}

GameObject* SceneGraph::GetGameObject(std::string name_)
{
	if (sceneGameObjects.find(name_) != sceneGameObjects.end()) {

		return sceneGameObjects[name_];
	}
	return nullptr;
}

void SceneGraph::Update(const float deltatime_)
{
	for (auto go : sceneGameObjects)
	{
		go.second->Update(deltatime_);
	}
}

void SceneGraph::Render(Camera* camera_)
{
	for (auto entry : sceneModels) {
		glUseProgram(entry.first);
		for (auto m : entry.second) {
			m->Render(camera_);
		}
	
	}
}