#include "Game.h"

//Private Funct
void Game::initVar()
{
	this->window = nullptr;

	//Game Logic
	this->points = 0;
	this->MoveCounter = 0;
	this->BulletSpawnTimerMax = 100.f;
	this->BulletSpawnTimer = this->BulletSpawnTimerMax;
	this->InvadersAlive = false;
	this->PlayerAlive = false;
}

void Game::initWindow()
{
	sf::VideoMode Fullscreen = sf::VideoMode::getDesktopMode();
	this->videoMode.height = Fullscreen.height;
	this->videoMode.width = Fullscreen.width;

	this->window = new sf::RenderWindow(sf::VideoMode(Fullscreen.width, Fullscreen.height), "Space Invaders", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

	this->window->setFramerateLimit(144);
}

void Game::initEnemies()
{
	this->Invader.setPosition(10.f, 10.f);
	this->Invader.setSize(sf::Vector2f(this->videoMode.width/40, this->videoMode.height/25));
	this->Invader.setScale(1.f, 1.f);
	this->Invader.setFillColor(sf::Color::White);
	this->Invader.setOutlineColor(sf::Color::Cyan);
	this->Invader.setOutlineThickness(1.f);
	
	/*if (!Invader1.loadFromFile("Invader.jpeg"))
	{
		std::cout << ("Couldnt Fetch Texture: Invader.jpeg");
	}*/
}

void Game::initPlayers()
{
	this->Player.setPosition(10.f, 10.f);
	this->Player.setSize(sf::Vector2f(this->videoMode.width / 30, this->videoMode.height / 25));
	this->Player.setScale(1.f, 1.f);
	this->Player.setFillColor(sf::Color::Green);
	this->Player.setOutlineColor(sf::Color::Black);
	this->Player.setOutlineThickness(1.f);
}

void Game::initBullets()
{
	this->Bullet.setPosition(10.f, 10.f);
	this->Bullet.setSize(sf::Vector2f(this->videoMode.width / 150, this->videoMode.height / 30));
	this->Bullet.setScale(1.f, 1.f);
	this->Bullet.setFillColor(sf::Color::Red);
	this->Bullet.setOutlineColor(sf::Color::Black);
	this->Bullet.setOutlineThickness(1.f);
}


//Constructors
Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initEnemies();
	this->initPlayers();
	this->initBullets();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::initShields()
{

}

void Game::spawnEnemy()
{
	for (int i = 0; i < 11; i++)
	{
		for (int y = 0; y < 5; y++)
		{
		this->Invader.setPosition((this->Invader.getGlobalBounds().width * 1.5f) * (i+1), (this->Invader.getGlobalBounds().height * 1.5 * (y+1)) + this->Invader.getGlobalBounds().height * 2);
		/*if (y = 0)
			this->Invader.setTexture(&this->Invader1, false);*/
		this->Invader.setFillColor(sf::Color::White);
		this->Invader.setOutlineColor(sf::Color::Black);
		this->Invaders.push_back(this->Invader);
		}
	}
}

void Game::spawnPlayer()
{
	this->Player.setPosition((this->videoMode.width/2)-(this->Player.getGlobalBounds().width/2), (this->videoMode.height) - (this->Player.getGlobalBounds().height*1.5));
	this->Player.setFillColor(sf::Color::Green);
	this->Player.setOutlineColor(sf::Color::Black);
	this->Players.push_back(this->Player);
}

void Game::spawnBullet()
{
	this->Bullet.setPosition((this->Players[0].getPosition().x + (this->Players[0].getGlobalBounds().width / 2)), (this->Players[0].getPosition().y));
	this->Bullet.setFillColor(sf::Color::Red);
	this->Bullet.setOutlineColor(sf::Color::Black);
	this->Bullets.push_back(this->Bullet);
}


//Functions
void Game::PollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
			this->window->close();
			break;
		}
	}
}

void Game::UpdateEnemies()
{
	if (!this->InvadersAlive)
	{
		spawnEnemy();
		this->InvadersAlive = true;
	}

	for (int i = 0; i < this->Invaders.size(); i++)
	{
		if (this->MoveCounter < 720)
			Invaders[i].move(this->Invader.getGlobalBounds().width / 36,0.f);
		else if (this->MoveCounter == 720)
			Invaders[i].move(0.f,this->Invader.getGlobalBounds().height);
		else if (this->MoveCounter > 720 && this->MoveCounter < 1440)
			Invaders[i].move(-(this->Invader.getGlobalBounds().width) / 36, 0.f);
		else
		{
			Invaders[i].move(0.f, this->Invader.getGlobalBounds().height);
		}

		for (int y = 0; y < this->Bullets.size(); y++)
		{
			if (Invaders[i].getGlobalBounds().contains(this->Bullets[y].getPosition().x + (this->Bullets[y].getGlobalBounds().width / 2), this->Bullets[y].getPosition().y))
			{
				this->points += 100;
				this->Invaders.erase(this->Invaders.begin() + i);
				this->Bullets.erase(this->Bullets.begin() + y);
			}
		}
	}
	if (MoveCounter != 1440)
	{
		MoveCounter += 1.f;
	}
	else
		MoveCounter = 0;
}

void Game::UpdatePlayer()
{
	if (!this->PlayerAlive)
	{
		spawnPlayer();
		this->PlayerAlive = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		float width = this->videoMode.width;
		this->Players[0].move(sf::Vector2f(-(width / 1250), 0.f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		float width = this->videoMode.width;
		this->Players[0].move(sf::Vector2f((width / 1250), 0.f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (this->BulletSpawnTimer >= this->BulletSpawnTimerMax)
		{
			this->BulletSpawnTimer = 0.f;
			spawnBullet();
		}
	}

	this->BulletSpawnTimer += 1.f;

}

void Game::UpdateBullet()
{
	for (auto& e : this->Bullets)
	{
		float height = this->videoMode.height;
		e.move(0.f, -(height / 150));
	}
}

void Game::spawnShield()
{

}

void Game::UpdateShields()
{

}

void Game::UpdateMousePosition()
{
	this->MousePosWindow = sf::Mouse::getPosition(*this->window);
	this->MousePosView = this->window->mapPixelToCoords(this->MousePosWindow);
}

void Game::Update()
{
	this->PollEvents();

	this->UpdateMousePosition();

	this->UpdateEnemies();

	this->UpdatePlayer();

	this->UpdateBullet();
}

void Game::RenderObjects()
{
	for (auto& e : this->Invaders)
	{
		this->window->draw(e);
	}

	for (auto& e : this->Players)
	{
		this->window->draw(e);
	}

	for (auto& e : this->Bullets)
	{
		this->window->draw(e);
	}
}

void Game::Render()
{
	this->window->clear(sf::Color::Black);

	//Draw Game
	this->RenderObjects();

	this->window->display();
}
