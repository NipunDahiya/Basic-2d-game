#include <iostream>
#include "Game.h"

int main() {

	// Initialize random seed 
	srand(static_cast<unsigned>(time(0)));


	// Initialize game object;
	Game game;

	// Game loop 
	while (game.running())
	{
		game.update();
		game.render();
	}


	return 0;

}