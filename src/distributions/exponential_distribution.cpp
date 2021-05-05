#include "exponential_distribution.hpp"

ExponentialDistribution::ExponentialDistribution(double lambda_) {
    left_support = 0.0;
    lambda = lambda_;
}

double ExponentialDistribution::pdf(double x) {
    return lambda * exp(-lambda * x);
}
double ExponentialDistribution::cdf(double x) {
    return 1.0 - exp(-lambda * x);
}
double ExponentialDistribution::ppf(double q) {
    return -log(1.0 - q) / lambda;
}

double ExponentialDistribution::mean() {
    return 1.0 / lambda;
}
double ExponentialDistribution::variance() {
    return 1.0 / (lambda * lambda);
}
