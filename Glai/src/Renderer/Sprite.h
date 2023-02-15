#pragma once

#include "Vertex.h"
#include "Shader/Shader.h"
#include "Material/Material.h"
#include "Renderer/Camera.h"

namespace Glai::Renderer
{
	class BatchSprite
	{
	public:
		BatchSprite();

	public:
		void Draw(OrtographicCamera* camera);
		void AddSprite() { AddQuad(&iQuad); }
		void RemoveSprite() { iQuad.vertexs.clear(); }

	public:
		InstancedQuad iQuad;
		Ref<Material::Material>	material;

	private:
		int						vectorLimit = 1000;
		unsigned int			VAO;
	};
}