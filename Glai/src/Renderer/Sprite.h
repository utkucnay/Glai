#pragma once

#include "Vertex.h"
#include "Shader/Shader.h"
#include "Material/Material.h"

namespace Glai::Renderer
{
	class Sprite
	{
	public:
		Sprite();

	public:
		void Draw();
		void AddSprite() { AddQuad(&iQuad); }

	public:
		InstancedQuad iQuad;
		Ref<Material::Material>	material;

	private:
		int						vectorLimit = 1000;
		unsigned int			VAO;
	};
}