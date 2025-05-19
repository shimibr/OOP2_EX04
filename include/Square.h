#pragma once
#include <SFML/Graphics.hpp>

class Square
{
public:
	Square(sf::Vector2f position,sf::Color color);
	virtual ~Square() {};
	virtual void draw(sf::RenderWindow& window);
	sf::FloatRect getGlobalBounds() const;

protected:
	sf::Vector2f m_position;
private:

	sf::RectangleShape m_square;
};