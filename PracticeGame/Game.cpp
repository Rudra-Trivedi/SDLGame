#include "Game.h"
#include <stdio.h>


Game::Game()
{

}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool bfullScreen)
{
	int flags = 0;
	if (bfullScreen) flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf(" Subsystems initalized \n");

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			printf("Window Created \n");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			printf("Renderer Created \n");
		}
		bIsRunnning = true; 
	}

	else
	{
		bIsRunnning = false;
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game Cleaned \n");
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			bIsRunnning = false;
			break;

		default:
			break;
	}
}


