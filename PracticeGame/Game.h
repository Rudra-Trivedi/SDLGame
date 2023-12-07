#pragma once
#include "SDL.h"
class Game
{
public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool bfullScreen);
	void update();
	void render();
	void clean(); 
	void handleEvents(); 

	bool isRunning() { return bIsRunnning; }

private:

	bool bIsRunnning;

	SDL_Window* window;
	SDL_Renderer* renderer;

};

