#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"
#include "Audio.h"
#include "Overlay.h"

enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
	void playAudio(unsigned int Source, glm::vec3 pos);
	glm::vec3 GetNormal();
	void blobEffect();
	void setADSLighting();
	void setToonLighting();
	void setRimShader();
	void setGeoShader();
	void setEMapShader();
	void setReflectShader();
	void setGeometryShader();
	void setExtensionShader();

	void Skybox();

	GLuint skyboxVAO, skyboxVBO, cubemapTexture;
	GLuint cubeVAO, cubeVBO;
	vector<std::string> faces;

	Display _gameDisplay;
	GameState _gameState;
	Mesh mesh1;
	Mesh mesh2;
	Mesh mesh3;

	Texture texture;
	Texture texture1;
	Texture skybox;

	Overlay overlay;
	Shader shaderPass;
	Shader shaderBlur;
	Shader shaderToon;
	Shader shaderRim;
	Shader shaderGeo;
	Shader shaderSkybox;
	Shader shaderEMap;
	Shader shaderReflect;
	Shader shaderGeometry;
	Shader shaderExtension;

	glm::mat4 modelView;

	Camera myCamera;
	Audio audioDevice;

	float counter;
	unsigned int whistle;
	unsigned int backGroundMusic;
};

