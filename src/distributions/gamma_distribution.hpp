#ifndef GAMMA_DISTRIBUTION_HPP
#define GAMMA_DISTRIBUTION_HPP

#include "distribution.hpp"

class GammaDistribution : public Distribution {
public:
    double k;
    double theta;

    GammaDistribution(double k_=2.0, double theta_=1.0);

    virtual double pdf(double x) override;
    virtual double cdf(double x) override;

    virtual double mean() override;
    virtual double variance() override;
};

#endif