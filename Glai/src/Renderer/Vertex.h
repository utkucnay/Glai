#pragma once
#include "EngineCore.h"
#include "Texture2D.h"
#include <glm/gtx/transform.hpp>

namespace Glai::Renderer
{
	struct Vertex
	{
		Vertex() = default;
		Vertex(const glm::vec3& pos, const glm::vec4& vertexColor, const glm::vec2& texCord) : pos(pos), vertexColor(vertexColor), texCord(texCord)  {}

		glm::vec3 pos;
		glm::vec4 vertexColor;
		glm::vec2 texCord;
	};

	struct Quad
	{
		Quad(int instanceCount = 0)
		{
			vertexs.at(0) = Vertex(glm::vec3(0.5, 0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(1, 1));
			vertexs.at(1) = Vertex(glm::vec3(0.5, -0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(0, 1));
			vertexs.at(2) = Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(0, 0));
			vertexs.at(3) = Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec4(1, 1, 1, 1), glm::vec2(1, 0));

			indices.at(0) = 0 + 4 * instanceCount;
			indices.at(1) = 1 + 4 * instanceCount;
			indices.at(2) = 3 + 4 * instanceCount;
			indices.at(3) = 1 + 4 * instanceCount;
			indices.at(4) = 2 + 4 * instanceCount;
			indices.at(5) = 3 + 4 * instanceCount;
		}



		Array<Vertex, 4>	vertexs;
		Array<int, 6>		indices;
	};

	struct InstancedVertex : Vertex
	{
		InstancedVertex(const glm::vec3& pos, const glm::vec4& vertexColor, const glm::vec2& texCord, const glm::mat4& model, const int& texID) :
			Vertex(pos, vertexColor, texCord), model(model), texID(texID) {}

		InstancedVertex(const Vertex& vertex, const glm::mat4& model, const int& texID) :
			Vertex(vertex), model(model), texID(texID) {}

		glm::mat4 model;
		int texID;
	};

	struct InstancedQuad
	{
		InstancedQuad() : count(0) {}
		Vector<InstancedVertex>	vertexs;
		int						count;
	};

	static void AddQuad(InstancedQuad* iQuad, const glm::mat4& model, int textureID = 0)
	{
		iQuad->vertexs.push_back(InstancedVertex(Vertex(glm::vec3(1, 1, 0), glm::vec4(1, 1, 1, 1), glm::vec2(1, 1)), model, textureID));
		iQuad->vertexs.push_back(InstancedVertex(Vertex(glm::vec3(1, -1, 0), glm::vec4(1, 1, 1, 1), glm::vec2(0, 1)), model, textureID));
		iQuad->vertexs.push_back(InstancedVertex(Vertex(glm::vec3(-1, -1, 0), glm::vec4(1, 1, 1, 1), glm::vec2(0, 0)), model, textureID));
		iQuad->vertexs.push_back(InstancedVertex(Vertex(glm::vec3(-1, 1, 0), glm::vec4(1, 1, 1, 1), glm::vec2(1, 0)), model, textureID));
	}
}