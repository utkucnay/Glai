#pragma once

#include "EngineCore.h"

namespace Glai
{
	class Window
	{
	public:
		struct WindowSize
		{
			int width, height;
		};
	public:
		Window(int width, int height,const std::string& title, GLFWmonitor* monitor, GLFWwindow* share)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			data = glfwCreateWindow(width, height, title.c_str(), monitor, share);

			glfwSetWindowSizeCallback(data, [](GLFWwindow* window, int width, int height)
				{
					glViewport(0, 0, width, height);
				});
		}

		const WindowSize& GetWindowSize() 
		{
			glfwGetWindowSize(data, &windowSize.width, &windowSize.height);
			return windowSize;
		}

	public:
		GLFWwindow* data;
		WindowSize windowSize;
	};
}