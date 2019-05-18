#include <iostream>
//#include <string>

#include "../lib/SDL2/include/SDL.h"
#include "../lib/SDL2/include/SDL_ttf.h"

#include "../include/class.hpp"
#include "../include/draw.hpp"
#include "../include/logic.hpp"
#include "../include/system.hpp"
#include "../include/constant.hpp"

int main(int argc, char **argv){
	//============================================
	//============== DECLARATION =================
	//============================================

	//Interface graphique
	SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
	SDL_Point mouse;
	SDL_Rect *options_menu;

	//
	char choice;

	//============================================
	//============= INITIALISATION ===============
	//============================================

	if( init_System(window, &renderer) ){
		return EXIT_FAILURE;
	}

	//============================================
	//================== DEBUT ===================
	//============================================

	initDrawINTRO(renderer);
    drawINTRO(renderer);

    do{
		initDrawMENU(renderer);
		options_menu = get_options_menu();
		drawMENU(renderer);

		//texte = TTF_RenderText_Blended(police, "Test", c_Noir);

        SDL_Event event;

        //Traitement des la file d'evenements
        while ( SDL_PollEvent(&event) )
        {
            switch (event.type) {
				//Evenement mouvement souris
                case SDL_MOUSEMOTION:
                    mouse.x = event.motion.x;
                    mouse.y = event.motion.y;
					//LOG
					//if(MODE_DEBUG) std::cout << "mouse = (" << mouse.x << ',' << mouse.y << ')' << std::endl;
                break;
				//Evenement bouton appuyé souris
                case SDL_MOUSEBUTTONDOWN:
					//LOG
					//if(MODE_DEBUG) std::cout << "Vous avez cliquer en (" << mouse.x << ',' << mouse.y << ')' << std::endl;
					if(SDL_PointInRect(&mouse, &options_menu[0]) == SDL_TRUE){
						//LOG
						if(MODE_DEBUG) std::cout << "Lancement d'une partie en mode facile" << std::endl;
						//playOthello('0', renderer);
					}
					else if(SDL_PointInRect(&mouse, &options_menu[1]) == SDL_TRUE){
						//LOG
						if(MODE_DEBUG) std::cout << "Lancement d'une partie en mode intermediaire" << std::endl;
						//playOthello('1', renderer);
					}
					else if(SDL_PointInRect(&mouse, &options_menu[2]) == SDL_TRUE){
						//LOG
						if(MODE_DEBUG)  std::cout << "QUITTER" << std::endl;
						choice = 'q';
					}
                break;
				//Evenement touche pressé
				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode) {
						//Evenement touche ESC
						case SDL_SCANCODE_ESCAPE:
							//Fermeture du systeme
							close_System( window, renderer );
							//LOG
							if(MODE_DEBUG) std::cout << "Appui touche ESC" << std::endl << "L'application quitte" << std::endl;
							//fermeture de l'application
							return EXIT_SUCCESS;
						break;
						default:

						break;
					}
				break;
				default:

				break;
            }
        }
    }
    while(choice != 'q'); // Tant que l'on veut que le jeu fonctionne

	//============================================
	//=================== FIN ====================
	//============================================

	close_System( window, renderer );

	return EXIT_SUCCESS;
}
