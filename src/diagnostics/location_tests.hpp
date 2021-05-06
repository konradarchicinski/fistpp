#ifndef BASE_HPP
#define BASE_HPP

#include <cmath>
#include <vector>
#include <iostream>

#include "../maths/descriptive_statistics.hpp"
#include "../distributions/student_t_distribution.hpp"


class StatisticalTest {
public:
    virtual double pvalue(std::string alternative="one-sided") = 0;
    double hypothesis_statitic(std::string alternative, double cdf);
};

class TTest: public StatisticalTest {
protected:
    int n1;
    int n2;
    double mean1;
    double mean2;
    double sample_variance1;
    double sample_variance2;
public:
    TTest(std::vector<double> sample1, std::vector<double> sample2);

    virtual double degrees_of_freedom();
    virtual double tstatistic();
    double pvalue(std::string alternative);

};

class WelchTTest: public TTest {
public:
    using TTest::TTest;

    double degrees_of_freedom() override;
    double tstatistic() override;
};

#endif