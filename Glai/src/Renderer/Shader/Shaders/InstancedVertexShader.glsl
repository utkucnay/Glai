#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in mat4 iModel;
layout (location = 4) in int texID;

out vec3 ourColor;
out vec2 TexCoord;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position =  vec4(aPos, 1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
};