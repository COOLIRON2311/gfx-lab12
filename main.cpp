#include "main.h"
#include "shaders.h"

ShapeType shapetype = ShapeType::Gradient_Tetrahedron;

void Init()
{
	proj = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
	affine = glm::mat4(1.0f);
	//Включаем проверку глубины
	glEnable(GL_DEPTH_TEST);
	// Инициализируем шейдеры
	InitShader();
	// Инициализируем вершинный буфер
	InitVBO();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	sf::Window window(sf::VideoMode(600, 600), "Shapes", sf::Style::Default, sf::ContextSettings(24));
	SetIcon(window);
	window.setVerticalSyncEnabled(true); // Вертикальная синхронизация
	window.setActive(true); // Устанавливаем контекст OpenGL
	glewInit(); // Инициализируем GLEW
	Init(); // Инициализируем ресурсы
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) // Если пользователь закрыл окно
			{
				window.close(); // Закрываем окно
				goto EXIT_IS_RIGHT_HERE; // Выходим из цикла
			}
			else if (event.type == sf::Event::Resized) // Если пользователь изменил размер окна
			{
				glViewport(0, 0, event.size.width, event.size.height); // Устанавливаем область вывода
			}
			else if (event.type == sf::Event::KeyPressed)
			{	
				// Rotation
				if (event.key.code == sf::Keyboard::P)
				{
					affine = glm::rotate(affine, 0.1f, glm::vec3(1.0f, 0.0f, 0.0f));
				}
				else if (event.key.code == sf::Keyboard::R)
				{
					affine = glm::rotate(affine, 0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
				}
				else if (event.key.code == sf::Keyboard::Y)
				{
					affine = glm::rotate(affine, 0.1f, glm::vec3(0.0f, 0.0f, 1.0f));
				}

				// Movement
				else if (event.key.code == sf::Keyboard::W)
				{
					affine = glm::translate(affine, glm::vec3(0.0f, 0.0f, 0.1f));
				}
				else if (event.key.code == sf::Keyboard::S)
				{
					affine = glm::translate(affine, glm::vec3(0.0f, 0.0f, -0.1f));
				}
				else if (event.key.code == sf::Keyboard::A)
				{
					affine = glm::translate(affine, glm::vec3(-0.1f, 0.0f, 0.0f));
				}
				else if (event.key.code == sf::Keyboard::D)
				{
					affine = glm::translate(affine, glm::vec3(0.1f, 0.0f, 0.0f));
				}
				else if (event.key.code == sf::Keyboard::Z)
				{
					affine = glm::translate(affine, glm::vec3(0.0f, 0.1f, 0.0f));
				}
				else if (event.key.code == sf::Keyboard::X)
				{
					affine = glm::translate(affine, glm::vec3(0.0f, -0.1f, 0.0f));
				}
				else if (event.key.code == sf::Keyboard::Equal)
				{
					/*TODO*/
				}
				else if (event.key.code == sf::Keyboard::Subtract)
				{
					/*TODO*/
				}

				else if (event.key.code == sf::Keyboard::F1)
				{
					proj = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
				}
				
				else if (event.key.code == sf::Keyboard::F2)
				{
					proj = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
				}
				
				else if (event.key.code == sf::Keyboard::Escape)
				{
					affine = glm::mat4(1.0f);
				}

				else if (event.key.code == sf::Keyboard::Num1)
				{
					shapetype = ShapeType::Gradient_Tetrahedron;
				}
				
				else if (event.key.code == sf::Keyboard::Num2)
				{
					shapetype = ShapeType::Gradient_Texture_Cube;
				}

				else if (event.key.code == sf::Keyboard::Num3)
				{
					shapetype = ShapeType::Double_Texture_Cube;
				}

				else if (event.key.code == sf::Keyboard::Num4)
				{
					shapetype = ShapeType::Gradient_Pie;
				}
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищаем буфер цвета и буфер глубины
		Draw(window); // Рисуем
		window.display(); // Выводим на экран
	}
EXIT_IS_RIGHT_HERE: // Метка выхода
	Release(); // Очищаем ресурсы
	return 0; // Выходим из программы
}

void InitVBO()
{
	glGenBuffers(1, &VBO); // Генерируем вершинный буфер
	Vertex data[] = {
		/*
		//Cube
		{1.0f, 1.0f, 1.0f, red},	//0
		{1.0f, 1.0f, -1.0f, blue},	//1
		{1.0f, -1.0f, 1.0f, green},	//2
		{1.0f, -1.0f, -1.0f, red},	//3
		{-1.0f, 1.0f, 1.0f, blue},	//4
		{-1.0f, 1.0f, -1.0f, green},//5
		{-1.0f, -1.0f, 1.0f, red},	//6
		{-1.0f, -1.0f, -1.0f, blue}	//7*/

		/*
		//Tetrahedron
		{1.0f, 0.0f, 0.0f, red},	//p1
		{0.0f, 1.0f, 0.0f, blue},	//p2
		{1.0f, 1.0f, 1.0f, green},	//p3
		{0.0f, 0.0f, 1.0f, orange},	//p4
		*/

		//Tetrahedron
		{0.0f, 0.0f, 0.0f, red},{0.0f, 1.0f, 1.0f, green},{1.0f, 0.0f, 1.0f, blue},
		{0.0f, 0.0f, 0.0f, red},{0.0f, 1.0f, 1.0f, green},{1.0f, 1.0f, 0.0f, white},
		{0.0f, 0.0f, 0.0f, red},{1.0f, 1.0f, 0.0f, white},{1.0f, 0.0f, 1.0f, blue},
		{1.0f, 1.0f, 0.0f, white},{1.0f, 0.0f, 1.0f, blue},{0.0f, 1.0f ,1.0f, green},

		//Cube
		{1.0f, 1.0f, -1.0f, red},{-1.0f, 1.0f, -1.0f,blue},{-1.0f, 1.0f, 1.0f, green},{1.0f, 1.0f, 1.0f, orange}, //top face
		{1.0f, -1.0f, 1.0f, yellow},{-1.0f, -1.0f, 1.0f, violet}, {-1.0f, -1.0f, -1.0f, white},{1.0f, -1.0f, -1.0f, cyan}, // bottom face
		{1.0f, 1.0f, 1.0f, orange},{-1.0f, 1.0f, 1.0f, green},{-1.0f, -1.0f, 1.0f, violet},{1.0f, -1.0f, 1.0f, yellow}, // front face
		{1.0f, -1.0f, -1.0f, cyan},{-1.0f, -1.0f, -1.0f, white},{-1.0f, 1.0f, -1.0f, blue},{1.0f, 1.0f, -1.0f, red}, //back face
		{-1.0f, 1.0f, 1.0f, green},{-1.0f, 1.0f, -1.0f, blue},{-1.0f, -1.0f, -1.0f, white},{-1.0f, -1.0f, 1.0f, violet}, //left face
		{1.0f, 1.0f, -1.0f, red},{1.0f, 1.0f, 1.0f, orange},{1.0f, -1.0f, 1.0f, yellow},{1.0f, -1.0f, -1.0f, cyan}, //right face

	};
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Привязываем вершинный буфер
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW); // Загружаем данные в буфер
	checkOpenGLerror();
}

void InitShader()
{
	// Создаем вершинный шейдер
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	// Загружаем исходный код шейдера
	glShaderSource(vShader, 1, &VertexShaderSource, NULL);
	// Компилируем шейдер
	glCompileShader(vShader);
	// Проверяем на ошибки
	std::cout << "vertex shader \n";
	ShaderLog(vShader);
	// Создаем фрагментный шейдер
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Загружаем исходный код шейдера
	glShaderSource(fShader, 1, &FragShaderSource, NULL);
	// Компилируем шейдер
	glCompileShader(fShader);
	// Проверяем на ошибки
	std::cout << "fragment shader \n";
	ShaderLog(fShader);

	// Создаем шейдерную программу
	Program = glCreateProgram();
	// Прикрепляем шейдеры к программе
	glAttachShader(Program, vShader);
	glAttachShader(Program, fShader);
	// Линкуем шейдерную программу
	glLinkProgram(Program);

	int link_ok;
	glGetProgramiv(Program, GL_LINK_STATUS, &link_ok);
	// Проверяем на ошибки
	if (!link_ok)
	{
		std::cout << "error attach shaders \n";
		return;
	}
	// Вытягиваем ID атрибута из шейдерной программы
	const char* attr_name = "coord";
	Attrib_vertex = glGetAttribLocation(Program, attr_name);
	if (Attrib_vertex == -1)
	{
		std::cout << "could not bind attrib " << attr_name << std::endl;
		return;
	}

	const char* attr_name2 = "color";
	Attrib_color = glGetAttribLocation(Program, attr_name2);
	if (Attrib_color == -1)
	{
		std::cout << "could not bind attrib " << attr_name2 << std::endl;
		return;
	}

	const char* attr_name3 = "affine";
	Uniform_affine = glGetUniformLocation(Program, attr_name3);
	if (Uniform_affine == -1)
	{
		std::cout << "could not bind uniform " << attr_name3 << std::endl;
		return;
	}

	const char* attr_name4 = "proj";
	Uniform_proj = glGetUniformLocation(Program, attr_name4);
	if (Uniform_proj == -1)
	{
		std::cout << "could not bind uniform " << attr_name4 << std::endl;
		return;
	}
	
	checkOpenGLerror();
}

void Draw(sf::Window& window)
{
	glUseProgram(Program); // Устанавливаем шейдерную программу
	glUniformMatrix4fv(Uniform_affine, 1, GL_FALSE, glm::value_ptr(affine));
	glUniformMatrix4fv(Uniform_proj, 1, GL_FALSE, glm::value_ptr(proj));
	glEnableVertexAttribArray(Attrib_vertex); // Включаем атрибут
	glEnableVertexAttribArray(Attrib_color);
	glEnableVertexAttribArray(Attrib_tex_coord);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Привязываем буфер
	glVertexAttribPointer(Attrib_vertex, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)0); 	// Указываем данные атрибута
	glVertexAttribPointer(Attrib_color, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Отвязываем буфер
	
	switch (shapetype)
	{
	case ShapeType::Gradient_Tetrahedron:
		window.setTitle("Gradient Tetrahedron");
		glDrawArrays(GL_TRIANGLES, 0, 12);
		break;
	case ShapeType::Gradient_Texture_Cube:
		window.setTitle("Gradient & Texture Cube");
		glDrawArrays(GL_QUADS, 12, 24);
		break;
	default:
		break;
	}
	

	glDisableVertexAttribArray(Attrib_vertex); // Отключаем атрибут
	glDisableVertexAttribArray(Attrib_color);
	glUseProgram(0); // Отключаем шейдерную программу
	checkOpenGLerror(); // Проверяем на ошибки
}

void Release()
{
	ReleaseShader(); // Очищаем шейдеры
	ReleaseVBO(); // Очищаем буфер
}

void ReleaseVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Отвязываем буфер
	glDeleteBuffers(1, &VBO); // Удаляем буфер
}

void ReleaseShader()
{
	glUseProgram(0); // Отключаем шейдерную программу
	glDeleteProgram(Program); // Удаляем шейдерную программу
}

void ShaderLog(unsigned int shader)
{
	int infologLen = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infologLen);
	if (infologLen > 1)
	{
		int charsWritten = 0;
		std::vector<char> infoLog(infologLen);
		glGetShaderInfoLog(shader, infologLen, &charsWritten, infoLog.data());
		std::cout << "InfoLog: " << infoLog.data() << std::endl;
	}
}

void checkOpenGLerror()
{
	GLenum errCode;
	const GLubyte* errString;
	if ((errCode = glGetError()) != GL_NO_ERROR)
	{
		errString = gluErrorString(errCode);
		std::cout << "OpenGL error: " << errString << std::endl;
	}
}

void SetIcon(sf::Window& wnd)
{
	sf::Image image;
	image.create(16, 16);
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			image.setPixel(i, j, { (uint8_t)(i * 16), (uint8_t)(j * 16), 0 });
		}
	}

	wnd.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}
