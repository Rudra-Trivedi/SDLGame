#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->init("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
	while (game->isRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}