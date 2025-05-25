#pragma once

#include "Object.h"
#include "SquareField.h"


class Enemy : public Object
{
public:
	Enemy(sf::Vector2f position, sf::Color color);
	~Enemy() = default;

	void collision(SquareField* squareField) override;
	void collision(Object* other) override;

	void collideWith(class Player* player) override{ m_playerDead = true; }
	void collideWith(class Enemy* enemy) override {}
	void collideWith(SquareFieldTrail* squareFieldTrail) override{ m_playerDead = true; }
	void collideWith(SquareFieldClosed* squareFieldClosed) override{ moveBack(); }
	void collideWith(SquareFieldOpen* squareFieldOpen) override {}

	bool isOpen(SquareField* squareField) override { return squareField->isOpen(this); }

private:
	
};