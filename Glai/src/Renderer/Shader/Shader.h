#pragma once

namespace Glai::Renderer::Shader
{
	class Shader
	{
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
    public:
        void Use();

        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
        void setMat4(const std::string& name, glm::mat4 value) const;

    public:
        unsigned int ID;
        std::string name;
        int nameHash;
	};
}