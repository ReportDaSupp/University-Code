#ifndef STARTTEXT_H
#define STARTTEXT_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class StartText {
private:
	sf::Text text;
	int iTextYPos;

public:
	StartText(); //default constructor
	void setFont(sf::Font font);
	void setText(string sText);
	void setCharSize(int iCharSize);
	void setPosition(int iWindowW, int iLastYPos, int iGap);
	void drawText(sf::RenderWindow& window);
	int getYPos();
};


#endif