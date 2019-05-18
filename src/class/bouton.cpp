#include "../../include/class/bouton.hpp"
#include "../../include/constant.hpp"

#include <iostream>

//BOUTON
BOUTON::BOUTON(){

}
BOUTON::~BOUTON(){
	if(MODE_DEBUG) std::cout << "destruction BOUTON" << std::endl;
}
