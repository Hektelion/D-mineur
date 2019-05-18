#ifndef __DRAW_HPP__
#define __DRAW_HPP__

#include "../lib/SDL2/include/SDL.h"
#include "../lib/SDL2/include/SDL_ttf.h"

void drawCircle(SDL_Renderer *renderer, SDL_Point origin, int ray);
SDL_Rect *get_options_menu();

int initDrawINTRO(SDL_Renderer *renderer);
void drawINTRO(SDL_Renderer *renderer);

int initDrawMENU(SDL_Renderer *renderer);
void drawMENU(SDL_Renderer *renderer);

int initDrawGAME(SDL_Renderer *renderer);
void drawGAME(SDL_Renderer *renderer);

#endif //__DRAW_HPP__
