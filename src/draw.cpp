#include "../include/draw.hpp"
#include "../include/constant.hpp"
#include <iostream>
#include <math.h>

#include "../lib/SDL2/include/SDL.h"
#include "../lib/SDL2/include/SDL_ttf.h"

static SDL_Rect options_menu[6];
static SDL_Rect menu;
SDL_Rect title;

/* Entrées    : renderer (un moteur de rendu), origin (un point), ray (un entier)
 * Sorties    :
 * Variables  : point (un point), n (un entier)
 * Traitement : Cette fonction dessine un cercle plein à l'écran
 */
void drawCircle(SDL_Renderer *renderer, SDL_Point origin, int ray){
	SDL_Point point;
	int n=100;

	for(int i=0 ; i<n ; i++){
		point.x = origin.x + ray * cos( (i+1) * ((2*M_PI)/n) );
		point.y = origin.y + ray * sin( (i+1) * ((2*M_PI)/n) );
		SDL_RenderDrawLine(renderer, origin.x, origin.y, point.x, point.y);
	}

}

/* Entrées    : renderer (un moteur de rendu)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier)
 * Traitement : Cette fonction initialise les elements utilisé dans l'intro
 */
int initDrawINTRO(SDL_Renderer *renderer){
	int width;
    int heigth;

    //Récupération de la taille de l'affichage
    SDL_GetRendererOutputSize(renderer, &width, &heigth);



	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu)
 * Sorties    :
 * Variables  :
 * Traitement : Dessine à l'écran l'introduction du jeu puis effectue une pause
 */
void drawINTRO(SDL_Renderer *renderer){

	//Background Noir
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
}

/* Entrées    : renderer (un moteur de rendu), title (un rectangle),
			 	menu (un rectangle), options (un tableau de rectangle)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier)
 * Traitement : Cette fonction initialise les elements utilisé dans le dessin du menu
 */
int initDrawMENU(SDL_Renderer *renderer){
	int width;
    int heigth;

    //Récupération de la taille de l'affichage
    SDL_GetRendererOutputSize(renderer, &width, &heigth);

	//Initialisation du titre
    title.h = heigth/10;
    title.w = width/2;
    title.x = width/4;
    title.y = heigth/50;

	//Initialisation de la partie menu
    menu.h = heigth - (title.h + 3*title.y);
    menu.w = 6*(width/8);
    menu.x = width/8;
    menu.y = title.h + 2*title.y;

	//Initialisation des options
    for(int i=0 ; i<NB_OPTION ; i++){
        options_menu[i].h = (menu.h - title.y) / NB_OPTION - title.y;
        options_menu[i].w = menu.w - 2*title.y;
        options_menu[i].x = menu.x + title.y;
        options_menu[i].y = menu.y + i * (options_menu[i].h + title.y) + title.y;
    }

	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu), title (un rectangle),
			 	menu (un rectangle), options (un tableau de rectangle)
 * Sorties    :
 * Variables  :
 * Traitement : Cette fonction dessine les éléments du menu
 */
void drawMENU(SDL_Renderer *renderer){

	//Background Blanc
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0,125,125,125);
    SDL_RenderDrawRect(renderer, &title);
    SDL_SetRenderDrawColor(renderer, 125,0,125,125);
    SDL_RenderDrawRect(renderer, &menu);
    SDL_SetRenderDrawColor(renderer, 125,125,0,125);
    for(int i=0 ; i<NB_OPTION ; i++){
        SDL_RenderDrawRect(renderer, &options_menu[i]);
    }

    SDL_RenderPresent(renderer);
}

/* Entrées    : renderer (un moteur de rendu), carreau (un tableau 2D de rectangles)
 * Sorties    : Le code d'erreur de la fonction
 * Variables  : width (un entier), heigth (un entier), ecart (un entier)
 * Traitement : Cette fonction initialise les elements
 				utilisé dans le dessin du plateau
 */
int initDrawGAME(SDL_Renderer *renderer){
	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu), o (un tableau 2D de caractères),
				player (un entier)
 * Sorties    :
 * Variables  : nbMove (un entier), c_possible (un tableau de coup)
 * Traitement : Cette fonction dessine les éléments du jeu
 */
void drawGAME(SDL_Renderer *renderer){

}
