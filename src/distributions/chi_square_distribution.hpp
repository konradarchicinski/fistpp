#ifndef CHI_SQUARE_DISTRIBUTION_HPP
#define CHI_SQUARE_DISTRIBUTION_HPP

#include "gamma_distribution.hpp"

class ChiSquareDistribution : public Distribution {
public:
    int k;

    ChiSquareDistribution(int k_=2);

    virtual double pdf(double x) override;
    virtual double cdf(double x) override;

    virtual double mean() override;
    virtual double variance() override;

private:
    GammaDistribution gamma_distribution;
};

#endif