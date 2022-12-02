// Import Intput/Output stream
#include <iostream>

// Import time
#include <time.h>

// Import Game class
#include "Game.h"

// MAIN FUNCTION
int main()
{
	// INIT SEED
	srand(static_cast<unsigned>(time(0)));

	// Creatiin game object
	Game game;
	game.run();


	// End of application
	return 0;
}