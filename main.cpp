
#include <iostream>
#include "Window.h"
#include "Program.h"
#include "Shader.h"
#include "Vertex.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

GLfloat vertices[]={
	//位置                  // 颜色                 //纹理坐标
  	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
};

GLuint indices[]={
	0,1,3,
	1,2,3
};

Program *program;
Vertex *vertex;
Texture *texture0;
Texture *texture1;
glm::mat4 view;
glm::mat4 projection;

void loop()
{
	program->use();
	texture0->activeTexure();
	texture1->activeTexure();
	glm::mat4 model;
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
	program->setMat4("model", glm::value_ptr(model));
	program->setMat4("view", glm::value_ptr(view));
	program->setMat4("projection", glm::value_ptr(projection));
	// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(vertex->getVAO());
	glDrawArrays(GL_TRIANGLES,0,36);
}

int main(int argc,char* argv[])
{
	Window win;
    program = new Program();
    vertex = new Vertex(vertices,180);
	
	glEnable(GL_DEPTH_TEST);
	Shader vShader(GL_VERTEX_SHADER,"./Shader.vs");
	Shader fShader(GL_FRAGMENT_SHADER,"./Shader.fs");
	program->attachShader(vShader.getID());
	program->attachShader(fShader.getID());
	program->use();
	
	program->link();
	vShader.clear();
	fShader.clear();
	
	vertex->addVAO(1);
	vertex->addVBO(1);
	vertex->setAttrib(0,3,5*sizeof(GLfloat),(void*)0);
	vertex->setAttrib(1,2,5*sizeof(GLfloat),(void*)(3 * sizeof(float)));

	texture0 = new Texture(GL_TEXTURE0);
	texture0->loadTexture("./beauty.jpg");
	texture1 = new Texture(GL_TEXTURE1);
	texture1->loadTexture("./1.png");

	program->use();
	program->setInt("texture1",0);
	program->setInt("texture2",1);
	// program->setFloat("factor",0.5);

	glm::vec4 vec(2.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3(1.0f, 3.0f, 0.0f));  //从这里就能看出单位矩阵的作用了。初始化的trans是一个单位矩阵，让它平移到(1.0f, 1.0f, 0.0f)的位置产生了一个平移矩阵。
	vec = trans * vec;
	std::cout << "(" << vec.x << "," << vec.y << "," << vec.z << ")" << std::endl;

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 100.0f);

	win.loop(loop);
	return 0;
}

