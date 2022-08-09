#include <iostream>
#include <random>
#include <cmath>


double get_levy(){

	//Rejection Sampling: 
	//generate x and y coordinate as many times and see if it fits underneath
	//the pdf curve 

	//Routine: 
	// 1. Generate random values x and y
	// 2. Plug x into the pdf 
	// 3. See if y < f(x) if so it is under the curve and part of the distribution, return

	//pdf
	auto f = [] (double x){
		double c = 0.5; 
		double mu = 0.5;

		double u = sqrt(c/(2*M_PI));
		double v = exp(-1*(c/(2*(x - mu))));
		double w = pow(x-mu, 1.5);
		return u * (v/w); 
	};

	std::random_device rd; 
	std::mt19937 e2(rd()); 
	std::uniform_real_distribution<> dist_a(0, 1);
	std::uniform_real_distribution<> dist_b(0, 1.5);

	double x; 
	double y; 

	do {
		x = dist_a(e2); 
		y = dist_b(e2); 

	} while(f(x) > y);

	return y; 

}


int main(int argc, char* argv[]){

	// STEP 1. Choose random uniform angle [0, 2pi)
	// STEP 2. Choose Lévy random distance
	// STEP 3. Move in that direction

	std::random_device rd; 
	std::mt19937 e2(rd()); 
	std::uniform_real_distribution<> dist_uniform(0, 1);

	double theta = 2*M_PI * dist_uniform(e2);

	// std::cout << theta << std::endl; 
	std::cout << get_levy() << std::endl; 
	
	return 0; 
}