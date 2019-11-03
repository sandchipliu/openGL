
#include <iostream>
#include "Window.h"
#include "Program.h"
#include "Shader.h"
#include "Vertex.h"
#include "Texture.h"
#include "Camera.h"
#include "Light.h"
#include "Cube.h"
#include "Plane.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Program *program;
Camera *camera;
Light *light;
Cube *cube;

void update()
{
	program->use();
	cube->update();
}

int main(int argc,char* argv[])
{
	Window win;
    program = new Program();
	
	glEnable(GL_DEPTH_TEST);
	Shader vShader(GL_VERTEX_SHADER,"./Shader.vs");
	Shader fShader(GL_FRAGMENT_SHADER,"./Shader.fs");
	program->attachShader(vShader.getID());
	program->attachShader(fShader.getID());
	program->use();
	
	program->link();
	vShader.clear();
	fShader.clear();

	light = new Light(program);
	cube = new Cube(program);
	
	camera = new Camera(program,glm::vec3(0.0f,0.0f,-3.0f));
	camera->Perspective(glm::radians(45.0f), (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 100.0f);
	
	glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
	glm::vec3 toyColor(1.0f, 0.5f, 0.31f);
	// glm::vec3 result = glm::dot(lightColor,toyColor);
	float a = glm::dot(lightColor,toyColor);

	std::cout << a << std::endl;
	// std::cout << result.x << " " << result.y << " " << result.z << std::endl;

	win.update(update);
	return 0;
}


