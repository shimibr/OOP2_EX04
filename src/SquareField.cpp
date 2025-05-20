#pragma once
#include "SquareField.h"
#include "Object.h"
#include "Player.h"


SquareField::SquareField(sf::Vector2f position, sf::Color color, SquareType squareType)
	: Square(position, color), m_Type(squareType)
{
}
//==================================
void SquareField::collision(Object* other)
{
	if (this->getGlobalBounds().intersects(other->getGlobalBounds()))
	{ 
		other->collideWith(this,m_Type);
	}
}
//==================================
void SquareField::collideWith(Player* player)
{
	/*if ((int)(this->getGlobalBounds().getPosition().x / 4) == (int)(player->getGlobalBounds().getPosition().x / 4)
		&& (int)(this->getGlobalBounds().getPosition().y / 4) == (int)(player->getGlobalBounds().getPosition().y / 4))*/
	if(this->getGlobalBounds().getPosition() == (player->getGlobalBounds().getPosition()))
	{
		if (m_Type == SquareType::Open)
		{
			m_Type = SquareType::Trail;
			setColor(sf::Color::White);
			player->collideWith(this, m_Type);
		}
	}
	else if (this->getGlobalBounds().intersects(player->getGlobalBounds()))
	{
		if (m_Type == SquareType::Closed || m_Type == SquareType::Trail)
		{
			player->collideWith(this, m_Type);
		}
	}
}
//==================================
void SquareField::collideWith(Enemy* enemy)
{
	
}
//==================================
void SquareField::collideWith(SquareField* squareField, SquareType squareType)
{
}
