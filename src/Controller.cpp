#pragma once
#include "Controller.h"
#include "Enemy.h"
#include <iostream>//

Controller::Controller()
{
}

void Controller::run()
{
	m_clock.restart();
	m_window.create(sf::VideoMode(800, 600), "SFML works!");
	m_window.setFramerateLimit(60);

	fillSquares();
	fillObject();

	while (m_window.isOpen())
	{
		if (Square::playerIsDead())
			std::cout << "dead";//

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		float time = m_clock.restart().asSeconds();
		for (int i = 0; i < 2; i++)
		{
			moveObject(time);
			checkCollision();
		}

		m_window.clear();
		drawSquares();
		drawObject();
		m_window.display();
	}
}
//==================================
void Controller::fillSquares()  
{  
	sf::Vector2f size = sf::Vector2f(m_window.getSize().x / SQUARE_SIZE, m_window.getSize().y / SQUARE_SIZE);
   for (int i = 0; i < size.x; i++)
   {  
       std::vector<SquareField> row;
       for (int j = 0; j < size.y; j++)
       {  
		   if(i == 0 || j == 0 || i == size.x - 1 || j ==  size.y - 1)
			   row.emplace_back(sf::Vector2f(i * SQUARE_SIZE, j * SQUARE_SIZE), sf::Color::Cyan , SquareType::Closed);
		   else
           row.emplace_back(sf::Vector2f(i * SQUARE_SIZE, j * SQUARE_SIZE), sf::Color::Black , SquareType::Open);
       }  
       m_squares.push_back(row);  
   }  
}
//==================================
void Controller::fillObject() // פה צריך למלאת את המערך של המלבנים
{
	m_object.push_back(std::make_unique<Player>(sf::Vector2f(0,0)));
	for (int i = 0; i < 3; ++i)
	{
			m_object.push_back(std::make_unique<Enemy>(sf::Vector2f((i+1) * 100, (i+1) * 100), sf::Color::Red));
	}
}
//==================================
void Controller::drawSquares()
{
	for (int i = 0; i < m_squares.size(); ++i)
	{
		for (int j = 0; j < m_squares[i].size(); ++j)
		{
			m_squares[i][j].draw(m_window);
		}
	}

}
//==================================
void Controller::drawObject()
{
	for (const auto& object : m_object)
	{
		object->draw(m_window);
	}
}
//==================================
void Controller::moveObject(float time)
{
	for (int i = 0; i < m_object.size(); ++i)
	{
		m_object[i]->move(time);
	}
}
//==================================
void Controller::checkCollision()
{
	checkSquaresCollision();
	for (int i = 0; i < m_object.size(); ++i)
	{
		for (int j = i + 1; j < m_object.size(); ++j)
		{
				m_object[i]->collision(m_object[j].get());
				m_object[j]->collision(m_object[i].get());
		}
	}


}
//=======================================
void Controller::checkSquaresCollision()
{
	for (int i = 0; i < m_object.size(); ++i)
	{
		for (int j = 0; j < m_squares.size(); ++j)
		{
			for (int k = 0; k < m_squares[j].size(); ++k)
			{
				m_object[i]->collision(&m_squares[j][k]);
			}
		}
	}
}
