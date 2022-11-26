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
GLuint Program;
// ID атрибута
GLint Attrib_vertex;
GLint Attrib_color;
GLint Uniform_proj;
GLint Uniform_affine;
// ID вершинного буфера
GLuint VBO;

// Матрицы аффиных преобразований
glm::mat4 affine;
// Матрица проекции
glm::mat4 proj;

GLfloat tex1_ratio = 0.5f;
GLfloat tex2_ratio = 0.5f;

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
};

// Функция для установки иконки приложения
void SetIcon(sf::Window& wnd);
// Функция для проверки ошибок
void checkOpenGLerror();
//
void ShaderLog(unsigned int shader);
// Функция для загрузки шейдеров
void InitShader();
// Функция для инициализации вершинного буфера
void InitVBO();
// Функция для инициализации ресурсов
void Init();
// Функция для отрисовки
void Draw(sf::Window& window);
// Функция для очистки шейдеров
void ReleaseShader();
// Функция для очистки вершинного буфера
void ReleaseVBO();
// Функция для очистки ресурсов
void Release();


#define red    1.0, 0.0, 0.0, 1.0
#define green  0.0, 1.0, 0.0, 1.0
#define blue   0.0, 0.0, 1.0, 1.0
#define yellow 1.0, 1.0, 0.3, 1.0
#define orange 1.0, 0.5, 0.0, 1.0
#define violet 0.5, 0.0, 1.0, 1.0
#define white  1.0, 1.0, 1.0, 1.0
#define cyan   0.0, 1.0, 1.0, 1.0