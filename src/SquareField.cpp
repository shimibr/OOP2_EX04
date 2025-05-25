#pragma once
#include "SquareField.h"
#include "Player.h"
#include "Enemy.h"
#include "SquareFieldTrail.h"



SquareField::SquareField(sf::Vector2f position, sf::Color color)
	: Square(position, color) { }
//==================================
bool SquareField::isOpen(Player* player)
{
	if(m_changeToType == SquareType::Closed)
		return false;

	 m_changeToType = SquareType::Closed; return true; 
}
//==================================