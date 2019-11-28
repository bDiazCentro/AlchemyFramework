/*
	Nombre: Alchemy Framework
	Año: 2019
	Version: 1.0.0
	Autor: Bruno Díaz
	Steam Lab
*/

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>	
#include "Application.hpp"

const int WIDTH = 1280;
const int HEIGHT = 960;

void RunApp(Application *app){}

int main() {
	try {	
		RunApp(new Application());
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}