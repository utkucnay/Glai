#include "Sprite.h"
#include <glm/gtx/transform.hpp>
#include "Camera.h"

Glai::Renderer::BatchSpriteSystem::BatchSpriteSystem()
{
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glBufferData(GL_ARRAY_BUFFER, vectorLimit * sizeof(Glai::Renderer::InstancedVertex), NULL, GL_DYNAMIC_DRAW);
	
	const int indicesLimit = vectorLimit * 3 / 2;

	int *indices = new int[indicesLimit];
	{
		int offset = 0;

		for (int i = 0; i < indicesLimit; i += 6)
		{
			indices[i + 0] = 0 + offset;
			indices[i + 1] = 1 + offset;
			indices[i + 2] = 3 + offset;
			indices[i + 3] = 1 + offset;
			indices[i + 4] = 2 + offset;
			indices[i + 5] = 3 + offset;

			offset += 4;
		}
	}

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesLimit * sizeof(int), indices, GL_STATIC_DRAW);

	auto vec4Size = sizeof(glm::vec4);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::pos));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::vertexColor));
	
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::texCord));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 1, GL_INT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::texID));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::model));

	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)(offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::model) + vec4Size));

	glEnableVertexAttribArray(6);
	glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)(offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::model) + vec4Size * 2));

	glEnableVertexAttribArray(7);
	glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)(offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::model) + vec4Size * 3));

	glBindVertexArray(NULL);

	material = CreateRef<Material::Material>();
	material->shader = CreateRef<Shader::Shader>();
	material->shader->CreateShader("c:/dev/Glai/Glai/src/Renderer/Shader/Shaders/InstancedVertexShader.glsl", "c:/dev/Glai/Glai/src/Renderer/Shader/Shaders/InstancedFragmentShader.glsl");
}

void Glai::Renderer::BatchSpriteSystem::Draw(Ref<Camera> camera)
{
	//shader Stuff
	material->shader->Use();
	auto& shader = material->shader;
	shader->setMat4("projection", camera->GetProjMat());
	shader->setMat4("view", camera->GetViewMat());

	glBindVertexArray(VAO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, iQuad.vertexs.size() * sizeof(Renderer::InstancedVertex), iQuad.vertexs.data());
	int amount = iQuad.vertexs.size() / 4;
	glDrawElementsInstanced(GL_TRIANGLES, amount * 6, GL_UNSIGNED_INT, 0, amount);
	glBindVertexArray(NULL);
}
