#ifndef __PARTIE_HPP__
#define __PARTIE_HPP__

#include "grille.hpp"
#include "minuteur.hpp"

class PARTIE
{
	public:
		PARTIE();
		//PARTIE();
		~PARTIE();
		void begin();

	protected:
		GRILLE field(40, 40, 40);
		MINUTEUR timer;
		bool isOver;

	private:

};

#endif //__PARTIE_HPP__
