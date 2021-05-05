#ifndef STUDENT_T_DISTRIBUTION_HPP
#define STUDENT_T_DISTRIBUTION_HPP

#include "distribution.hpp"

class StudentTDistribution : public Distribution {
public:
    double mu;
    double sigma;
    double nu;

    StudentTDistribution(double mu_=0.0, double sigma_=1.0, double nu_=4.0);

    virtual double pdf(double x) override;
    virtual double cdf(double x) override;

    virtual double mean() override;
    virtual double variance() override;
};

#endif