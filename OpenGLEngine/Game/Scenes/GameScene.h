#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Core/CoreEngine.h"
#include <memory>

//!GameScene Class
/*!Control's our game scene and inheritress from Scene*/
class GameScene : public Scene
{
public:

	//!GameScene Constructor
	/*!Initializes any class specific variables*/
	GameScene();

	//!Virtual GameScene Destructor
	/*!Add's the GameScene destructor to this classes Vtable*/
	virtual ~GameScene();

	//!OnCreate Function overrider
	/*!Overrides the Scene OnCreate and initializes any needed variables*/
	bool OnCreate() override;

	//!Update Function overrider
	/*!Overrides the Scene Update and updates our current scene*/
	void Update(const float deltaTime_) override;

	//!Render Function overrider
	/*!Overrides the Scene Render and renders our current scene*/
	void Render() override;

private:

	//!InitilizeSquareMesh Function
	/*!Creates a list of vertices for a square and then returns the vertices as a mesh*/
	Mesh* InitilizeSquareMesh(const float size_);

	//!InitilizeTriangleMesh Function
	/*!Creates a list of vertices for a triangle and then returns the vertices as a mesh*/
	Mesh* InitilizeTriangleMesh(const float size_);

	//!InitilizeTriangleMesh Function
	/*!Creates a list of vertices for a triangle and then returns the vertices as a mesh*/
	Mesh* InitilizeBoxMesh();

	//!InitilizeModel Function
	/*!Initializes the model that the square GameObject will use*/
	void InitilizeModel();

	//!Square GameObject pointer
	/*!Handle's how the square gameobject will be rendered*/
	GameObject* square;

	//!Model pointer
	/*!*/
	Model* model;
};

#endif

