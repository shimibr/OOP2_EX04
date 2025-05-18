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

protected:
	Direction m_direction;
private:
	int m_speed;
};