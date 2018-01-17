/// <summary>
/// @author Cathal Redmond
/// </summary>

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "Vector3D.h"

#ifndef GAME_H 
#define GAME_H



class Game
{
public:
	Game();
	~Game();
	void run();

private:
	sf::Window m_window;

	bool isRunning{ false };
	void initialize();
	void update();
	void draw();
	void unload();


	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 1.0f;


	Vector3D trianglePosition[3];
	Matrix3D matrix;

	bool triangleUpdated{ false };

	


};








#endif // !GAME_H 
