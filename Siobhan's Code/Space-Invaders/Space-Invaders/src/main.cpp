#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "startText.h"

using namespace std;

void startScreen();
void startText(string sText, sf::Font font, int iCharSize);

int iWindowW = 1920; //window width
int iWindowH = 1080; //window height

int main() {
	//go to start screen
	while (1) {
		startScreen();
	}
	return 0;
}

void startScreen() {
	//define variables
	int iFps = 60; //frame rate per second

	//set font
	sf::Font font;
	font.loadFromFile("assets/fonts/unifont.ttf");

	//set character size
	int iCharSize = 48;

	//create full screen window
	sf::RenderWindow window(sf::VideoMode(iWindowW, iWindowH), "Space Invaders", sf::Style::Fullscreen);
	window.setFramerateLimit(iFps);

	while (window.isOpen()) {
		//check all user events
		sf::Event event;
		while (window.pollEvent(event)) {
			//user has pressed the close button
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Q) {
					window.close();
				}
			}
		}

		//set background to black
		window.clear(sf::Color::Black);

		//create text for title
		StartText title;
		title.setFont(font); // font not being registered correctly - Ben
		title.setText("SPACE INVADERS");
		title.setCharSize(iCharSize);
		title.setPosition(iWindowW, 0, 0);
		
		//create text for click here button
		StartText clickHere;
		clickHere.setFont(font);
		clickHere.setText("CLICK HERE TO PLAY!");
		clickHere.setCharSize(iCharSize);
		clickHere.setPosition(iWindowW, title.getYPos(), 20);

		//create text for score advance table title
		StartText scoreA;
		scoreA.setFont(font);
		scoreA.setText("*SCORE ADVANCE TABLE*");
		scoreA.setCharSize(iCharSize);
		scoreA.setPosition(iWindowW, clickHere.getYPos(), 300);


		//draw to window
		title.drawText(window);
		clickHere.drawText(window);
		scoreA.drawText(window);


		//display what has been drawn to screen
		window.display();
	}
}

void game() {
	//define variables
	int level = 0;
	int lives = 3;
}



