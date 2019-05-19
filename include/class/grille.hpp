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
		bool isInField(int x, int y);
		void revealField(int x, int y);

	private:
		CASE **grid;
		char **visible;
		int nbRow;
		int nbColumn;
		int nbBombs;
		int remainBombs;
};

#endif //__GRILLE_HPP__
