#pragma once
#include "SquareField.h"


class SquareFieldTrail : public SquareField
{
public:
	SquareFieldTrail(sf::Vector2f position);
	~SquareFieldTrail() {}

	void collision(Object* other) override;
	void collideWith(Player* player) override {}
	void collideWith(Enemy* enemy) override {}

private:

};