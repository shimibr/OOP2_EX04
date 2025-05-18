#pragma once

#include <SFML/Graphics.hpp>
#include "Square.h"



class Controller
{
public:
	Controller();
	void run();

private:

	void fillSquares();
	void drawSquares();

	sf::RenderWindow m_window;
	std::vector<std::unique_ptr<Square>> m_squares;
};