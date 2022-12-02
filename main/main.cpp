#include <iostream>
#include <time.h>

#include "Game.h"

int main()
{
	// INIT SEED
	srand(static_cast<unsigned>(time(0)));

	Game game;
	game.run();


	// End of application
	return 0;
}