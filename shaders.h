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

const char* TexVShader = R"(
in vec3 position;
in vec3 color;
in vec2 texCoord;
out vec3 ourColor;
out vec2 TexCoord;
void main() {
    gl_Position = vec4(position, 1.0f);
    ourColor = color;
    TexCoord = texCoord
})";

const char* TexColorFshader = R"(
in vec3 ourColor;
in vec2 TexCoord;
out vec4 color;
uniform sampler2D ourTexture;
uniform float mixValue;
void main() {
     color = mix(texture(ourTexture, TexCoord), vec4(ourColor, 1.0f), mixValue);
})";

const char* TexTextureFshader = R"(
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform float mixValue;
void main(){
    color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), mixValue);
})";