#pragma once

#include "Square.h"
#include "Io.h"

class Object : public Square
{
public:
	Object(sf::Vector2f position,sf::Color color, int speed);
	virtual void move(sf::Vector2f time);

protected:
	Direction m_direction;
private:
	int m_speed;
};