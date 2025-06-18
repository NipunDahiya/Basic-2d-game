#include "Game.h"

void Game::initVaraibles()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBalls=10;
	this->points = 0.f;


}

void Game::initWindow()
{
	this->videomode = sf::VideoMode(700, 500);
	this->window = new sf::RenderWindow(this->videomode, "G 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initFont()
{
	this->font.loadFromFile("Fonts/Dosis-Light.otf");

}

void Game::initText()
{
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(32);


	
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(70);
	this->endGameText.setString(" GAME OVER ... YUP  ");
	this->endGameText.setPosition(sf::Vector2f(100, 150));
}

Game::Game()
{
	this->initVaraibles();
	this->initWindow();
	this->initFont();
	this->initText();



}

Game::~Game()
{
	delete this->window; 
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}



void Game::spawnBalls()
{	
	//Timer 
	if (this->spawnTimer < this->spawnTimerMax) {
		this->spawnTimer += 1.f;

	}

	else {
		if (this->Ball.size() < this->maxBalls)
		{
			this->Ball.push_back(Balls(*this->window,this->randamizeType()));
		}
		this->spawnTimer = 0.f;
	}

}

const int Game::randamizeType()
{
	int type = BallType::DEFAULT;

	int randValue = rand() % 100 + 1;
	if (randValue > 30 && randValue <= 90)
	{
		type = BallType::DAMAGING;
	}
	else if (randValue>90)
		type = BallType::HEALING;

	return type;
}

void Game::updatePlayer()
{
	this->player.update(this->window);
	if (this->player.getHP() <= 0)
		this->endGame = true;

}

void Game::updateCollision()
{
	//Check the collision 
	for (size_t i = 0; i < this->Ball.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->Ball[i].getShape().getGlobalBounds()))
		{

			switch (this->Ball[i].getType())
			{

			case BallType::DEFAULT:
				this->points++;
				break;
			case BallType::DAMAGING:
				this->player.takeDamage(1);
				break;

			case BallType::HEALING:
				this->player.gainHealth(1);
				break;
			}

			this->Ball.erase(this->Ball.begin() + i);

		}

	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "POINTS : " << this->points<<"\n"<< "HEALTH : "<<this->player.getHP();
	this->guiText.setString(ss.str());

}

void Game::update()
{
	this->pollEvents();
	if (this->endGame == false)
	{

		this->spawnBalls();
		this->updatePlayer();
		this->updateCollision();
		this->updateGUI();

	}

}

void Game::renderGUI(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}


void Game::render()
{
	this->window->clear();

	//Render stuff 
	this->player.render(this->window);

	for (auto i : this->Ball) {
		i.render(*this->window);
	}

	//Render GUI 
	this->renderGUI(this->window);

	// RENDER END GAME TEXT 
	if (this->endGame) 
	{
		this->window->draw(this->endGameText);
	}

	// Main window display 
	this->window->display();

}


//Functions 


