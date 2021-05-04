#include "../maths/special_functions.hpp"
#include "student_t_distribution.hpp"

StudentTDistribution::StudentTDistribution(
    double _mu, double _sigma, double _nu) {
    mu = _mu;
    sigma = _sigma;
    nu = _nu;
}

double StudentTDistribution::pdf(double x) {
    double t = (nu + 1) / 2;
    return pow(1 + (1 / nu) * pow((x - mu) / sigma, 2), -t) *
           (tgamma(t) / (sigma * sqrt(M_PI * nu) * tgamma(nu / 2)));
}
double StudentTDistribution::cdf(double x) {
    double xt = (x + sqrt(x * x + nu)) / (2.0 * sqrt(x * x + nu));
    return betainc(nu / 2.0, nu / 2.0, xt);
}
double StudentTDistribution::mean() {
    return mu;
}
double StudentTDistribution::variance() {
    if (nu > 2.0)
    {
        return scale * (nu / (nu - 2.0));
    }
    else if (1.0 < nu <= 2.0)
    {
        return std::numeric_limits<float>::infinity();
    }
    else
    {
        return std::numeric_limits<double>::quiet_NaN();
    }
}