#include <Game.h>

Game::Game()
	:
	m_window(sf::VideoMode(800,600), "VectorMAtrix3D")
{
}

Game::~Game()
{
}

void Game::run()
{
	initialize();

	sf::Event event;

	while (isRunning)
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				
					switch (event.key.code)
					{
					case sf::Keyboard::W:
						matrix = matrix.translate(0.0, -0.1);
						triangleUpdated = true;
						break;
					case sf::Keyboard::S:
						matrix = matrix.translate(0.0,0.1);
						triangleUpdated = true;
						break;
					case sf::Keyboard::A:
						matrix = matrix.translate(0.1, 0.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::D:
						matrix = matrix.translate(-0.1, 0.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::Z:
						matrix = matrix.rotationX(1.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::X:
						matrix = matrix.rotationX(-1.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::C:
						matrix = matrix.rotationY(-1.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::V:
						matrix = matrix.rotationY(1.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::B:
						matrix = matrix.rotationZ(-1.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::N:
						matrix = matrix.rotationZ(1.0);
						triangleUpdated = true;
						break;
					case sf::Keyboard::F:
						matrix = matrix.scale3D(1.005);
						triangleUpdated = true;
						break;
					case sf::Keyboard::G:
						matrix = matrix.scale3D(0.905);
						triangleUpdated = true;
						break;
					default:
						break;
					}
			}
		}
		update();
		draw();
	}
}

void Game::initialize()
{

	trianglePosition[0] = Vector3D(0.0, 2.0, -30.0);
	trianglePosition[1] = Vector3D(-2.0, -2.0, -30.0);
	trianglePosition[2] = Vector3D(2.0, -2.0, -30.0);



	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, m_window.getSize().x / m_window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);



	

}

void Game::update()
{
	if (triangleUpdated)
	{
		for (int index = 0; index < 3; index++)
		{
			trianglePosition[index] = matrix * trianglePosition[index];
		}
		triangleUpdated = false;
	}
}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(trianglePosition[0].X(), trianglePosition[0].Y(), trianglePosition[0].Z());
		glVertex3f(trianglePosition[1].X(), trianglePosition[1].Y(), trianglePosition[1].Z());
		glVertex3f(trianglePosition[2].X(), trianglePosition[2].Y(), trianglePosition[2].Z());
	}
	glEnd();
	m_window.display();
}

void Game::unload()
{
}
