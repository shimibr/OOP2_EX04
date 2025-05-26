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
    m_text.setFont(m_font);
    m_text.setString(str);
    m_text.setCharacterSize(size);
    m_text.setFillColor(color);

    if (position.x == 0)
        m_text.setPosition(window.getSize().x / 2 + position.x, window.getSize().y / 2 + position.y);
	else
        m_text.setPosition(position);

    auto bounds = m_text.getLocalBounds();
    m_text.setOrigin(bounds.width / 2, bounds.height / 2);

    window.draw(m_text);
}
//=====================================
void PrintText::drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, sf::Vector2f position, int wait)
{
    window.clear();
    drawText(window, str, size, color, position);
    window.display();
    sf::sleep(sf::seconds(wait));
}
