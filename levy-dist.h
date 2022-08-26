#include <random>
#include <cmath>
#include <array>
#include <stdexcept> 
#include <iostream>


//Code lifted from John Cook, Ph.D.
double rational_approximation(double t){

	//Abramowitz and Stegun formula
	double c[] = {2.515517, 0.802853, 0.010328}; 
	double d[] = {1.432788, 0.189269, 0.001308}; 

	return t - ((c[2]*t + c[1])*t + c[0]) / (((d[2]*t + d[1]*t) + d[0]) *t + 1.0);; 
}

double inv_norm_cdf(double p){

	if (p < 0.0 || p > 1.0){
		std::cout << p << std::endl; 
		throw std::invalid_argument("input must be greater than 0 and less than 1"); 
	}
	if (p < 0.5) return -rational_approximation(sqrt(-2.0*log(p))); 
	else return rational_approximation(sqrt(-2.0*log(1-p))); 
}

//End code lifted from John Cook//


//inverse transform sampling
double get_levy_inverse_transform(double c=0.5, double mu=0, bool truncate=false, double truncate_val=1.0){

	std::random_device rd; 
	std::mt19937 e2(rd());

	std::uniform_real_distribution<> var(0,1); 
	double res = 0.0; 

	if(truncate){
		do {
			double u = var(e2); 
			double n = c; 
			double d = pow(inv_norm_cdf(1-u), 2);
			res = n/d + mu; 
		} 
		while(res > truncate_val); 
	}
	else{
		double u = var(e2); 
		double n = c; 
		double d = pow(inv_norm_cdf(1-u), 2);
		res = n/d + mu; 
	}
	return res;  
}


//rejection sampling
double get_levy(double c=0.5, double mu=0.5, double x_low=1, double x_high=1.5, double y_low=0, double y_high=1.5){

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

	return y; 

}


//Test function for rejection sampling from a Lévy distribution
double get_levy_test(std::array<double, 2>& params, double c=0.5, double mu=0., double x_low=1, double x_high=1.5, double y_low=0, double y_high=1.5){

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