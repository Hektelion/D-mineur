#include "../include/logic.hpp"
//#include "../include/system.hpp"
#include "../include/constant.hpp"
#include "../include/class.hpp"
#include "../include/draw.hpp"

#include "../lib/SDL2/include/SDL.h"
//#include "../lib/SDL2/include/SDL_ttf.h"

#include <iostream>
#include <vector>
//#include <string>

using namespace std;

int playMinesweeper(int difficulty, SDL_Renderer *renderer)
{
	SDL_Point point;

	int nb_row;
	int nb_column;
	int nbBomb;

	bool isOver = true;

	if(difficulty == 0)
	{
		nb_row = 8;
		nb_column = 16;
		nbBomb = 20;
	}
	else
	{
		nb_row = 16;
		nb_column = 32;
		nbBomb = 50;
	}

	vector< vector<SDL_Rect> > graphic_field(nb_column);

	for (int i = 0; i < nb_column; i++) {
        graphic_field[i] = vector<SDL_Rect>(nb_row);
    }

	PARTIE game(nb_row, nb_column, nbBomb);

	SDL_Event event;
	do{
		initDrawGAME(renderer, graphic_field);
		drawGAME(renderer, graphic_field);

		//Mise a jour des événement
		while ( SDL_PollEvent(&event) ) // Nous traitons les événements de la queue
		{
			switch (event.type) {
				case SDL_MOUSEMOTION:
					point.x = event.motion.x;
					point.y = event.motion.y;
				break;
				case SDL_MOUSEBUTTONDOWN:
					switch (event.button.button) {
						case SDL_BUTTON_LEFT:
							for(int i=0 ; i<graphic_field.size() ; i++){
								for(int j=0 ; j<graphic_field[i].size() ; j++){
									if(SDL_PointInRect(&point, &graphic_field[i][j]) == SDL_TRUE)
									{
										isOver = game.leftClic(point.x, point.y);
									}
								}
							}
						break;
						case SDL_BUTTON_RIGHT:
							for(int i=0 ; i<graphic_field.size() ; i++){
								for(int j=0 ; j<graphic_field[i].size() ; j++){
									if(SDL_PointInRect(&point, &graphic_field[i][j]) == SDL_TRUE)
									{
										isOver = game.rightClic(point.x, point.y);
									}
								}
							}
						break;
					}
				break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode) {
						case SDL_SCANCODE_ESCAPE:
							return 0;
						break;
					}
				break;
				default:

				break;
			}
		}
	}
	while(isOver);

}
