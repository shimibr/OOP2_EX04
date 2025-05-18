#pragma once
#include <SFML/Graphics.hpp>

class Square
{
public:
	Square(sf::Vector2f position,sf::Color color);
	void draw(sf::RenderWindow& window);

private:

	sf::RectangleShape m_square;
	sf::Vector2f m_position;
};