#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(sf::Vector2f position);
	virtual ~Player() {};
	void move(float time) override;
	void draw(sf::RenderWindow& window) override;
	void collision(Object* other) override;
	void collideWith(class Player* player) override;
	void collideWith(class Enemy* enemy) override;
	void collideWith(SquareField* squareField, SquareType squareType) override;


private:
};
