#ifndef STUDENT_T_DISTRIBUTION_HPP
#define STUDENT_T_DISTRIBUTION_HPP

#include "distribution.hpp"

class StudentTDistribution : public Distribution {
public:
    double mu;
    double sigma;
    double nu;

    StudentTDistribution(
        double _mu = 0.0, double _sigma = 1.0, double _nu = 4.0);

    virtual double pdf(double x) override;
    virtual double cdf(double x) override;

    virtual double mean() override;
    virtual double variance() override;
};

#endif