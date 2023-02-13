#pragma once

#include "EngineCore.h"

namespace Glai
{
	class Window
	{
	public:
		Window(int width, int height,const std::string& title, GLFWmonitor* monitor, GLFWwindow* share)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			data = glfwCreateWindow(width, height, title.c_str(), monitor, share);

			this->width = width;
			this->height = height;

			glfwSetWindowSizeCallback(data, [](GLFWwindow* window, int width, int height)
				{
					glViewport(0, 0, width, height);
				});
		}

	public:
		GLFWwindow* data;
		int width, height;
	};
}