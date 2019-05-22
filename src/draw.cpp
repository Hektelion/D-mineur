#include "../include/draw.hpp"
#include "../include/constant.hpp"
//#include <iostream>
#include <math.h>

#include "../lib/SDL2/include/SDL.h"
#include "../lib/SDL2/include/SDL_ttf.h"
#include "../lib/SDL2/include/SDL_image.h"

#include <iostream>
#include <vector>

using namespace std;

static SDL_Rect options_menu[NB_OPTION];
static SDL_Rect menu;
static SDL_Rect title;

static SDL_Rect panel;

static SDL_Surface *blank = NULL;
static SDL_Surface *one = NULL;
static SDL_Surface *two = NULL;
static SDL_Surface *three = NULL;
static SDL_Surface *four = NULL;
static SDL_Surface *five = NULL;
static SDL_Surface *six = NULL;
static SDL_Surface *seven = NULL;
static SDL_Surface *eight = NULL;
static SDL_Surface *bomb = NULL;
static SDL_Surface *flag = NULL;

static SDL_Texture *texture = NULL;

//Charge une image est l'optimise
SDL_Surface *load_image( string filename )
{
	if(LOG_APPEL_FONCTION) std::cout << "Appel de load_image " << filename << std::endl;

	SDL_Surface* loadIm = NULL;
	SDL_Surface* opti = NULL;

	loadIm = SDL_LoadBMP( filename.c_str() );
	if( loadIm != NULL )
	{
		opti = SDL_ConvertSurfaceFormat( loadIm, SDL_PIXELFORMAT_RGBA4444, 0 );
		SDL_FreeSurface( loadIm );
	}
	else
	{
		std::cerr << "Erreur SDL_LoadBMP : " << SDL_GetError() << std::endl;
	}

	if( loadIm == NULL )
	{
		std::cerr << "Erreur SDL_ConvertSurfaceFormat : " << SDL_GetError() << std::endl;
	}

	return opti;
}

//Charge toutes les image dans des surfaces
void loadData(){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de loadData" << std::endl;

	blank = load_image( "./images/blank.bmp" );
	one = load_image( "./images/1.bmp" );
	two = load_image( "./images/2.bmp" );
	three = load_image( "./images/3.bmp" );
	four = load_image( "./images/4.bmp" );
	five = load_image( "./images/5.bmp" );
	six = load_image( "./images/6.bmp" );
	seven = load_image( "./images/7.bmp" );
	eight = load_image( "./images/8.bmp" );
	bomb = load_image( "./images/bomb.bmp" );
	flag = load_image( "./images/flag.bmp" );
}

//libere les surface
void freeData(){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de freeData" << std::endl;

	SDL_FreeSurface( blank );
	SDL_FreeSurface( one );
	SDL_FreeSurface( two );
	SDL_FreeSurface( three );
	SDL_FreeSurface( four );
	SDL_FreeSurface( five );
	SDL_FreeSurface( six );
	SDL_FreeSurface( seven );
	SDL_FreeSurface( eight );
	SDL_FreeSurface( bomb );
	SDL_FreeSurface( flag );
}

/* Entrées    : renderer (un moteur de rendu), origin (un point), ray (un entier)
* Sorties    : -
* Variables  : point (un point), n (un entier)
* Traitement : Cette fonction dessine un cercle plein à l'écran
*/
void drawCircle(SDL_Renderer *renderer, SDL_Point origin, int ray){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de drawCircle" << std::endl;

	SDL_Point point;
	int n=100;

	for(int i=0 ; i<n ; i++){
		point.x = origin.x + ray * cos( (i+1) * ((2*M_PI)/n) );
		point.y = origin.y + ray * sin( (i+1) * ((2*M_PI)/n) );
		SDL_RenderDrawLine(renderer, origin.x, origin.y, point.x, point.y);
	}

}

/* Entrées    : -
* Sorties    : -
* Variables  : -
* Traitement : Renvoi le tableau statique options_menu
*/
SDL_Rect *get_options_menu(){
	return options_menu;
}

/* Entrées    : renderer (un moteur de rendu)
* Sorties    : Le code d'erreur de la fonction
* Variables  : width (un entier), heigth (un entier)
* Traitement : Cette fonction initialise les elements utilisé dans l'intro
*/
int initDrawINTRO(SDL_Renderer *renderer){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de initDrawINTRO" << std::endl;

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
	if(LOG_APPEL_FONCTION) std::cout << "Appel de drawINTRO" << std::endl;

	//Background Noir
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	SDL_RenderClear(renderer);
}

/* Entrées    : renderer (un moteur de rendu)
* Sorties    : Le code d'erreur de la fonction
* Variables  : width (un entier), heigth (un entier)
* Traitement : Cette fonction initialise les elements utilisé dans le dessin du menu
*/
int initDrawMENU(SDL_Renderer *renderer){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de initDrawMENU" << std::endl;

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

/* Entrées    : renderer (un moteur de rendu)
* Sorties    :
* Variables  :
* Traitement : Cette fonction dessine les éléments du menu
*/
void drawMENU(SDL_Renderer *renderer){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de drawMENU" << std::endl;

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

/* Entrées    : renderer (un moteur de rendu), graphic_field (un vecteur de vecteur de rectangles)
* Sorties    : Le code d'erreur de la fonction
* Variables  : width (un entier), heigth (un entier)
* Traitement : Cette fonction initialise les elements
utilisé dans le dessin du plateau
*/
int initDrawGAME(SDL_Renderer *renderer, vector< vector<SDL_Rect> > & graphic_field){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de initDrawGAME" << std::endl;

	int width;
	int heigth;

	//Récupération de la taille de l'affichage
	SDL_GetRendererOutputSize(renderer, &width, &heigth);

	int side = width/graphic_field.size();
	SDL_Point field_origin;

	field_origin.x = 0;
	field_origin.y = heigth * (2.0/9.0);

	for(unsigned int i=0 ; i<graphic_field.size() ; i++){
		for(unsigned int j=0 ; j<graphic_field[i].size() ; j++){
			graphic_field[i][j].x = field_origin.x + i * side;
			graphic_field[i][j].y = field_origin.y + j * side;
			graphic_field[i][j].w = side;
			graphic_field[i][j].h = side;
		}
	}

	panel.x = 0;
	panel.y = 0;
	panel.w = width;
	panel.h = field_origin.x;

	return EXIT_SUCCESS;
}

/* Entrées    : renderer (un moteur de rendu), graphic_field (un vecteur de vecteur de rectangles), partie (les element du jeu)
* Sorties    :
* Variables  :
* Traitement : Cette fonction dessine les éléments du jeu
*/
void drawGAME(SDL_Renderer *renderer, vector< vector<SDL_Rect> > & graphic_field, PARTIE & partie){
	if(LOG_APPEL_FONCTION) std::cout << "Appel de drawGAME" << std::endl;

	int width;
	int heigth;

	//Récupération de la taille de l'affichage
	SDL_GetRendererOutputSize(renderer, &width, &heigth);

	//texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_Point p1;
	SDL_Point p2;

	//Background Blanc
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 127,127,127,255);
	SDL_RenderFillRect(renderer, &panel);

	for(unsigned int i=0 ; i<partie.field.visible.size() ; i++){
		for(unsigned int j=0 ; j<partie.field.visible[i].size() ; j++){
			switch (partie.field.visible[i][j]) {
				case '#':
					texture = SDL_CreateTextureFromSurface(renderer, blank);
				break;
				case '.':
					texture = SDL_CreateTextureFromSurface(renderer, blank);
				break;
				case '1':
					texture = SDL_CreateTextureFromSurface(renderer, one);
				break;
				case '2':
					texture = SDL_CreateTextureFromSurface(renderer, two);
				break;
				case '3':
					texture = SDL_CreateTextureFromSurface(renderer, three);
				break;
				case '4':
					texture = SDL_CreateTextureFromSurface(renderer, four);
				break;
				case '5':
					texture = SDL_CreateTextureFromSurface(renderer, five);
				break;
				case '6':
					texture = SDL_CreateTextureFromSurface(renderer, six);
				break;
				case '7':
					texture = SDL_CreateTextureFromSurface(renderer, seven);
				break;
				case '8':
					texture = SDL_CreateTextureFromSurface(renderer, eight);
				break;
				case 'B':
					texture = SDL_CreateTextureFromSurface(renderer, bomb);
				break;
				case 'F':
					texture = SDL_CreateTextureFromSurface(renderer, flag);
				break;
			}
			SDL_RenderCopy(renderer, texture, NULL, &graphic_field[i][j]);
			SDL_DestroyTexture(texture);
		}
	}

	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	for(unsigned int i=1 ; i<graphic_field.size() ; i++){
		p1.x = graphic_field[i][0].x;
		p1.y = graphic_field[i][0].y;

		p2.x = graphic_field[i][0].x;
		p2.y = heigth;

		SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
	}

	for(unsigned int i=1 ; i<graphic_field[i].size() ; i++){
		p1.x = 0;
		p1.y = graphic_field[0][i].y;

		p2.x = width;
		p2.y = graphic_field[0][i].y;

		SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
	}

	SDL_RenderPresent(renderer);
}
