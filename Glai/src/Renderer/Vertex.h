#pragma once
#include "EngineCore.h"
#include "Texture2D.h"

namespace Glai::Renderer
{
	struct Vertex
	{
		Vertex() = default;
		Vertex(glm::vec3 pos, glm::vec4 vertexColor, glm::vec2 texCord) : pos(pos), vertexColor(vertexColor), texCord(texCord)  {}

		glm::vec3 pos;
		glm::vec4 vertexColor;
		glm::vec2 texCord;
	};

	struct Quad
	{
		Quad()
		{
			vertexs.at(0) = Vertex(glm::vec3(0.5, 0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(1, 1));
			vertexs.at(1) = Vertex(glm::vec3(0.5, -0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(0, 1));
			vertexs.at(2) = Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(0, 0));
			vertexs.at(3) = Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(1, 0));

			indices.at(0) = 0;
			indices.at(1) = 1;
			indices.at(2) = 3;
			indices.at(3) = 1;
			indices.at(4) = 2;
			indices.at(5) = 3;
		}
		Array<Vertex, 4> vertexs;
		Array<int, 6> indices;
	};
}