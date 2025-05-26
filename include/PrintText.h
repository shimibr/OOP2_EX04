#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class PrintText
{
public:
    static PrintText& getInstance(); 

    void drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, sf::Vector2f position);
    void drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, sf::Vector2f position, int wait);

private:
    PrintText();                  
    ~PrintText();             

    PrintText(const PrintText&) = delete;         
    PrintText& operator=(const PrintText&) = delete; 

    sf::Font m_font;
    sf::Text m_text;
};
