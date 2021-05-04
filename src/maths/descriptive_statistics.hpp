#ifndef DESCRIPTIVE_STATISTICS_HPP
#define DESCRIPTIVE_STATISTICS_HPP

#include <cmath>
#include <vector>

double mean(std::vector<double> values);
double variance(std::vector<double> values, int df = 1);
double standard_deviation(std::vector<double> values, int df = 1);

#endif