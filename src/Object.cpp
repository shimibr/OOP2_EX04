#include "Object.h"

Object::Object(sf::Vector2f position, sf::Color color, int speed)
	: Square(position, color), m_speed(speed)
{
	m_direction = static_cast<Direction>(rand() % 4);
}
//==================================
void Object::move(sf::Vector2f time)
{
	m_position +=  sf::Vector2f(m_speed* time.x, m_speed* time.y);
}
//==================================