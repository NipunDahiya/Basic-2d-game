#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>


enum BallType {DEFAULT =0,DAMAGING, HEALING, NROFTYPE};


class Balls
{

private:
	sf::CircleShape shape;
	int type;
	void initShape(const sf::RenderWindow& window);

public:
	Balls(const sf::RenderWindow& window, int type );
	virtual ~Balls();

	// Accessors 
	const sf::CircleShape getShape() const;
	const int& getType() const; 

	// Funtions 
	void update();
	void render(sf::RenderTarget& target);

};

