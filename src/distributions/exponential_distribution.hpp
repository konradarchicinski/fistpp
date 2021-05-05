#ifndef EXPONENTIAL_DISTRIBUTION_HPP
#define EXPONENTIAL_DISTRIBUTION_HPP

#include "distribution.hpp"

class ExponentialDistribution : public Distribution {
public:
    double lambda;
    
    ExponentialDistribution(double lambda_=1.0);

    virtual double pdf(double x) override;
    virtual double cdf(double x) override;
    virtual double ppf(double q) override;

    virtual double mean() override;
    virtual double variance() override;
};

#endif