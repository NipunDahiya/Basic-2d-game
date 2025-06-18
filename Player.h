#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>



class Player
{private: 
	sf::RectangleShape shape;
	int hp;
	int hpMax;

	float movementSpeed;
	void initVaraibles();
	void initShape();


public : 
	Player(float x=0.f,float y=0.f);
	virtual ~Player();

	// Accessors 
	const sf::RectangleShape& getShape() const;
	const int& getHP() const;
	const int& getHpMax() const;

	// Functions 
	void takeDamage(const int damage);
	void gainHealth(const int health);


	void updateInput();
	void updateWindowBoundCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};

