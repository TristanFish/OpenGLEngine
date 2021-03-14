#include "Mesh.h"
#include "Core/CoreEngine.h"

Mesh::Mesh(SubMesh& subMesh_, GLuint shaderProgram_) : VAO(0), VBO(0),
shaderProgram(0), viewLoc(0), projectionLoc(0),textureLoc(0)
{
	subMesh = subMesh_;
	shaderProgram = shaderProgram_;
	GenerateBuffers();
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	if (subMesh.vertexList.size() > 0) {
		subMesh.vertexList.clear();
	}

	if (subMesh.meshIndices.size() > 0) {
		subMesh.meshIndices.clear();
	}

}

void Mesh::Render(Camera* camera_, std::vector<glm::mat4>& instances_)
{
	glUniform1i(textureLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, subMesh.textureID);


	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetView()));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetPerspective()));

	glUniform3fv(posLoc, 1, glm::value_ptr(CoreEngine::GetInstance()->GetCamera()->GetPosition()));

	glUniform1i(lightsInGameLoc, CoreEngine::GetInstance()->GetCamera()->GetLightSources().size());


	for (int i = 0; i < CoreEngine::GetInstance()->GetCamera()->GetLightSources().size(); i++)
	{
		std::string index = "light[" + std::to_string(i) + "]";

		lightPosLoc = glGetUniformLocation(shaderProgram, (index + ".position").c_str());
		glUniform3fv(lightPosLoc, 1, glm::value_ptr(CoreEngine::GetInstance()->GetCamera()->GetLightSources()[i]->GetPosition()));

		lightColLoc = glGetUniformLocation(shaderProgram, (index + ".colour").c_str());
		glUniform3fv(lightColLoc, 1, glm::value_ptr(CoreEngine::GetInstance()->GetCamera()->GetLightSources()[i]->GetColour()));

		lightAmbLoc = glGetUniformLocation(shaderProgram, (index + ".ambient").c_str());
		glUniform1f(lightAmbLoc, CoreEngine::GetInstance()->GetCamera()->GetLightSources()[i]->GetAmbient());

		lightDiffLoc = glGetUniformLocation(shaderProgram, (index + ".diffuse").c_str());
		glUniform1f(lightDiffLoc, CoreEngine::GetInstance()->GetCamera()->GetLightSources()[i]->GetDiffuse());

		lightSpecLoc = glGetUniformLocation(shaderProgram, (index + ".specular").c_str());
		glUniform1f(lightSpecLoc, CoreEngine::GetInstance()->GetCamera()->GetLightSources()[i]->GetSpecular());

		
	}

	


	glBindVertexArray(VAO);

	glEnable(GL_DEPTH_TEST);

	for (int i = 0; i < instances_.size(); i++)
	{
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances_[i]));

		glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());
	}

	

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Mesh::GenerateBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, subMesh.vertexList.size() * sizeof(Vertex), &subMesh.vertexList[0], GL_STATIC_DRAW);

	//Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	//Normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	//Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoordinates));

	//Colour
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	modelLoc = glGetUniformLocation(shaderProgram, "model");
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	textureLoc = glGetUniformLocation(shaderProgram, "meshTexture");

	posLoc = glGetUniformLocation(shaderProgram, "viewPosition");
	
	lightsInGameLoc = glGetUniformLocation(shaderProgram, "lightsInGame");


}
