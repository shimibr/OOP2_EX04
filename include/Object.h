#pragma once

#include "Square.h"
#include "Io.h"

class Object : public Square
{
public:
	Object(sf::Vector2f position,sf::Color color, int speed);
	virtual ~Object() {};
	virtual void move(sf::Vector2f time);
	virtual void draw(sf::RenderWindow& window) override{}

	virtual void collision(Object* other) = 0;
	virtual void collideWithPlayer(class Player* player) = 0;
	virtual void collideWithEnemy(class Enemy* enemy) = 0;
	virtual void collideWithSquare(Square* square) = 0;

protected:
	Direction m_direction;
private:
	int m_speed;
};