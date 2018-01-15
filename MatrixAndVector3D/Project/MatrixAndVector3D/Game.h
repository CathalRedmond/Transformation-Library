/// <summary>
/// @author Cathal Redmond
/// </summary>
#ifndef GAME
#define GAME

#include "Vector3D.h"
#include "Matrix3D.h"

class Vector3D;
class Matrix3D;

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setUpShape();

	sf::RenderWindow m_window; // main SFML window



	Matrix3D matrix;



	// vertex array for a triangle
	sf::VertexArray m_triangle;
	// vertexs for the vertex array triangle
	sf::Vertex m_vertexs[3];
	// position of the vertex using vector3d class
	Vector3D m_vertexPos[3];

	// colour used for the vertexs
	sf::Color m_red = sf::Color::Red;
	// bool used for if the vertexs has been moved, scaled or rotated
	bool m_hasTransformed{ false };

};

#endif // !GAME
