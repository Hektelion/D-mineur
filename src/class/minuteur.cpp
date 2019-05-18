#include "../../include/class/minuteur.hpp"
#include "../../include/constant.hpp"

#include <iostream>

//MINUTEUR
MINUTEUR::MINUTEUR(){
	time = 0;
}
MINUTEUR::~MINUTEUR(){
	if(MODE_DEBUG) std::cout << "destruction MINUTEUR" << std::endl;
}
