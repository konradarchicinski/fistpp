#ifndef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#include <cmath>
#include <vector>
#include <limits>

#include "../generators/mersenne_twister.hpp"

class Distribution {
private:
    const double QUANTILE_TOLERANCE = 1e-15;
    const int ITERATIONS_LIMIT = 1e+4;

public:
    Distribution(){};
    virtual ~Distribution(){};

    double left_support = -std::numeric_limits<float>::infinity();
    double right_support = std::numeric_limits<float>::infinity();

    double location = 0.0;
    double scale = 1.0;

    MersenneTwister generator;

    virtual double pdf(double x) = 0;
    virtual double cdf(double x) = 0;
    virtual double ppf(double q);
    std::vector<double> simulate(
        unsigned long long int simulations_number, 
        unsigned long long int seed=1);
    double random_number();
    void set_generator(
        double lower_bound,
        double upper_bound,
        unsigned long long int seed);

    virtual double mean() = 0;
    virtual double variance() = 0;

};

#endif
