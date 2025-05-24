#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Object.h"
#include "SquareField.h" 

class Controller
{
public:
	Controller();
	~Controller() = default;
	void run();

private:
	void fillSquaresConquere();
	void recFillSquaresConquere(int i, int j, Object* object);
	
	void fillSquares();
	void fillObject();
	void drawSquares();
	void drawObject();
	void moveObject(float time);
	void checkCollision();
	void checkSquaresCollision();
	void ReadFileInfo(std::ifstream& file);
	void printInfo();
	void resetDisqualification();

	sf::RenderWindow m_window;
	std::vector<std::unique_ptr<Object>> m_object;
	std::vector<std::vector<std::unique_ptr <SquareField>>> m_squares;
	sf::Clock m_clock;
	std::vector<int> m_info;
	int m_sumSquare = 0;
};