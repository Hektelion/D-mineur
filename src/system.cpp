#include "../include/system.hpp"
#include "../include/constant.hpp"
#include <iostream>

#include "../lib/SDL2/include/SDL.h"
#include "../lib/SDL2/include/SDL_ttf.h"

/* Entrées    :
* Sorties    : Le code d'erreur de la fonction
* Variables  :
* Traitement : Initialise la SDL et gère les erreur en
affichant un log dans la console.
(Cette bibliothèque sert à l'interface graphique)
*/
int init_SDL(){
	//============================================
	//			INITIALISATION DE SDL2
	//============================================

	//LOG
	if(MODE_DEBUG) std::cout << "Initialisation de la bibliothèque SDL..." << std::endl;
	//Initialisation de la SDL
	if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0 ){
		std::cerr << "Erreur SDL_Init : " << SDL_GetError() << std::endl;
		//Probleme dans l'initialisation
		return EXIT_FAILURE;
	}
	//LOG
	if(MODE_DEBUG) std::cout << "Initialisation de la bibliothèque SDL : OK" << std::endl;

	//Initialisation OK
	return EXIT_SUCCESS;
}

/* Entrées    :
* Sorties    : Le code d'erreur de la fonction
* Variables  :
* Traitement : Initialise la SDL_TTF et gère les erreur en
affichant un log dans la console.
(Cette bibliothèque permet l'ouverture de fichier .ttf
ce qui permet d'afficher du texte dans l'interface)
*/
int init_SDL_TTF(){
	//============================================
	//			INITIALISATION DE SDL_ttf
	//============================================

	//LOG
	if(MODE_DEBUG) std::cout << "Initialisation de la bibliothèque SDL_ttf..." << std::endl;
	//Initialisation de TTF
	if(!TTF_WasInit() && TTF_Init()==-1){
		std::cerr << "Erreur TTF_Init :  : " << TTF_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	//LOG
	std::cout << "Initialisation de la bibliothèque SDL_ttf : OK" << std::endl;
	return EXIT_SUCCESS;
}

/* Entrées    : window (une fenetre)
* Sorties    : Le code d'erreur de la fonction
* Variables  :
* Traitement : Crée la fenetre d'apres des constantes
et gère l'erreur en affichant un log dans la console.
*/
int create_window(SDL_Window **window){
	//============================================
	//			CREATION DE LA FENETRE
	//============================================

	if(MODE_DEBUG) std::cout << "Création de la fenetre..." << std::endl;

	//Création de la fenetre
	*window = SDL_CreateWindow("D-mineur",	//Nom de la fenetre
	0,	//Origine x
	0,	//Origine y
	WIDTH,	//Largeur
	HEIGHT,	//Hauteur
	SDL_WINDOW_RESIZABLE);	//Flags

	//Gestion de l'erreur si la fenetre n'a pas été crée
	if(*window == NULL){
		std::cerr << "Erreur SDL_CreateWindow :  : " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if(MODE_DEBUG) std::cout << "Création de la fenetre : OK" << std::endl;

	return EXIT_SUCCESS;
}

/* Entrées    : window (une fenetre), renderer (un moteur de rendu)
* Sorties    : Le code d'erreur de la fonction
* Variables  :
* Traitement : Crée le moteur de rendu en le liant à la fenetre
et gère l'erreur en affichant un log dans la console
*/
int create_renderer(SDL_Window *window, SDL_Renderer **renderer){
	//============================================
	//		CREATION DU MOTEUR DE RENDU
	//============================================

	if(MODE_DEBUG) std::cout << "Création du moteur de rendu..." << std::endl;

	//Création du moteur de rendu
	(*renderer) = SDL_CreateRenderer(window,	//Fenetre cible du moteur de rendu
		-1,		//Index
		SDL_RENDERER_ACCELERATED);		//Flags

		//Gestion de l'erreur si le moteur de rendu n'a pas été crée
		if( (*renderer) == NULL){
			std::cerr << "Erreur SDL_CreateRenderer :  : " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}

		if(MODE_DEBUG) std::cout << "Création du moteur de rendu : OK" << std::endl;

		return EXIT_SUCCESS;
	}

	/* Entrées    : window (une fenetre), renderer (un moteur de rendu)
	* Sorties    : Le code d'erreur de la fonction
	* Variables  :
	* Traitement : Initialise les bibliothèques et elements necessaire
	de l'interface graphique
	*/
	int init_System(SDL_Window *window, SDL_Renderer **renderer){
		if( init_SDL() ){
			return EXIT_FAILURE;
		}
		if( init_SDL_TTF() ){
			return EXIT_FAILURE;
		}
		if( create_window(&window) ){
			return EXIT_FAILURE;
		}
		if( create_renderer(window, renderer ) ){
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}

	/* Entrées    : window (une fenetre)
	* Sorties    :
	* Variables  :
	* Traitement : Detruit la fenetre si elle à été crée
	*/
	void close_window(SDL_Window *window){
		//============================================
		//		DESTRUCTION DE LA FENETRE
		//============================================

		//Si la fenetre est initialisée
		if(window != NULL){
			if(MODE_DEBUG) std::cout << "Destruction de la fenetre" << std::endl;
			SDL_DestroyWindow(window);
		}
	}

	/* Entrées    : renderer (un moteur de rendu)
	* Sorties    :
	* Variables  :
	* Traitement : Detruit le moteur de rendu si elle à été crée
	*/
	void close_renderer(SDL_Renderer *renderer){
		//============================================
		//		DESTRUCTION DU MOTEUR DE RENDU
		//============================================

		if(renderer != NULL){
			if(MODE_DEBUG) std::cout << "Destruction du moteur de rendu" << std::endl;
			SDL_DestroyRenderer(renderer);
		}
	}

	/* Entrées    : window (une fenetre), renderer (un moteur de rendu)
	* Sorties    :
	* Variables  :
	* Traitement : Quitte les bibliothèques utilisé et les elements de l'interface graphique
	*/
	void close_System(SDL_Window *window, SDL_Renderer *renderer){
		close_window(window);
		close_renderer(renderer);

		if(MODE_DEBUG) std::cout << "SDL_TTF Quitte" << std::endl;
		TTF_Quit();

		if(MODE_DEBUG) std::cout << "SDL Quitte" << std::endl;
		SDL_Quit();
		//fprintf(stdout, "L'application n'a rencontrer aucun problème\n");
	}
