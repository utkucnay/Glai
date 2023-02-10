#include "Engine.h"

#include "Thread/ThreadSystem.h"
#include "Thread/JobSystem.h"

Engine::Engine::~Engine()
{
}

void Engine::Engine::EngineStart()
{
	ENG_CORE_LOG("Engine Start")

	if (glfwInit() == GLFW_FALSE) 
	{
		ENG_CORE_ASSERT("GLFW Don't Init")
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(800, 600, "Chess", NULL, NULL);

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ENG_CORE_ASSERT("Glad Don't Init")
	}

	glViewport(0, 0, 800, 600);

	Singleton<JobSystem::ThreadSystem> threadInit();
	Singleton<JobSystem::JobSystem> jobInit();
}

void Engine::Engine::EngineUpdate()
{
	glfwPollEvents();

	//Frame Phases
	frame->FrameInit();
	frame->FramePhase1();
	frame->FramePhase2();
	frame->FramePhase3();

	glfwSwapBuffers(window);
}

void Engine::Engine::EngineOnEnd()
{
	glfwTerminate();
}

bool&& Engine::Engine::IsEngineWindowClosed() const
{
	return std::move(!glfwWindowShouldClose(window));
}