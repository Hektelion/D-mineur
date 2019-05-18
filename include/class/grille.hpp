#ifndef __GRILLE_HPP__
#define __GRILLE_HPP__

//#include <iostream>
#include "case.hpp"

class GRILLE
{
	public:
		GRILLE();
		GRILLE(int nb_line, int nb_col, int nb_bomb);
		~GRILLE();

	protected:
		CASE **grid;
		int nbRow;
		int nbColumn;
		int nbBombs;
		int remainBombs;

	private:

};

#endif //__GRILLE_HPP__
