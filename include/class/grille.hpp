#ifndef __GRILLE_HPP__
#define __GRILLE_HPP__

//#include <iostream>
#include "case.hpp"
#include <vector>

class GRILLE
{
	public:
		std::vector< std::vector<char> > visible;
		GRILLE(int nb_line, int nb_col, int nb_bomb);
		~GRILLE();
		void initGrid();
		void initVisible();
		bool isInField(int x, int y);
		void revealField(int x, int y);
		void update();
		void printGrid();
		void printVisible();
		bool isBombIn(int x, int y);

	private:
		std::vector< std::vector<CASE> > grid;
		int nbRow;
		int nbColumn;
		int nbBombs;
		int remainBombs;
};

#endif //__GRILLE_HPP__
