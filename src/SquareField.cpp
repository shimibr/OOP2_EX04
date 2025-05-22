#pragma once
#include "SquareField.h"
#include "Player.h"
#include "Enemy.h"
#include "SquareFieldTrail.h"



SquareField::SquareField(sf::Vector2f position, sf::Color color)
	: Square(position, color)
{
}
//==================================
void SquareField::checkSquareFieldToTrail(std::unique_ptr<SquareField>& squareField)
{
	squareField  = std::make_unique<SquareFieldTrail>(getGlobalBounds().getPosition());

}
//==================================
//void SquareField::collideWith(Player* player)
//{
//	if ((int)(this->getGlobalBounds().getPosition().x / 4) == (int)(player->getGlobalBounds().getPosition().x / 4)
//		&& (int)(this->getGlobalBounds().getPosition().y / 4) == (int)(player->getGlobalBounds().getPosition().y / 4)
//		&& m_Type == SquareType::Open)
//		//if(this->getGlobalBounds().getPosition() == (player->getGlobalBounds().getPosition()))
//	{
//			m_Type = SquareType::Trail;
//			setColor(sf::Color::White);
//			player->collideWith(this);
//	}
//	else if (this->getGlobalBounds().intersects(player->getGlobalBounds()))
//	{
//		if (m_Type == SquareType::Closed || m_Type == SquareType::Trail)
//		{
//			player->collideWith(this);
//		}
//	}
//}
////==================================
//void SquareField::collideWith(Enemy* enemy)
//{
//	if (this->getGlobalBounds().intersects(enemy->getGlobalBounds()))
//	{
//		if (m_Type == SquareType::Closed)
//			enemy->collideWith(this);
//
//		if (m_Type == SquareType::Trail)
//			m_playerDead = true;
//	
//	}
//	
//}
////==================================
