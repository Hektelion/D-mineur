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
