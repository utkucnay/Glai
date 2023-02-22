#include "Engine.h"

#include "Thread/ThreadSystem.h"
#include "Thread/JobSystem.h"

#include "Renderer/Shader/Shader.h"
#include "Renderer/Material/Material.h"
#include <glm/gtx/transform.hpp>

#include "Renderer/Sprite.h"
#include "Renderer/Camera.h"

Glai::Engine::~Engine()
{
}

Glai::Renderer::BatchSpriteSystem* BatchSprite;
Glai::Ref<Glai::Renderer::Camera> camera;

void Glai::Engine::EngineStart()
{
	ENG_CORE_LOG("Engine Start")

	if (glfwInit() == GLFW_FALSE) 
	{
		ENG_CORE_ASSERT("GLFW Don't Init")
	}

	window = new Window(1280, 720, "Glai", NULL, NULL);

	glfwMakeContextCurrent(window->data);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ENG_CORE_ASSERT("Glad Don't Init")
	}

	glViewport(0, 0, 1280, 720);

	Singleton<JobSystem::ThreadSystem> threadInit();
	Singleton<JobSystem::JobSystem> jobInit();

	BatchSprite = new Renderer::BatchSpriteSystem();

	camera = CreateRef<Renderer::OrtographicCamera>(window);
}

void Glai::Engine::EngineUpdate()
{

	//Frame Phases
	frame->FrameInit();
	frame->FramePhase1();
	frame->FramePhase2();
	frame->FramePhase3();
	
	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(30, 0, 0));
	BatchSprite->AddSprite(model);

	BatchSprite->Draw(camera);

	glfwSwapBuffers(window->data);

	glClearColor(0, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	BatchSprite->RemoveAllSprite();

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

