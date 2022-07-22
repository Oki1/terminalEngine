#include <Terminal.hpp>
#include <Rasterizer.hpp>
#include <vector>
#include <iostream>
#include <cstdio>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
typedef unsigned int uint;
int main() {
	Terminal t = Terminal();
	const static std::vector<float> vertices =
    {
                -0.5f,0.5f,-0.5f,
                -0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,-0.5f,
                0.5f,0.5f,-0.5f,
 
                -0.5f,0.5f,0.5f,
                -0.5f,-0.5f,0.5f,
                0.5f,-0.5f,0.5f,
                0.5f,0.5f,0.5f,
 
                0.5f,0.5f,-0.5f,
                0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,0.5f,
                0.5f,0.5f,0.5f,
 
                -0.5f,0.5f,-0.5f,
                -0.5f,-0.5f,-0.5f,
                -0.5f,-0.5f,0.5f,
                -0.5f,0.5f,0.5f,
 
                -0.5f,0.5f,0.5f,
                -0.5f,0.5f,-0.5f,
                0.5f,0.5f,-0.5f,
                0.5f,0.5f,0.5f,
 
                -0.5f,-0.5f,0.5f,
                -0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,0.5f
    };
	const static std::vector<float> indices =
    {
                0,1,3,
                3,1,2,
                4,5,7,
                7,5,6,
                8,9,11,
                11,9,10,
                12,13,15,
                15,13,14,
                16,17,19,
                19,17,18,
                20,21,23,
                23,21,22
    };

	std::vector<glm::vec3> cubeIndices;
	for(uint x = 0; x < indices.size(); x+=3) {
		cubeIndices.push_back(glm::vec3(indices[x], indices[x+1], indices[x+2]));
	}
	std::vector<glm::vec4> cubeVertices;
	for(uint x = 0; x < vertices.size(); x+=3) {
		cubeVertices.push_back(glm::vec4(vertices[x], vertices[x+1], vertices[x+2], 1.0f));
	}


	glm::vec3 cameraPosition(7, -7, 5);
	

	glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);

    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	view *= glm::lookAt(cameraPosition, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 projection = glm::perspective(glm::radians(75.0f), (float)((float)t.screenWidth)/((float)t.screenHeight), 0.01f, 100.0f);


	for(int x = 0; x < cubeVertices.size(); x++) {
		cubeVertices[x] = glm::vec4(projection*view*model*cubeVertices[x]);
	}

	t.ClearBuffer(' ');
    //rast::DrawLine(t, {5, 5}, {30, 30}, '@');
    rast::DrawTriangle(t, {5,10}, {5,5}, {10,5},'#');
    rast::DrawTriangle(t, {5,10}, {10,10}, {10,5},'@');
    t.DrawFrame();
    getc(stdin);
}