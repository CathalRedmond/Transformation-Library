/// <summary>
/// @author Cathal Redmond
/// </summary>
#include "Game.h"
#include <iostream>


/// <summary>
/// @brief basic constructor for the game class
/// </summary>
Game::Game() 
	:m_window{ sf::VideoMode{ 800, 600 }, "Matrix Vector 3D" }
	,m_triangle{sf::Triangles}
{
	m_vertexPos[0] = Vector3D(400.0, 100.0);
	m_vertexPos[1] = Vector3D(200.0, 400.0);
	m_vertexPos[2] = Vector3D(600.0, 400.0);

	for (int i = 0; i < 3; i++)
	{
		m_vertexs[i].position = m_vertexPos[i];
		m_vertexs[i].color = m_red;
		m_triangle.append(m_vertexs[i]);
	}
}


/// <summary>
/// @brief basic destructor for the game class
/// </summary>
Game::~Game()
{
}



void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_window.close();
				break;
			case sf::Keyboard::W:
				m_hasTransformed = true;
				matrix = matrix.translate(0, -10);
				break;
			case sf::Keyboard::A:
				m_hasTransformed = true;
				matrix = matrix.translate(-10, 0);
				break;
			case sf::Keyboard::S:
				m_hasTransformed = true;
				matrix = matrix.translate(0, 10);
				break;
			case sf::Keyboard::D:
				m_hasTransformed = true;
				matrix = matrix.translate(10, 0);
				break;
			case sf::Keyboard::F:
				m_hasTransformed = true;
				matrix = matrix.scale3D(1.1);
				break;
			case sf::Keyboard::G:
				m_hasTransformed = true;
				matrix = matrix.scale3D(0.9);
				break;
			case sf::Keyboard::Z:
				m_hasTransformed = true;
				matrix = matrix.rotationZ(1);
				break;
			case sf::Keyboard::X:
				m_hasTransformed = true;
				matrix = matrix.rotationZ(-1);
				break;
			case sf::Keyboard::C:
				m_hasTransformed = true;
				matrix = matrix.rotationX(1);
				break;
			case sf::Keyboard::V:
				m_hasTransformed = true;
				matrix = matrix.rotationX(-1);
				break;
			case sf::Keyboard::B:
				m_hasTransformed = true;
				matrix = matrix.rotationY(1);
				break;
			case sf::Keyboard::N:
				m_hasTransformed = true;
				matrix = matrix.rotationY(-1);
				break;
			default:
				break;
			}
			
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	for (size_t index = 0; index < 3; index++)
	{
		if (m_hasTransformed)	// only updates if the vertex has transformed
		{
			m_vertexPos[index] = matrix *  m_vertexPos[index];
			if (index == 2)
			{
				m_hasTransformed = false;
			}
		}
		m_triangle[index].position = m_vertexPos[index];
		m_vertexs[index].position = m_vertexPos[index];
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_triangle);
	m_window.display();
}


