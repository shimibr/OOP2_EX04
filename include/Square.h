#pragma once
#include <SFML/Graphics.hpp>
#include "Io.h"

class SquareField;
class Object;
enum class SquareType;

class Square
{
public:
	Square(sf::Vector2f position,sf::Color color);
	virtual ~Square() = default;
	virtual void draw(sf::RenderWindow& window);


	virtual void collision(Object* other) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;

	sf::FloatRect getGlobalBounds() const;
protected:
	void setPosition() { m_square.setPosition(m_position);}
	sf::Vector2f m_position;
private:
	void inWindow(sf::Vector2u sizeWindow);
	sf::RectangleShape m_square;
};