#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(sf::Vector2f position, int life);
	virtual ~Player() {};
	void move(float time) override;
	void draw(sf::RenderWindow& window) override;

	void collision(SquareField* squareField) override;
	void collision(Object* other) override;
	void collideWith(class Player* player) override;
	void collideWith(class Enemy* enemy) override;

	void collideWith(SquareFieldTrail* squareFieldTrail) override {}
	void collideWith(SquareFieldClosed* squareFieldClosed) override;
	void collideWith(SquareFieldOpen* squareFieldOpen) override;


private:
	
	int m_life;
};
