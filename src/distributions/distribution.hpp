#ifndef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#include <cmath>
#include <vector>
#include <limits>

class Distribution {
public:
    Distribution(){};
    virtual ~Distribution(){};

    double left_support = -std::numeric_limits<float>::infinity();
    double right_support = std::numeric_limits<float>::infinity();

    double location = 0.0;
    double scale = 1.0;

    virtual double pdf(double x) = 0;
    virtual double cdf(double x) = 0;
    virtual double ppf(double q);
    std::vector<double> simulate(
        unsigned long long int simulations_number, 
        unsigned long long int seed=1);

    virtual double mean() = 0;
    virtual double variance() = 0;

private:
    const double QUANTILE_TOLERANCE = 1e-15;
    const int ITERATIONS_LIMIT = 1e+4;
};

#endif
