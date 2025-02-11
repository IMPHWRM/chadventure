#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "menu_loop.c"
#include "game_loop.c"

int main(int argc,char* argv[])
{
	printf("Start main function.\n");
	SDL_Init(SDL_INIT_EVENTS);

	int state=1;
	int running=1;
	while(running)
	{
		if(state==1)
		{
			printf("Open menu loop.\n");
			state=menu_loop();
			printf("Quit menu loop.\n");
		}
		if(state==2)
		{
			printf("Open game loop.\n");
			state=game_loop();
			printf("Quit game loop.\n");
		}
		if(state==0)
		{
			running=0;
			printf("Quit prog.\n");
		}
	}
	SDL_Quit();
	return 0;
}
