#include "Sprite.h"
#include <glm/gtx/transform.hpp>

Glai::Renderer::BatchSprite::BatchSprite()
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

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::pos));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::vertexColor));
	
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::texCord));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 16, GL_FLOAT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::model));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 1, GL_INT, GL_FALSE, sizeof(Glai::Renderer::InstancedVertex), (void*)offsetof(Glai::Renderer::InstancedVertex, Glai::Renderer::InstancedVertex::texID));

	glBindVertexArray(NULL);

	material = CreateRef<Material::Material>();
	material->shader = CreateRef<Shader::Shader>();
	material->shader->CreateShader("c:/dev/Glai/Glai/src/Renderer/Shader/Shaders/InstancedVertexShader.glsl", "../../Glai/Glai/src/Renderer/Shader/Shaders/InstancedFragmentShader.glsl");
}

void Glai::Renderer::BatchSprite::Draw()
{


	//shader Stuff
	material->shader->Use();
	auto& shader = material->shader;

	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(500, 500, -5.0f));

	shader->setMat4("projection", projection);
	shader->setMat4("view", view);

	glBindVertexArray(VAO);
	
	glBufferSubData(GL_ARRAY_BUFFER, 0, iQuad.vertexs.size() * sizeof(Renderer::InstancedVertex), iQuad.vertexs.data());

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(NULL);
}
