#include "Engine.h"

#include "Thread/ThreadSystem.h"
#include "Thread/JobSystem.h"

#include "Renderer/Shader/Shader.h"
#include "Renderer/Material/Material.h"
#include <glm/gtx/transform.hpp>

#include "Renderer/Sprite.h"

Glai::Engine::~Engine()
{
}

Glai::Renderer::BatchSprite* sprite;

void Glai::Engine::EngineStart()
{
	ENG_CORE_LOG("Engine Start")

	if (glfwInit() == GLFW_FALSE) 
	{
		ENG_CORE_ASSERT("GLFW Don't Init")
	}

	window = new Window(800, 600, "Glai", NULL, NULL);

	glfwMakeContextCurrent(window->data);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ENG_CORE_ASSERT("Glad Don't Init")
	}

	glViewport(0, 0, 800, 600);

	Singleton<JobSystem::ThreadSystem> threadInit();
	Singleton<JobSystem::JobSystem> jobInit();

	sprite = new Renderer::BatchSprite();

	sprite->AddSprite();

}

void Glai::Engine::EngineUpdate()
{

	//Frame Phases
	frame->FrameInit();
	frame->FramePhase1();
	frame->FramePhase2();
	frame->FramePhase3();

	glClearColor(0, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	sprite->Draw();

	glfwSwapBuffers(window->data);
	glfwPollEvents();
}

void Glai::Engine::EngineOnEnd()
{
	glfwTerminate();
}

bool Glai::Engine::IsEngineWindowClosed()
{
	return glfwWindowShouldClose(window->data);
}

