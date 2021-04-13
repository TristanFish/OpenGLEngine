#include "MTLoader.h"

MTLoader::~MTLoader()
{

}

void MTLoader::LoadMaterial(std::string filePath_)
{
	std::ifstream in(filePath_.c_str(), std::ios::in);
	if (!in)
	{
		Debug::Error("Cannot open MTL file: " + filePath_, "MaterialLoader.cpp", __LINE__);
		return;
	}

	Material m = Material();
	std::string matName = "";
	std::string line;

	while (std::getline(in, line)) {

		if (line.substr(0, 7) == "newmtl ") {
			if (m.diffuseMap != 0) {

				MaterialHandler::GetInstance()->AddMaterial(m);
				m = Material();
			}
			matName = line.substr(7);
			m.diffuseMap = LoadTexture(matName);
			m.name = matName;
		}

		if (line.substr(0, 4) == "\tKd ") {
			
			std::stringstream f_1(line.substr(5));
			f_1 >> m.diffuse.x >> m.diffuse.y >> m.diffuse.z;
		}
		if (line.substr(0, 4) == "\tKs ") {

			std::stringstream f_1(line.substr(5));
			f_1 >> m.specular.x >> m.specular.y >> m.specular.z;
		}
		if (line.substr(0, 4) == "\tKa ") {

			std::stringstream f_1(line.substr(5));
			f_1 >> m.ambient.x >> m.ambient.y >> m.ambient.z;
		}
		if (line.substr(0, 4) == "\td ") {

			std::stringstream f_1(line.substr(4));
			f_1 >> m.transparency;
		}
		if (line.substr(0, 4) == "\tNs ") {

			std::stringstream f_1(line.substr(4));
			f_1 >> m.shininess;
		}
	}

	if (m.diffuseMap != 0) {
		MaterialHandler::GetInstance()->AddMaterial(m);
	}

	in.close();
}

GLuint MTLoader::LoadTexture(std::string fileName_)
{
	GLuint currentTexture = TextureHandler::GetInstance()->GetTexture(fileName_);
	if (currentTexture == 0) {

		TextureHandler::GetInstance()->CreateTexture(fileName_, "./Resources/Textures/" + fileName_ + ".png");
		currentTexture = TextureHandler::GetInstance()->GetTexture(fileName_);
	}
	return currentTexture;
}
