#include "Square.h"

Square::Square(sf::Vector2f position, sf::Color color
) : m_position(position)
{
	m_square.setSize(sf::Vector2f(20.f, 20.f));
	m_square.setFillColor(color);
	m_square.setPosition(m_position);
}
//==================================
void Square::draw(sf::RenderWindow& window)
{
	m_square.setPosition(m_position);
	window.draw(m_square);
}
