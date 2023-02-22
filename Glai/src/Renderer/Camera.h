#pragma once

#include "Window.h"
#include <glm/gtx/transform.hpp>

namespace Glai::Renderer
{
	class Camera
	{
	public:
		virtual const glm::mat4& GetViewMat() = 0;
		virtual const glm::mat4& GetProjMat() = 0;
	};

	class OrtographicCamera : public Camera
	{
	public:
		OrtographicCamera(Window* window) {
			this->window = window;
			auto WinSize = window->GetWindowSize();
			view = glm::mat4(1.0f);
			view = glm::translate(view, glm::vec3(0, 0, -3.0f));
			projection = glm::ortho(0.0f, (float)WinSize.width, 0.0f, (float)WinSize.height, 0.1f, 300.0f);
		}

	public:
		const glm::mat4& GetViewMat() override { return view; }
		const glm::mat4& GetProjMat() override { UpdateProjection(); return projection;}

		void UpdateProjection()
		{
			auto WinSize = window->GetWindowSize();
			float hWidth = 16 / 2.0f * cameraSize;
			float hHeight = 9 / 2.0f * cameraSize;
			projection = glm::ortho(-hWidth, hWidth , -hHeight, hHeight, 0.1f, 300.0f);
		}

	private:
		Window* window;
		glm::mat4 view;
		glm::mat4 projection;
		float cameraSize = 5;
	};


}