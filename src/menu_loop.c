#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#include <SDL2/SDL.h>

int menu_loop()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window=SDL_CreateWindow("map creator",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	SDL_Event event;
	Uint8* keystate=SDL_GetKeyboardState(NULL);

	int return_value;
	int running=1;
	while (running)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					return_value=0;
					running=0;
					break;
			}
		}
		if(keystate[SDL_SCANCODE_ESCAPE])
		{
			return_value=2;
			running=0;
		}
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	return return_value;
}
