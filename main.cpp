#include <iostream>
#include "levy-dist.h"
#include <fstream> 


int main(int argc, char* argv[]){

	//Testing	
	std::ofstream res("levy-test.csv"); 
	std::ofstream params("levy-params.csv"); 
	
	std::array<double, 2> p {0, 0}; 
	for(int i = 0; i < 10000; ++i){

		//For testing note x > mu
		//function signature: 
		//get_levy(double c, double mu, double x_low, double x_high, double y_low, double y_high)
		
		res << get_levy() << std::endl;  
	}

	params << p[0] << "," << p[1] << std::endl; 

	std::cout << "Running Display File..." << std::endl; 
	std::system("python3 levy-test.py"); 
	
}