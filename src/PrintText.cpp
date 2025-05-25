#include "PrintText.h"
#include <iostream>

PrintText::PrintText()
{
    if (!m_font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
}
//===================================
PrintText::~PrintText() = default;
//===================================
PrintText& PrintText::getInstance()
{
    static PrintText instance;
    return instance;
}
//===================================
void PrintText::drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, sf::Vector2f position)
{
    text.setFont(m_font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);

    if (position.x == 0)
	text.setPosition(window.getSize().x / 2 + position.x, window.getSize().y / 2 + position.y);
	else
		text.setPosition(position);

    // אפשרות למרכז את הטקסט:
    auto bounds = text.getLocalBounds();
    text.setOrigin(bounds.width / 2, bounds.height / 2);

    window.draw(text);
//	window.display();
}
