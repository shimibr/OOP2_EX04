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
	
	while(!Object::playerIsDead() && ReadFileInfo(file) && m_info.size() == 5)
	{
		m_clock.restart();
		m_window.create(sf::VideoMode(m_info[0], m_info[1]), "Xonix game!");
		m_sumSquare = (m_info[0] / SQUARE_SIZE) * (m_info[1] / SQUARE_SIZE);
		m_window.setFramerateLimit(60);

		fillObject();
		fillSquares();

		while (m_window.isOpen())
		{



			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || Object::playerIsDead())
					m_window.close();
			}

			float time = m_clock.restart().asSeconds();
			for (int i = 0; i < 2; i++)
			{
				moveObject(time);
				checkCollision();
			}
			if (Player::isConquered())
			{
				fillSquaresConquere();
			}
			if (Object::playerIsDead())
			{
				resetDisqualification();
			}


			m_window.clear();
			drawSquares();
			drawObject();
			m_window.display();

			if (SquareFieldClosed::getCount() >= m_sumSquare / 100 * m_info[3])
			{
				std::cout << "You win!" << std::endl;
				m_window.close();
				m_stage++;
			}
		}
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
void Controller::fillObject() // פה צריך למלאת את המערך של המלבנים
{
	m_object.push_back(std::make_unique<Player>(sf::Vector2f(0, 0), m_info[2]));
	for (int i = 0; i < m_info[4]; ++i)
	{
		int x = (rand() % (m_info[0] - 3 * SQUARE_SIZE)) + SQUARE_SIZE;
		int y = (rand() % (m_info[1] - 3 * SQUARE_SIZE)) + SQUARE_SIZE;
			m_object.push_back(std::make_unique<Enemy>(sf::Vector2f(x,y), sf::Color::Red));
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
	{
		object->draw(m_window);
	}
	printInfo();
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
bool Controller::ReadFileInfo(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return false;
	}

	m_info.clear(); // מאפס את הווקטור

	std::string line;
	for(int i = 0; i < 2; i++)
	{
		if (std::getline(file, line)) // קורא רק שורה אחת
		{
			std::istringstream iss(line);
			int number;

			while (iss >> number)
			{
				m_info.push_back(number); // מוסיף מספרים לווקטור
			}
		}
		else
		{
			return false; // אם לא הצליח לקרוא שורה, מחזיר false
		}
	}
	return true; // אם הצליח לקרוא את כל השורות, מחזיר true
}
//=======================================
void Controller::printInfo()
{
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setString("Stage: " + std::to_string(m_stage));
	text.setPosition((m_window.getSize().x /5), m_window.getSize().y - 40);
	m_window.draw(text);
	text.setString("Player score: " + std::to_string(SquareFieldClosed::getCount() * 100 / m_sumSquare) + " / " + std::to_string(m_info[3]));
	text.setPosition((m_window.getSize().x /5 * 3 ), m_window.getSize().y - 40);
	m_window.draw(text);
}
//=======================================
void Controller::resetDisqualification()
{
	for (int i = 0; i < m_squares.size(); ++i)
	{
		for (int j = 0; j < m_squares[i].size(); ++j)
		{
			m_squares[i][j]->reset();
		}
	}
	for (int i = 0; i < m_object.size(); ++i)
	{
		m_object[i]->reset();
	}
}
//=======================================
void Controller::deleteGame()
{
	for (int i = 0; i < m_squares.size(); ++i)
	{
		m_squares[i].clear();
	}
	m_squares.clear();
	m_object.clear();
	m_info.clear();
}
//=======================================
