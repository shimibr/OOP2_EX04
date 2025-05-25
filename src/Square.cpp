#pragma once
#include "Square.h"


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
	inWindow(window.getSize());
	window.draw(m_square);
}
//==================================
sf::FloatRect Square::getGlobalBounds() const
{
	return m_square.getGlobalBounds();
}
//================================
void Square::inWindow(sf::Vector2u sizeWindow)
{
	if (m_position.x < 0)
		m_position.x = 0;
	if (m_position.x > sizeWindow.x - SQUARE_SIZE)
		m_position.x = sizeWindow.x - SQUARE_SIZE;
	if (m_position.y < 0)
		m_position.y = 0;
	if (m_position.y > sizeWindow.y - SQUARE_SIZE * 3)
		m_position.y = sizeWindow.y - SQUARE_SIZE * 3;

	setPosition();
}
