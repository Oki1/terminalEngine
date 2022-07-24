#include <Terminal.hpp>
#include <Rasterizer.hpp>
#include <vector>
#include <iostream>
#include <cstdio>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

typedef unsigned int uint;
int main() {
    /*
	Terminal t = Terminal();
	const static std::vector<float> vertices =
    {
                -0.5f,-0.5f,+0.5f,
                +0.5f,-0.5f,+0.5f,
                -0.5f,+0.5f,+0.5f,
                +0.5f,+0.5f,+0.5f,

                -0.5f,-0.5f,-0.5f,
                +0.5f,-0.5f,-0.5f,
                -0.5f,+0.5f,-0.5f,
                +0.5f,+0.5f,-0.5f,
    };
	const static std::vector<float> indices =
    {
                0,2,3,
                0,1,3,
                2,6,7,
                2,3,7,
                1,3,5,
                3,5,7,
                6,7,4,
                6,7,5,
                2,6,4,
                2,4,0,
                0,1,5,
                0,5,4
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

    float rotation = 10.0f;

    for(int x = 0; x < 60; x++) {
        model = glm::rotate(model, glm::degrees(rotation), glm::vec3(1.0f,0.0f,1.0f));
        
        for(int x = 0; x < cubeVertices.size(); x++) {
            cubeVertices[x] = glm::vec4(projection*view*model*cubeVertices[x]);
            cubeVertices[x].x = (cubeVertices[x].x+1.0f)/2.0f;
            cubeVertices[x].y = (cubeVertices[x].y+1.0f)/2.0f;
        }
        t.ClearBuffer('.');
        for(unsigned int x = 0; x < indices.size(); x+=3) {
            glm::vec4 a = cubeVertices[indices[x]];
            glm::vec4 b = cubeVertices[indices[x+1]];
            glm::vec4 c = cubeVertices[indices[x+2]];
            rast::DrawTriangleScreenCoordinates(t, rast::vec2f(a.x, a.y), rast::vec2f(b.x, b.y), rast::vec2f(c.x, c.y), '@');
        }
        t.DrawFrame();

        auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(500s);
    }*/
    for(int x = 0; x < 120; x++) {
        std::cout << "Hello " << std::flush;
        std::this_thread::sleep_for(200ms);
        std::cout << "World!" << std::endl;
        std::this_thread::sleep_for(200ms);
    }
}