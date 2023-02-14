#pragma once

namespace Glai::Renderer::Material
{
	class Material
	{
	public:
		Material() = default;
		Material(Ref<Shader::Shader> shader) : shader(shader) {}

	public:
		Ref<Shader::Shader> shader;
	};
}