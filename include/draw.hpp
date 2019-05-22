#ifndef __DRAW_HPP__
#define __DRAW_HPP__

#include "../lib/SDL2/include/SDL.h"
//#include "../lib/SDL2/include/SDL_ttf.h"

#include "class/partie.hpp"

#include <iostream>
#include <vector>

using namespace std;

SDL_Surface *load_image( string filename );
void loadData();
void freeData();

void drawCircle(SDL_Renderer *renderer, SDL_Point origin, int ray);
SDL_Rect *get_options_menu();

int initDrawINTRO(SDL_Renderer *renderer);
void drawINTRO(SDL_Renderer *renderer);

int initDrawMENU(SDL_Renderer *renderer);
void drawMENU(SDL_Renderer *renderer);

int initDrawGAME(SDL_Renderer *renderer, vector< vector<SDL_Rect> > & graphic_field);
void drawGAME(SDL_Renderer *renderer, vector< vector<SDL_Rect> > & graphic_field, PARTIE & partie);

#endif //__DRAW_HPP__
