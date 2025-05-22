#pragma once
#include "Controller.h"
#include "Enemy.h"
#include <iostream>//
#include "SquareFieldOpen.h"
#include <SquareFieldClosed.h>
#include "SquareFieldTrail.h"
#include <fstream>
#include <sstream>

Controller::Controller()
{
}

void Controller::run()
{
	std::ifstream file("info.txt");
	ReadFileInfo(file);

	m_object.push_back(std::make_unique<Player>(sf::Vector2f(0, 0), m_info[2]));
	m_clock.restart();
	m_window.create(sf::VideoMode(m_info[0], m_info[1]), "Xonix game!");
	m_window.setFramerateLimit(60);
	ReadFileInfo(file);

	fillObject();
	fillSquares();

	while (m_window.isOpen())
	{
		//if (Square::playerIsDead())
			//std::cout << "dead";//

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

	m_squares.resize(size.x);
	for (int i = 0; i < m_squares.size();i++)
		m_squares[i].resize(size.y);

	for (int i = 0; i < size.x; i++)
   {   
	   for (int j = 0; j < size.y; j++)
       {  
		   if (i == 0 || j == 0 || i == size.x - 1 || j == size.y - 1)
			   m_squares[i][j] = std::make_unique< SquareFieldClosed>(sf::Vector2f(i * SQUARE_SIZE, j * SQUARE_SIZE));
		   else
			   m_squares[i][j] = std::make_unique<SquareFieldOpen>(sf::Vector2f(i * SQUARE_SIZE, j * SQUARE_SIZE));
	   } 
   }  
}
//==================================
void Controller::fillObject() // פה צריך למלאת את המערך של המלבנים
{
	for (int i = 0; i < m_info[1]; ++i)
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
			m_squares[i][j]->draw(m_window);
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
				m_object[i]->collision(m_squares[j][k].get());
			}
		}
	}
}
//=======================================
void Controller::ReadFileInfo(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}

	m_info.clear(); // מאפס את הווקטור

	std::string line;
	if (std::getline(file, line)) // קורא רק שורה אחת
	{
		std::istringstream iss(line);
		int number;

		while (iss >> number)
		{
			m_info.push_back(number); // מוסיף מספרים לווקטור
		}
	}

}
