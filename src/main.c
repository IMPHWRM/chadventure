#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "menu.h"
#include "game.h"

#include "src_file.c"
int main(int argc,char* argv[])
{
	printf("Start main function.\n");
	SDL_Init(SDL_INIT_EVENTS);

	int state=1;
	int running=1;
	while(running)
	{
		switch(state)
		{
			//menu
			case 1:
				printf("Open menu loop.\n");
				state=menu_loop();
				printf("Quit menu loop.\n");
				break;
			//game
			case 2:
				printf("Open game loop.\n");
				state=game_loop();
				printf("Quit game loop.\n");
				break;
			//end
			case 0:
				running=0;
				printf("Quit prog.\n");
				break;
			default :
				running=0;
		}
	}
	SDL_Quit();
	return 0;
}
