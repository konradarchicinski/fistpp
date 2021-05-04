#ifndef NORMAL_DISTRIBUTION_HPP
#define NORMAL_DISTRIBUTION_HPP

#include "distribution.hpp"

class NormalDistribution : public Distribution {
public:
    double mu;
    double sigma;

    NormalDistribution(double _mu = 0.0, double _sigma = 1.0);

    virtual double pdf(double x) override;
    virtual double cdf(double x) override;
    virtual double ppf(double q) override;

    virtual double mean() override;
    virtual double variance() override;
};

#endif