#include "../maths/special_functions.hpp"
#include "chi_square_distribution.hpp"

ChiSquareDistribution::ChiSquareDistribution(int k_)
    : gamma_distribution(k_ / 2.0, 2.0) {
    left_support = 0.0;
    k = k_;
}

double ChiSquareDistribution::pdf(double x) {
    return gamma_distribution.pdf(x);
}
double ChiSquareDistribution::cdf(double x) {
    return gamma_distribution.cdf(x);
}
double ChiSquareDistribution::mean() {
    return gamma_distribution.mean();
}
double ChiSquareDistribution::variance() {
    return gamma_distribution.variance();
}