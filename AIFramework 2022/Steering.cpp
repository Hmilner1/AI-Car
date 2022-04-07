#include "Steering.h"

void Vehicle::update(const float deltaTime)
{
	cout << ("hello") << endl;
}


Vector2D Vehicle::Seek()
{
	Vector2D Target = Vector2D(460, -343);
	Vector2D m_SteerForce = (Target - m_currentPosition);
	m_SteerForce.Normalize();
	m_SteerForce = m_SteerForce * m_maxSpeed;
	return (m_SteerForce - vel);
}