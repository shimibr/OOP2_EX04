#include "Square.h"
#include <Io.h>

bool Square::m_playerDead = false;

Square::Square(sf::Vector2f position, sf::Color color) 
	: m_position(position)
{
	m_square.setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
	m_square.setFillColor(color);
	m_square.setPosition(m_position);
}
//==================================
void Square::draw(sf::RenderWindow& window) 
{
	window.draw(m_square);
}
//==================================
sf::FloatRect Square::getGlobalBounds() const
{
	return m_square.getGlobalBounds();
}
