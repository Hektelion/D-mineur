#include "../../include/class/partie.hpp"
//#include "../../include/class/grille.hpp"
#include "../../include/constant.hpp"

#include <iostream>

PARTIE::PARTIE(int nb_line, int nb_col, int nb_bomb) : field(GRILLE(nb_line, nb_col, nb_bomb))
{
	if(MODE_DEBUG) std::cout << "construction PARTIE" << std::endl;


}
PARTIE::~PARTIE()
{
	if(MODE_DEBUG) std::cout << "destruction PARTIE" << std::endl;
}

void PARTIE::begin()
{

}

bool PARTIE::rightClic(int x, int y)
{
	return true;
}

bool PARTIE::leftClic(int x, int y)
{
	return true;
}
