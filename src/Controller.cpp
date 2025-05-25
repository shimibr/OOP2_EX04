#pragma once
#include "Controller.h"
#include "Enemy.h"
#include <iostream>
#include "SquareFieldOpen.h"
#include <SquareFieldClosed.h>
#include "SquareFieldTrail.h"
#include "PrintText.h"
#include <fstream>
#include <sstream>

Controller::Controller()
{
}
//========================================
void Controller::run()
{
	std::ifstream file("info.txt");
	
	while(!Object::playerIsDead() && ReadFileInfo(file))
	{
		m_window.create(sf::VideoMode(m_info[0], m_info[1]), "Xonix game!");
		m_sumSquare = (m_info[0] / SQUARE_SIZE) * (m_info[1] / SQUARE_SIZE);
		m_window.setFramerateLimit(60);

		fillSquares();
		fillObject();

		m_clock.restart();
		while (m_window.isOpen())
			runLevel();

	deleteGame();
	}
}
//==================================
void Controller::fillSquaresConquere()
{
	for(int o = 0;o < m_object.size(); o++)
	{
		for (int i = 0; i < m_squares.size(); i++)
		{
			for (int j = 0; j < m_squares[i].size(); j++)
			{
				if (m_squares[i][j]->getGlobalBounds().intersects(m_object[o]->getGlobalBounds()))
				{
					recFillSquaresConquere(i, j, m_object[o].get());
					j = m_squares[i].size();
				}
			}
		}
	}
}
//==================================
void Controller::recFillSquaresConquere(int i, int j, Object* object)
{
	if (object->isOpen(m_squares[i][j].get()))
	{
		if(i < m_squares.size()-1)
			recFillSquaresConquere(i + 1, j, object);
		if(i > 0)
			recFillSquaresConquere(i - 1, j, object);
		if (j < m_squares[i].size() - 1)
			recFillSquaresConquere(i, j + 1, object);
		if (j > 0)
			recFillSquaresConquere(i, j - 1, object);
	}
}
//==================================
void Controller::fillSquares()  
{  
	sf::Vector2f size = sf::Vector2f(m_window.getSize().x / SQUARE_SIZE, (m_window.getSize().y / SQUARE_SIZE) - 2);

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
void Controller::fillObject()
{
	m_object.push_back(std::make_unique<Player>(sf::Vector2f(0, 0), m_info[2]));
	for (int i = 0; i < m_info[4]; ++i)
	{
		int x = (rand() % (m_info[0] - 3 * SQUARE_SIZE)) +  SQUARE_SIZE;
		int y = (rand() % (m_info[1] - 5 * SQUARE_SIZE)) + SQUARE_SIZE;
			m_object.push_back(std::make_unique<Enemy>(sf::Vector2f(x,y)));
	}
}
//==================================
void Controller::drawSquares()
{
	for (int i = 0; i < m_squares.size(); ++i)
	{
		for (int j = 0; j < m_squares[i].size(); ++j)
		{
			if (m_squares[i][j]->isChanged() == SquareType::Trail)
			{
				m_squares[i][j] = std::make_unique<SquareFieldTrail>(sf::Vector2f(i * SQUARE_SIZE, j * SQUARE_SIZE));
			}
			if (m_squares[i][j]->isChanged() == SquareType::Closed)
			{
				m_squares[i][j] = std::make_unique<SquareFieldClosed>(sf::Vector2f(i * SQUARE_SIZE, j * SQUARE_SIZE));
			}
			if (m_squares[i][j]->isChanged() == SquareType::Open)
			{
				m_squares[i][j] = std::make_unique<SquareFieldOpen>(sf::Vector2f(i * SQUARE_SIZE, j * SQUARE_SIZE));
			}
			m_squares[i][j]->draw(m_window);
		}
	}
}
//==================================
void Controller::drawObject()
{
	for (const auto& object : m_object)
		object->draw(m_window);

	printInfo();
}
//==================================
void Controller::moveObject(float time)
{
	for (int i = 0; i < m_object.size(); ++i)
		m_object[i]->move(time);
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
				m_object[i]->collision(m_squares[j][k].get());
		}
	}
}
//=======================================
bool Controller::ReadFileInfo(std::ifstream& file)
{
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file info.txt");
		return false;
	}

	m_info.clear(); // מאפס את הווקטור

	std::string line;
	if (std::getline(file, line)) // קורא רק שורה אחת
	{
		std::istringstream iss(line);
		iss.exceptions(std::ios::failbit | std::ios::badbit);
		int number;

		while (!iss.eof() && iss >> number)
		{
			if (number < 0)
				throw std::runtime_error("Negative number found in info.txt");

			m_info.push_back(number); // מוסיף מספרים לווקטור

			if(!iss.eof())
				iss >> std::ws;
		}
	}
	else
		return false; // אם לא הצליח לקרוא שורה, מחזיר false

	if (m_info.size() != 5)
		throw std::runtime_error("Incorrect number of values in info.txt, expected 5 values");

	return true; // אם הצליח לקרוא את כל השורות, מחזיר true
}
//=======================================
void Controller::printInfo()
{
	PrintText::getInstance().drawText(m_window, "Stage: " + std::to_string(m_stage), 24, sf::Color::White, sf::Vector2f(m_window.getSize().x * 0.15, m_window.getSize().y - SQUARE_SIZE));
	PrintText::getInstance().drawText(m_window, "Player score: " + std::to_string(SquareFieldClosed::getCount() * 100 / m_sumSquare) + " / " + std::to_string(m_info[3]), 24, sf::Color::White, sf::Vector2f((m_window.getSize().x * 0.75), m_window.getSize().y - SQUARE_SIZE));
}
//=======================================
void Controller::resetDisqualification()
{
	for (int i = 0; i < m_squares.size(); ++i)
	{
		for (int j = 0; j < m_squares[i].size(); ++j)
			m_squares[i][j]->reset();
	}

	for (int i = 0; i < m_object.size(); ++i)
		m_object[i]->reset();
}
//=======================================
void Controller::deleteGame()
{
	for (int i = 0; i < m_squares.size(); ++i)
		m_squares[i].clear();

	m_squares.clear();
	m_object.clear();
	m_info.clear();
}
//=======================================
void Controller::playerWon()
{
	PrintText::getInstance().drawText(m_window, "Good job! You won!", 50, sf::Color::Green, sf::Vector2f(0, 0), 2);
	PrintText::getInstance().drawText(m_window, "Press enter to continu ... ", 30, sf::Color::White, sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2), 0);
	m_stage++;

	sf::Event event;
	while (m_window.waitEvent(event))
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			m_window.close();
	}
}
void Controller::playerDead()
{
	if (Object::playerIsDead())
	{
		PrintText::getInstance().drawText(m_window, "Game over!", 50, sf::Color::Red, sf::Vector2f(0, 0), 2);
		PrintText::getInstance().drawText(m_window, "Press enter to exit ... ", 30, sf::Color::White, sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2), 0);

		sf::Event event;
		while (m_window.waitEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				m_window.close();
		}
		return;
	}
}
//======================================
void Controller::checkPlayersStatus()
{
	if (Player::isConquered())
		fillSquaresConquere();

	if (Object::playerIsDead())
	{
		PrintText::getInstance().drawText(m_window, "You are disqualified! Be careful!", 50, sf::Color::Red, sf::Vector2f(0, 0), 1);
		resetDisqualification();
	}

	if (SquareFieldClosed::getCount() >= m_sumSquare / 100 * m_info[3])
		playerWon();
}
//======================================
void Controller::runLevel()
{
	playerDead();

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return;
		}
	}

	float time = m_clock.restart().asSeconds();
	if (time > 0.2f) time = 0.2f; // מגביל את הזמן למקסימום של 0.2 שניות - עמ להתמודד עם מחשבים איטיים

	for (int i = 0; i < 2; i++)
	{
		moveObject(time);
		checkCollision();
	}

	checkPlayersStatus();

	m_window.clear();
	drawSquares();
	drawObject();
	m_window.display();
}
//=======================================
