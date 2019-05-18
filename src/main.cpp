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

	SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

	SDL_Point mouse;
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
		drawMENU(renderer);

		//texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", c_Noir);

        SDL_Event event;

        //Traitement des la file d'evenements
        while ( SDL_PollEvent(&event) )
        {
            switch (event.type) {
                case SDL_MOUSEMOTION:
                    mouse.x = event.motion.x;
                    mouse.y = event.motion.y;
					std::cout << "mouse = (" << mouse.x << ',' << mouse.y << ')' << std::endl;
                break;
                case SDL_MOUSEBUTTONDOWN:
					std::cout << "Vous avez cliquer en (" << mouse.x << ',' << mouse.y << ')' << std::endl;
                break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode) {
						case SDL_SCANCODE_ESCAPE:
							std::cout << "Appui touche ESC" << std::endl << "L'application quitte" << std::endl;
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
