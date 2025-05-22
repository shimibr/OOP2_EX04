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
	void fillSquares();
	void fillObject();
	void drawSquares();
	void drawObject();
	void moveObject(float time);
	void checkCollision();
	void checkSquaresCollision();
	void ReadFileInfo(std::ifstream& file);
	void printInfo();

	sf::RenderWindow m_window;
	std::vector<std::unique_ptr<Object>> m_object;
	std::vector<std::vector<std::unique_ptr <SquareField>>> m_squares;
	sf::Clock m_clock;
	std::vector<int> m_info;
};