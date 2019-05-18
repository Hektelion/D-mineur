#include "../../include/class/grille.hpp"
#include "../../include/constant.hpp"

#include <iostream>

GRILLE::GRILLE(){
	nbRow = 8;
	nbColumn = 8;
	nbBombs = 10;
	remainBombs = 0;

	if(MODE_DEBUG) std::cout << "allocation de *grid" << std::endl;
	grid = new CASE*[nbColumn];

	if(*grid != NULL){
		for(int i=0 ; i<nbColumn ; i++){
			if(MODE_DEBUG) std::cout << "allocation de grid[" << i << ']' << std::endl;
			grid[i] = new CASE[nbRow];
			if(grid[i] == NULL) std::cerr << "allocation de grid[" << i << "] ERREUR" << std::endl;
		}
	}
	else std::cerr << "allocation de *grid[" << nbColumn << "] ERREUR" << std::endl;
}

GRILLE::GRILLE(int nb_line, int nb_col, int nb_bomb){
	nbRow = nb_line;
	nbColumn = nb_col;
	nbBombs = nb_bomb;
	remainBombs = 0;

	if(MODE_DEBUG) std::cout << "allocation de *grid" << std::endl;
	grid = new CASE*[nbColumn];

	if(*grid != NULL){
		for(int i=0 ; i<nbColumn ; i++){
			if(MODE_DEBUG) std::cout << "allocation de grid[" << i << ']' << std::endl;
			grid[i] = new CASE[nbRow];
			if(grid[i] == NULL) std::cerr << "allocation de grid[" << i << "] ERREUR" << std::endl;
		}
	}
	else std::cerr << "allocation de *grid[" << nbColumn << "] ERREUR" << std::endl;
}

GRILLE::~GRILLE(){
	for(int i=0 ; i<nbColumn ; i++){
		if(MODE_DEBUG) std::cout << "destruction de grid[" << i << ']' << std::endl;
		delete(grid[i]);
	}
	delete(grid);
	if(MODE_DEBUG) std::cout << "destruction GRILLE" << std::endl;
}
