#include "../../include/class/case.hpp"
#include "../../include/constant.hpp"

#include <iostream>

//CASE
CASE::CASE(){
	bomb = false;
	nbBombAround = 0;
}
CASE::~CASE(){
	if(MODE_DEBUG) std::cout << "destruction CASE" << std::endl;
}

bool CASE::getBomb()
{
	return bomb;
}

int CASE::getNbBombAround()
{
	return nbBombAround;
}

void CASE::placeBomb()
{
	bomb = true;
}

void CASE::incNbBombAround(){
	nbBombAround++;
}
