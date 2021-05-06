#ifndef DESCRIPTIVE_STATISTICS_HPP
#define DESCRIPTIVE_STATISTICS_HPP

#include <cmath>
#include <vector>

double mean(std::vector<double> values);
double variance(std::vector<double> values, int df=0);
double standard_deviation(std::vector<double> values, int df=0);
double welch_satterthwaite_equation(
    std::vector<double> variances, std::vector<double> nus
);

#endif