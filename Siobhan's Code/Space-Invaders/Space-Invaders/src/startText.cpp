#include "startText.h"
#include <iostream>

StartText::StartText() {} //default constructor

void StartText::setFont(sf::Font font) {
	text.setFont(font);
}

void StartText::setText(string sText) {
	text.setString(sText);
}

void StartText::setCharSize(int iCharSize) {
	text.setCharacterSize(iCharSize);
}

void StartText::setPosition(int iWindowW, int iLastYPos, int iGap) {
	sf::FloatRect boundBox;
	boundBox = text.getLocalBounds(); // Position of error, Font - Ben
	int iTextXPos = (iWindowW - boundBox.width) / 2.0f;
	
	if (iLastYPos != 0) {
		iTextYPos = (iLastYPos + boundBox.height + iGap);
	}
	else {
		iTextYPos = 100;
	}
	
	text.setPosition(iTextXPos, iTextYPos);
}

void StartText::drawText(sf::RenderWindow& window){
	window.draw(text);
}

int StartText::getYPos() {
	return iTextYPos;
}