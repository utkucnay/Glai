#pragma once
#include "Frame.h"
#include "Renderer/Vertex.h"
#include "Window.h"

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
		bool IsEngineWindowClosed();

	private:
		Singleton<Frame> frame;
		Window* window;
	};
}