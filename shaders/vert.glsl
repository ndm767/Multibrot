#version 330 core

layout(location = 0) in vec3 pos;

out vec3 fPos;

void main() {
    fPos = pos;
    gl_Position = vec4(pos, 1.0);
}