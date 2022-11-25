#pragma once
const char* VertexShaderSource = R"(
#version 330 core
in vec3 coord;
in vec4 color;
out vec4 vcolor;
uniform mat4 affine;
uniform mat4 proj;
void main() {
    gl_Position = proj * affine * vec4(coord / 2, 1.0);
    vcolor = color;
}
)";

const char* FragShaderSource = R"(
#version 330 core
in vec4 vcolor;
void main() {
    gl_FragColor = vcolor;
}
)";