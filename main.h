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
// ID шейдерной программы
GLuint Task1;
GLuint Task2;
GLuint Task3;
GLuint Task4;

GLuint texture1;
GLuint texture2;

// ID атрибута
GLint A1_vertex;
GLint A1_color;
GLint U1_affine;
GLint U1_proj;

GLint A2_vertex;
GLint A2_color;
GLint A2_texCoord;
GLint U2_affine;
GLint U2_proj;

GLint A3_vertex;
GLint A3_color;
GLint A3_texCoord;
GLint U3_affine;
GLint U3_proj;

GLint A4_vertex;
GLint A4_color;
GLint U4_affine;
GLint U4_proj;

GLint U_mix_value;
// ID вершинного буфера
GLuint VBO;

// Матрицы аффиных преобразований
glm::mat4 affine;
// Матрица проекции
glm::mat4 proj;

GLfloat tex_ratio = 0.5f;

// Структура для хранения вершин
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

// Функция для установки иконки приложения
void SetIcon(sf::Window& wnd);
// Функция для проверки ошибок
void checkOpenGLerror();



void ShaderLog(unsigned int shader);
// Функция для загрузки шейдеров
void InitShader();
void LoadAttrib(GLuint prog, GLint& attrib, const char* attr_name);
void LoadUniform(GLuint prog, GLint& attrib, const char* attr_name);
// Функция для инициализации вершинного буфера
void InitVBO();
// Функция для инициализации ресурсов
void InitTextures();
void Init();
// Функция для отрисовки
void Draw(sf::Window& window);
// Функция для очистки шейдеров
void ReleaseShader();
// Функция для очистки вершинного буфера
void ReleaseVBO();
// Функция для очистки ресурсов
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