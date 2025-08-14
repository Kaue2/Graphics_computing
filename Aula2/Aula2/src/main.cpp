#include <iostream>
#include <GL/glew.h>
#include <GLFW//glfw3.h>

using namespace std;

const GLint WIDTH = 800, HEIGHT = 600;

int main() {
	// inicando GLFW
	if (!glfwInit()) {
		cout << "Erro: GLFW n�o foi iniciado";
		glfwTerminate();
		return -1;
	}

	// set nas coisas obrigat�rias para subir uma janela
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // vers�o m�xima permitida 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // vers�o m�nima
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // somente as fun��es core
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // qual a precis�o de ponto flutuante que vamos usar, precis�o da placa

	// cria��o de janela 
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
	if (!window) {
		cout << "Erro: N�o foi poss�vel criar a janela";
		glfwTerminate();
		return -1;
	}

	// guardando o tamanho real da minha tela 
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

	glfwMakeContextCurrent(window); // tornando essa janela como principal

	//iniciando o Glew
	glewExperimental = GLU_TRUE;
	if (glewInit() != GLEW_OK) {
		cout << "Erro: n�o foi poss�vel iniciar o glew";
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, bufferWidth, bufferHeight);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}