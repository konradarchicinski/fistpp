#ifndef PAYOFF_HPP
#define PAYOFF_HPP

#include <vector>
#include "../maths/minmax.hpp"

class PayOff {
public:
    std::vector<double> strikes;
    unsigned long ticks;
    double spot;

    PayOff(){};
    virtual ~PayOff(){};

    virtual double operator()(std::vector<double> spots) = 0;
};

#endif