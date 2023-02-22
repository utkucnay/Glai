#pragma once

#include "Vertex.h"
#include "Shader/Shader.h"
#include "Material/Material.h"
#include "Renderer/Camera.h"

namespace Glai::Renderer
{
	class BatchSpriteSystem
	{
	public:
		BatchSpriteSystem();

	public:
		void Draw(Ref<Camera> camera);
		void AddSprite(const glm::mat4& model, const int& textureID = 0) { AddQuad(&iQuad, model, textureID); }
		void RemoveAllSprite() { iQuad.vertexs.clear(); }

	public:
		InstancedQuad iQuad;
		Ref<Material::Material>	material;

	private:
		int						vectorLimit = 1000;
		unsigned int			VAO;
	};
}