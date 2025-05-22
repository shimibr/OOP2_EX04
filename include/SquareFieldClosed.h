#pragma once
#include "SquareField.h"



class SquareFieldClosed : public SquareField
{
public:
	SquareFieldClosed(sf::Vector2f position);
	~SquareFieldClosed() {}

	void collision(Object* other) override;
	void collideWith(Player* player) override;
	void collideWith(Enemy* enemy) override;

	bool isOpen(Player* player) override;


private:

};