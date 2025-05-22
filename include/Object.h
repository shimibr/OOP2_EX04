#pragma once

#include "Square.h"
//#include "SquareFieldTrail.h"
//#include "SquareFieldClosed.h"
//#include "SquareFieldOpen.h"
class SquareFieldTrail;
class SquareFieldClosed;
class SquareFieldOpen;

class Object : public Square
{
public:
	Object(sf::Vector2f position,sf::Color color, int speed);
	virtual ~Object() {};
	virtual void move(float time);

	virtual void collision(SquareField* squareField) = 0;
	virtual void collision(Object* other) = 0;
	virtual void collideWith(class Player* player) = 0;
	virtual void collideWith(class Enemy* enemy) = 0;

	virtual void collideWith(SquareFieldTrail* squareFieldTrail) = 0;
	virtual void collideWith(SquareFieldClosed* squareFieldClosed) = 0;
	virtual void collideWith(SquareFieldOpen* squareFieldOpen) = 0;

	virtual bool isOpen(SquareField* squareField) = 0;

protected:
	void moveBack();
	int m_directionX;
	int m_directionY;
private:
	float m_timeMove;
	bool m_moveX = true;
	int m_speed;
};