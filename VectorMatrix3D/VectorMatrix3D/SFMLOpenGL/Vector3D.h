/// <summary>
/// @author Cathal Redmond
/// </summary>
#ifndef VECTOR_3D
#define VECTOR_3D

#include <iostream>
#include <string>
#include "Matrix3D.h"
#include <SFML\Graphics.hpp>


//forward referencing
class Matrix3D;

/// <summary>
/// @brief a class for a 3D vector
/// </summary>
class Vector3D
{
public:
	Vector3D();
	

	Vector3D(double t_x, double t_y, double t_z);
	Vector3D(double t_x, double t_y);

	double X() const;
	double Y() const;
	double Z() const;

	double length() const;
	double lengthSquared() const;

	void normalise();

	Vector3D operator + (Vector3D t_vector3D) const;
	Vector3D operator - (Vector3D t_vector3D) const;
	Vector3D operator - () const;
	double operator * (Vector3D t_vector3D) const;
	Vector3D operator * (double t_scalar) const;
	Vector3D operator * (float t_scalar) const;
	Vector3D operator * (int t_scalar) const;
	Vector3D operator ^ (Vector3D t_vector) const;
	Vector3D operator * (Matrix3D t_matrix3D) const;

	bool operator == (Vector3D t_vector) const;
	bool operator != (Vector3D t_vector) const;

	std::string toString() const;




private:
	// x component of the vector
	double m_x;
	// y component of the vector
	double m_y;
	// z component of the vector
	double m_z;
};

#endif // !VECTOR_3D
