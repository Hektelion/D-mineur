#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include "../lib/SDL2/include/SDL.h"
#include "../lib/SDL2/include/SDL_ttf.h"

int init_SDL();
int init_SDL_TTF();
int create_window(SDL_Window **window);
int create_renderer(SDL_Window *window, SDL_Renderer **renderer);
int init_System(SDL_Window *window, SDL_Renderer **renderer);

void close_window(SDL_Window *window);
void close_renderer(SDL_Renderer *renderer);
void close_System(SDL_Window *window, SDL_Renderer *renderer);

#endif //__SYSTEM_HPP__
