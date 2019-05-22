#ifndef __PARTIE_HPP__
#define __PARTIE_HPP__

#include "grille.hpp"
#include "minuteur.hpp"

class PARTIE
{
	public:
		PARTIE(int nb_line, int nb_col, int nb_bomb);
		//PARTIE();
		~PARTIE();
		void begin();
		bool leftClic(int x, int y);
		void rightClic(int x, int y);
		void log();
		GRILLE field;

	private:
		MINUTEUR timer;
		bool isOver;
};

#endif //__PARTIE_HPP__
