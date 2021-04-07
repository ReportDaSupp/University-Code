#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

//Game Engine Class
class Game
{
private:

	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse Positions
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

	//Game Logic
	int MoveCounter;
	unsigned points;
	float BulletSpawnTimer;
	float BulletSpawnTimerMax;
	bool InvadersAlive;
	bool PlayerAlive;
	
	//Game Objects
	std::vector<sf::RectangleShape> Invaders;
	sf::RectangleShape Invader;
	std::vector<sf::RectangleShape> Players;
	sf::RectangleShape Player;
	std::vector<sf::RectangleShape> Bullets;
	sf::RectangleShape Bullet;
	sf::Texture Invader1;
	sf::Texture Invader2;
	sf::Texture Invader3;

	//Private Functions
	void initVar();
	void initWindow();
	void initEnemies();
	void initPlayers();
	void initBullets();
	void initShields();

public:

	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void spawnEnemy();
	void spawnPlayer();
	void spawnBullet();
	void spawnShield();
	void PollEvents();
	void UpdateEnemies();
	void UpdatePlayer();
	void UpdateBullet();
	void UpdateShields();
	void UpdateMousePosition();
	void Update();
	void RenderObjects();
	void Render();

};

