#pragma once
#include "Frame.h"

namespace Glai
{
	class Engine
	{
	public:
		Engine() = default;
		~Engine();

	public:
		void EngineStart();
		void EngineUpdate();
		void EngineOnEnd();
		bool&& IsEngineWindowClosed() const;

	private:
		Singleton<Frame> frame;
		GLFWwindow* window;
	};
}