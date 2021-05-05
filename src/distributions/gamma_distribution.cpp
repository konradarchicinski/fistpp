#include "../maths/special_functions.hpp"
#include "gamma_distribution.hpp"

GammaDistribution::GammaDistribution(double k_, double theta_) {
    left_support = 0.0;
    k = k_;
    theta = theta_;
}

double GammaDistribution::pdf(double x) {
    return pow(x, k - 1) * exp(-x / theta) / (tgamma(k) * pow(theta, k));
}
double GammaDistribution::cdf(double x){
    return gammainc(k, x / theta) / tgamma(k);
}
double GammaDistribution::mean() {
    return k * theta;
}
double GammaDistribution::variance() {
    return k * theta * theta;
}
