#include "player.h"

void Player::initVaraibles()
{
	this->movementSpeed = 5.f;
	this->hpMax = 10;
	this->hp = hpMax;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f,50.f));
	this->shape.setPosition(50.f, 300.f);

}

Player::Player(float x, float y)
{	
	this->shape.setPosition(x, y);
	this->initVaraibles();
	this->initShape();

}


Player::~Player()
{
	

}

const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}

const int& Player::getHP() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
		this->hp -= damage;

	if (this->hp < 0)
		this->hp = 0;

}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;

	if (this->hp > this->hpMax)
		this->hp = hpMax;

}

void Player::updateInput()
{

	//Keyboard input 
	//LEFT 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed,0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f,-this->movementSpeed);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f,this->movementSpeed);
	}
}

void Player::updateWindowBoundCollision(const sf::RenderTarget* target)
{
	//LEFT 

	sf::FloatRect playerBounds = this->shape.getGlobalBounds();

	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	}

	//RIGHT 

	else if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
	{

		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}

	//TOP
	
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left,0.f);
	}

	//BOTTOM

	else if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
	this->shape.setPosition(this->shape.getGlobalBounds().left,target->getSize().y-this->shape.getGlobalBounds().height);

}

void Player::update(const sf::RenderTarget* target)
{	
	this->updateInput();

	//Window bounds collision 
	this->updateWindowBoundCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);

}
