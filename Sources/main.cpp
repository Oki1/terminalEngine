#include <Headers/Terminal.hpp>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
int main() {
	std::vector<glm::vec4> cubeVertices = {
		glm::vec4(1.0, 1.0, 1.0f, 1.0f),
		glm::vec4(-1.0f, 1.0f, 1.0, 1.0f),
		glm::vec4(-1.0f,-1.0f, 1.0, 1.0f),
		glm::vec4( 1.0f,-1.0f, 1.0, 1.0f),
		glm::vec4(1.0f,-1.0f,-1.0, 1.0f),
		glm::vec4(1.0f, 1.0f,-1.0, 1.0f),
		glm::vec4(-1.0f, 1.0f,-1.0, 1.0f),
		glm::vec4(-1.0f,-1.0f,-1.0f, 1.0f)};

	glm::vec3 cameraPosition(7, -7, 5);
	

	glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);

    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	view *= glm::LookAt(cameraPosition, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	projection = glm::perspective(glm::radians(75.0f), 800.0f / 600.0f, 0.1f, 100.0f);




	for(int x = 0; x < cubeVertices.size(); x++) {
		cubeVertices[x] = glm::vec4(projection*view*model*cubeVertices[x]);
	}
}