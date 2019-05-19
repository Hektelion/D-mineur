#include "../../include/class/grille.hpp"
#include "../../include/constant.hpp"

#include <iostream>

GRILLE::GRILLE()
{
	nbRow = 8;
	nbColumn = 8;
	nbBombs = 10;
	remainBombs = 0;

	if(MODE_DEBUG) std::cout << "allocation de *grid" << std::endl;
	grid = new CASE*[nbColumn];

	if(*grid != NULL)
	{
		for(int i=0 ; i<nbColumn ; i++)
		{
			if(MODE_DEBUG) std::cout << "allocation de grid[" << i << ']' << std::endl;
			grid[i] = new CASE[nbRow];
			if(grid[i] == NULL) std::cerr << "allocation de grid[" << i << "] ERREUR" << std::endl;
		}
	}
	else std::cerr << "allocation de *grid[" << nbColumn << "] ERREUR" << std::endl;
}

GRILLE::GRILLE(int nb_line, int nb_col, int nb_bomb)
{
	nbRow = nb_line;
	nbColumn = nb_col;
	nbBombs = nb_bomb;
	remainBombs = 0;

	if(MODE_DEBUG) std::cout << "allocation de *grid" << std::endl;
	grid = new CASE*[nbColumn];

	if(*grid != NULL)
	{
		for(int i=0 ; i<nbColumn ; i++)
		{
			if(MODE_DEBUG) std::cout << "allocation de grid[" << i << ']' << std::endl;
			grid[i] = new CASE[nbRow];
			if(grid[i] == NULL) std::cerr << "allocation de grid[" << i << "] ERREUR" << std::endl;
		}
	}
	else std::cerr << "allocation de *grid[" << nbColumn << "] ERREUR" << std::endl;

	if(MODE_DEBUG) std::cout << "allocation de *visible" << std::endl;
	visible = new char*[nbColumn];

	if(*visible != NULL)
	{
		for(int i=0 ; i<nbColumn ; i++)
		{
			if(MODE_DEBUG) std::cout << "allocation de visible[" << i << ']' << std::endl;
			visible[i] = new char[nbRow];
			if(visible[i] == NULL) std::cerr << "allocation de visible[" << i << "] ERREUR" << std::endl;
		}
	}
	else std::cerr << "allocation de *visible[" << nbColumn << "] ERREUR" << std::endl;
}

GRILLE::~GRILLE()
{
	for(int i=0 ; i<nbColumn ; i++)
	{
		if(MODE_DEBUG) std::cout << "destruction de grid[" << i << ']' << std::endl;
		delete(grid[i]);
	}
	delete(grid);
	if(MODE_DEBUG) std::cout << "destruction grid" << std::endl;

	for(int i=0 ; i<nbColumn ; i++)
	{
		if(MODE_DEBUG) std::cout << "destruction de visible[" << i << ']' << std::endl;
		delete(visible[i]);
	}
	delete(visible);
	if(MODE_DEBUG) std::cout << "destruction visible" << std::endl;
}

bool GRILLE::isInField(int x, int y)
{
	return (x >= 0 && x < nbColumn && y >= 0 && y < nbRow);
}

void GRILLE::revealField(int x, int y)
{
	if(isInField(x,y))
	{
		if(grid[x][y].getNbBombAround() == 0 && grid[x][y].getBomb() == false)
		{
			visible[x][y] = '0';
			revealField(x - 1, y - 1);
			revealField(x - 1, y);
			revealField(x    , y - 1);
			revealField(x + 1, y + 1);
			revealField(x + 1, y);
			revealField(x    , y + 1);
			revealField(x + 1, y - 1);
			revealField(x - 1, y + 1);
		}
		else
		{
			visible[x][y] = (char)grid[x][y].getNbBombAround();
		}
	}
}
