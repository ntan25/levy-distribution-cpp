#include <iostream>
#include "levy-dist.h"


int main(int argc, char* argv[]){

	//Testing	
	for(int i = 0; i < 1000; ++i){
		std::cout << get_levy() << std::endl; 
	}
	
}