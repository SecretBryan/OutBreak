#include "Events.h"
#include "Movement.h"
#include "SDL.h"

Events::Events()
{

}

void Events::gameEvents(SDL_Event &event,Movement &move)
{
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			gameRunning=false;
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					gameRunning=false;
					break;
				case SDLK_a:
					move.setPlayerDir(0,true);
					break;
				case SDLK_w:
					move.setPlayerDir(1,true);
					break;
				case SDLK_d:
					move.setPlayerDir(2,true);
					break;
				case SDLK_s:
					move.setPlayerDir(3,true);
					break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					move.setPlayerDir(0,false);
					break;
				case SDLK_w:
					move.setPlayerDir(1,false);
					break;
				case SDLK_d:
					move.setPlayerDir(2,false);
					break;
				case SDLK_s:
					move.setPlayerDir(3,false);
					break;
			}
			break;
		}
	}
}

bool getGameState()
{
	return gameRunning;
}