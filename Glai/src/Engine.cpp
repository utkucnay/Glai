#include "Engine.h"

#include "Thread/ThreadSystem.h"
#include "Thread/JobSystem.h"

#include "Renderer/Shader/Shader.h"
#include <glm/gtx/transform.hpp>

Glai::Engine::~Engine()
{
}

unsigned int VAO;
Glai::Renderer::Shader::Shader* shader;

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

	Glai::Renderer::Quad quad;

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glBufferData(GL_ARRAY_BUFFER, quad.vertexs.size() * sizeof(Glai::Renderer::Vertex), quad.vertexs.data(), GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, quad.indices.size() * sizeof(int), quad.indices.data(), GL_STATIC_DRAW);

	shader = new Renderer::Shader::Shader("C:/Dev/Glai/Glai/src/Renderer/Shader/Shaders/VertexShader.glsl", "C:/Dev/Glai/Glai/src/Renderer/Shader/Shaders/FragmentShader.glsl");

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::Vertex), (void*)offsetof(Glai::Renderer::Vertex, Glai::Renderer::Vertex::pos));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::Vertex), (void*)offsetof(Glai::Renderer::Vertex, Glai::Renderer::Vertex::vertexColor));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::Vertex), (void*)offsetof(Glai::Renderer::Vertex, Glai::Renderer::Vertex::texCord));
	glEnableVertexAttribArray(2);
	
	glBindVertexArray(NULL);
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

	shader->Use();


	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(500, 500, 1));


	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(500, 500, -5.0f));

	shader->setMat4("model", model);
	shader->setMat4("projection", projection);
	shader->setMat4("view", view);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(NULL);


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

