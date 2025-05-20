#include "Object.h"

Object::Object(sf::Vector2f position, sf::Color color, int speed)
	: Square(position, color), m_speed(speed)
{
}
//==================================
void Object::move(float time)
{
	m_timeMove = time;
	if (m_moveX)
	{
		m_position.x += m_directionX * time * m_speed;
		m_moveX = false;
	}
	else
	{
		m_position.y += m_directionY * time * m_speed;
		m_moveX = true;
	}
	setPosition();
}
//==================================
void Object::moveBack()
{
	if (m_moveX)
	{
		m_directionY *= -1;
		m_position.y += m_directionY * m_speed * m_timeMove;
	}
	else
	{
		m_directionX *= -1;
		m_position.x += m_directionX * m_speed * m_timeMove;
	}
	setPosition();
}
//==================================