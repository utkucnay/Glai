#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in int texID;
layout (location = 4) in vec4 iModel0;
layout (location = 5) in vec4 iModel1;
layout (location = 6) in vec4 iModel2;
layout (location = 7) in vec4 iModel3;

out vec4 ourColor;
out vec2 TexCoord;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    mat4 iModel = mat4(iModel0,iModel1,iModel2, iModel3);
    gl_Position = projection * view * iModel * vec4(aPos, 1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
};