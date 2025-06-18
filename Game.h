#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>

#include "Player.h"
#include "Balls.h"



class Game {

private: 

	sf::VideoMode videomode; 
	sf::RenderWindow* window;
	bool endGame; 
	sf::Event sfmlEvent;
	int points;

	sf::Font font; 
	sf::Text guiText; 
	sf::Text endGameText;


	Player player;

	std::vector<Balls> Ball;
	float spawnTimerMax;
	float spawnTimer;
	int maxBalls;


	void initVaraibles();
	void initWindow();
	void initFont();
	void initText();


public : 
	Game();
	~Game();

	// Accessors 
	const bool& getEndGame() const;

	//Modifiers 


	//Functions 

	const bool running() const;
	void pollEvents();


	void spawnBalls();
	const int randamizeType();
	void updatePlayer();
	void updateCollision();
	void updateGUI();
	void update();
	void renderGUI(sf::RenderTarget* target);
	void render();


};





