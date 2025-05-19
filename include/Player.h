#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(sf::Vector2f position, sf::Color color);
	virtual ~Player() {};
	void move(sf::Vector2f time) override;
	void draw(sf::RenderWindow& window) override;
	void collision(Object* other) override;
	void collideWithPlayer(class Player* player) override;
	void collideWithEnemy(class Enemy* enemy) override;
	void collideWithSquare(Square* square) override;


private:
};
