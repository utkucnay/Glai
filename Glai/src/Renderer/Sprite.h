#pragma once

#include "Vertex.h"
#include "Shader/Shader.h"
#include "Material/Material.h"

namespace Glai::Renderer
{
	class BatchSprite
	{
	public:
		BatchSprite();

	public:
		void Draw();
		void AddSprite() { AddQuad(&iQuad); }
		void RemoveSprite() {  }

	public:
		InstancedQuad iQuad;
		Ref<Material::Material>	material;

	private:
		int						vectorLimit = 1000;
		unsigned int			VAO;
		//int* indices;
	};
}