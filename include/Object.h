#pragma once

#include "Io.h"
#include "Square.h"

class Object : public Square
{
public:
	Object(sf::Vector2f position,sf::Color color, int speed);
	virtual ~Object() {};
	virtual void move(float time);

	virtual void collision(Object* other) = 0;
	virtual void collision(Square* Square) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;
	virtual void collideWith(SquareField* squareField, SquareType squareType) = 0;

protected:
	void moveBack();
	int m_directionX;
	int m_directionY;
private:
	float m_timeMove;
	bool m_moveX = true;
	int m_speed;
};