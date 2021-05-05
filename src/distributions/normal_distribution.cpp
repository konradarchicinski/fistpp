#include "../maths/special_functions.hpp"
#include "normal_distribution.hpp"

NormalDistribution::NormalDistribution(double mu_, double sigma_) {
    mu = mu_;
    sigma = sigma_;
}

double NormalDistribution::pdf(double x) {
    return exp(-0.5 * (pow((x - mu) / sigma, 2))) / (sigma * sqrt(2 * M_PI));
}
double NormalDistribution::cdf(double x) {
    return 0.5 * (1 + erf((x - mu) / (sigma * sqrt(2))));
}
double NormalDistribution::ppf(double q) {
    return mu + sigma * sqrt(2) * erfinv(2 * q - 1);
}
double NormalDistribution::mean() {
    return mu;
}
double NormalDistribution::variance() {
    return sigma;
}
