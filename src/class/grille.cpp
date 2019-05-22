#include "../../include/class/grille.hpp"
#include "../../include/constant.hpp"

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

GRILLE::GRILLE(int nb_line, int nb_col, int nb_bomb)
{
	nbRow = nb_line;
	nbColumn = nb_col;
	nbBombs = nb_bomb;
	remainBombs = 0;

	if(MODE_DEBUG) cout << "Redimensionnement de grid" << endl;
	grid.resize(nbColumn);
	for(unsigned int i=0 ; i < grid.size() ; i++) {
		grid[i].resize(nbRow);
    }

	if(MODE_DEBUG) cout << "Redimensionnement de visible" << endl;
	visible.resize(nbColumn);
	for(unsigned int i=0 ; i < grid.size() ; i++) {
		visible[i].resize(nbRow);
    }

	initGrid();
	initVisible();
	update();
}

GRILLE::~GRILLE()
{
	if(MODE_DEBUG) cout << "Destruction GRILLE..." << endl;
}

void GRILLE::initGrid(){
	srand(time(NULL));

	for(int i = 0; i < nbBombs; i++)
	{
		int x, y;
		while(true)
		{
			x = rand() % nbColumn;
			y = rand() % nbRow;
			if(grid[x][y].getBomb() != true)
			{
				grid[x][y].placeBomb();
				break;
			}
		}
	}
}

void GRILLE::initVisible(){
	for(int i=0 ; i<nbColumn ; i++)
	{
		for(int j=0 ; j<nbRow ; j++)
		{
			visible[i][j] = '#';
		}
	}
}

bool GRILLE::isInField(int x, int y)
{
	return (x >= 0 && x < nbColumn && y >= 0 && y < nbRow);
}

void GRILLE::revealField(int x, int y)
{
	if(MODE_DEBUG) cout << "Appel de revealField case (" << x << ',' << y << ')' << endl;
	if(isInField(x,y))
	{
		if(visible[x][y] == '#' && grid[x][y].getBomb() == false && grid[x][y].getNbBombAround() == 0 )
		{
			visible[x][y] = '.';
			revealField(x - 1, y - 1);
			revealField(x - 1, y);
			revealField(x    , y - 1);
			revealField(x + 1, y + 1);
			revealField(x + 1, y);
			revealField(x    , y + 1);
			revealField(x + 1, y - 1);
			revealField(x - 1, y + 1);
		}
		else if(grid[x][y].getNbBombAround() > 0)
		{
			visible[x][y] = grid[x][y].getNbBombAround() + 48;
		}
	}
	else
	{
		if(MODE_DEBUG) cout << "ERREUR revealField case (" << x << ',' << y << ") : en dehors de la grille" << endl;
	}
}

void GRILLE::printGrid(){
	for(int i=0 ; i<nbColumn ; i++)
	{
		for(int j=0 ; j<nbRow ; j++)
		{
			if(grid[i][j].getBomb() == true){
				cout << "B ";
			}
			else if(grid[i][j].getNbBombAround() != 0){
				cout << grid[i][j].getNbBombAround() << ' ';
			}
			else{
				cout << ". ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void GRILLE::printVisible(){
	for(int i=0 ; i<nbColumn ; i++)
	{
		for(int j=0 ; j<nbRow ; j++)
		{
			cout << visible[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void GRILLE::update(){
	for(int i=0 ; i<nbColumn ; i++)
	{
		for(int j=0 ; j<nbRow ; j++)
		{
			if(grid[i][j].getBomb() == true)
			{
				if(isInField(i - 1, j - 1))	grid[i - 1][j - 1].incNbBombAround();
				if(isInField(i - 1, j    ))	grid[i - 1][j    ].incNbBombAround();
				if(isInField(i    , j - 1))	grid[i	  ][j - 1].incNbBombAround();
				if(isInField(i + 1, j + 1))	grid[i + 1][j + 1].incNbBombAround();
				if(isInField(i + 1, j    ))	grid[i + 1][j    ].incNbBombAround();
				if(isInField(i    , j + 1))	grid[i	  ][j + 1].incNbBombAround();
				if(isInField(i + 1, j - 1))	grid[i + 1][j - 1].incNbBombAround();
				if(isInField(i - 1, j + 1))	grid[i - 1][j + 1].incNbBombAround();
			}
		}
	}
}

bool GRILLE::isBombIn(int x, int y){
	return grid[x][y].getBomb();
}
