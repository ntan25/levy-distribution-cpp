#include <random>
#include <cmath>
#include <array> 


double get_levy(std::array<double, 2>& params, double c=0.5, double mu=0.5, double x_low=1, double x_high=1.5, double y_low=0, double y_high=1.5){

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

    //Note: x > mu, changing c and mu will change the shape of the pdf 

	std::random_device rd; 
	std::mt19937 e2(rd()); 
	std::uniform_real_distribution<> dist_a(x_low, x_high);
	std::uniform_real_distribution<> dist_b(y_low, y_high);

	double x = 0.; 
	double y = 0.; 

	do {
		x = dist_a(e2); 
		y = dist_b(e2); 
	} while(f(x, c, mu) < y);

	params[0] = c; 
	params[1] = mu; 

	return y; 

}