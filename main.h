#pragma once
#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <corecrt_math_defines.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// ID ��������� ���������
GLuint Program;
// ID ��������
GLint Attrib_vertex;
GLint Attrib_color;
GLint Attrib_tex_coord;
GLint Uniform_proj;
GLint Uniform_affine;
GLint Uniform_texture1;
GLint Uniform_texture2;
GLint Uniform_mix_value;
// ID ���������� ������
GLuint VBO;

// ������� ������� ��������������
glm::mat4 affine;
// ������� ��������
glm::mat4 proj;

GLfloat tex_ratio = 0.5f;

// ��������� ��� �������� ������
struct Vertex
{
	//coords
	GLfloat x;
	GLfloat y;
	GLfloat z;

	//colors
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;

	// texture coords
	GLfloat s;
	GLfloat t;
};

// ������� ��� ��������� ������ ����������
void SetIcon(sf::Window& wnd);
// ������� ��� �������� ������
void checkOpenGLerror();
//
void ShaderLog(unsigned int shader);
// ������� ��� �������� ��������
void InitShader();
// ������� ��� ������������� ���������� ������
void InitVBO();
// ������� ��� ������������� ��������
void Init();
// ������� ��� ���������
void Draw(sf::Window& window);
// ������� ��� ������� ��������
void ReleaseShader();
// ������� ��� ������� ���������� ������
void ReleaseVBO();
// ������� ��� ������� ��������
void Release();

enum class ShapeType {
	Gradient_Tetrahedron = 0,
	Gradient_Texture_Cube,
	Double_Texture_Cube,
	Gradient_Pie
};

#define red    1.0, 0.0, 0.0, 1.0
#define green  0.0, 1.0, 0.0, 1.0
#define blue   0.0, 0.0, 1.0, 1.0
#define yellow 1.0, 1.0, 0.3, 1.0
#define orange 1.0, 0.5, 0.0, 1.0
#define violet 0.5, 0.0, 1.0, 1.0
#define white  1.0, 1.0, 1.0, 1.0
#define cyan   0.0, 1.0, 1.0, 1.0