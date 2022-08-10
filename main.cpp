#include <iostream>
#include "levy-dist.h"
#include <fstream> 


int main(int argc, char* argv[]){

	//Testing	
	std::ofstream myfile("levy-test.csv"); 
	
	for(int i = 0; i < 100; ++i){
		myfile << get_levy() << std::endl;  
	}

	
}