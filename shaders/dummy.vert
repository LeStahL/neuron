#version 460 core

out vec3 gl_Position;
in vec3 position;

void main()
{
    gl_Position = position;
}