#include <random>
#include <cmath>


double get_levy(){

	//Rejection Sampling: 

	//Routine: 
	// 1. Generate random values x and y
	// 2. Plug x into the pdf 
	// 3. See if y < f(x). If so it is under the curve and part of the distribution, return

	//pdf lambda function
	auto f = [] (double x, double c = 0.5, double mu = 0.5){

		double u = sqrt(c/(2*M_PI));
		double v = exp(-1*(c/(2*(x - mu))));
		double w = pow(x-mu, 1.5);
		return u * (v/w); 
	};

	std::random_device rd; 
	std::mt19937 e2(rd()); 
	std::uniform_real_distribution<> dist_a(0, 1);
	std::uniform_real_distribution<> dist_b(0, 1.5);

	double x = 0.; 
	double y = 0.; 

	do {
		x = dist_a(e2); 
		y = dist_b(e2); 

	} while(f(x) > y);

	return y; 

}