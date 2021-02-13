#include "GameScene.h"

GameScene::GameScene() : square(nullptr)
{

}

GameScene::~GameScene()
{
	delete square;
	square = nullptr;
}

bool GameScene::OnCreate()
{
	Debug::Info("Game Scene Has Been Created", "GameScene.cpp", __LINE__);

	
	InitilizeModel();
	return true;
}

void GameScene::Update(const float deltaTime_)
{
}

void GameScene::Render()
{
	square->Render();
}

Mesh* GameScene::InitilizeSquareMesh(const float size_)
{
	Vertex vert;
	std::vector<Vertex> vertexList;
	vertexList.reserve(6);
	vert.position = glm::vec3(-size_, size_, 0.0f);
	vert.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(vert);

	vert.position = glm::vec3(-size_, -size_, 0.0f);
	vert.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(vert);

	vert.position = glm::vec3(0.0f, -size_, 0.0f);
	vert.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(vert);

	vert.position = glm::vec3(-size_, size_, 0.0f);
	vert.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(vert);

	vert.position = glm::vec3(0.0f, size_, 0.0f);
	vert.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	vertexList.push_back(vert);

	vert.position = glm::vec3(0.0f, -size_, 0.0f);
	vert.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	vertexList.push_back(vert);

	return new Mesh(vertexList);
}

Mesh* GameScene::InitilizeTriangleMesh(const float size_)
{
	Vertex vert;
	std::vector<Vertex> vertexList;
	vertexList.reserve(3);
	vert.position = glm::vec3(0.0f, size_, 0.0f);
	vert.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(vert);

	vert.position = glm::vec3(-size_, -size_, 0.0f);
	vert.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(vert);

	vert.position = glm::vec3(size_, -size_, 0.0f);
	vert.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(vert);

	return new Mesh(vertexList);
}

void GameScene::InitilizeModel()
{
	Mesh* Square = InitilizeSquareMesh(0.25f);


	Model* model = new Model(ShaderHandler::GetInstance()->GetShader("colourShader"));
	model->AddMesh(Square);
	square = new GameObject(model);
}
