#ifndef ASIAN_PAYOFF_HPP
#define ASIAN_PAYOFF_HPP

#include "payoff.hpp"
#include "../maths/descriptive_statistics.hpp"

class PayOffAsian: public PayOff {
public:
    PayOffAsian(double strike_, double spot_, unsigned long ticks_) {
        strikes.push_back(strike_);
        spot = spot_;
        ticks = ticks_;
    };
    virtual ~PayOffAsian() {};

    virtual double operator () (std::vector<double> spots) = 0;

    double average_spot(std::vector<double> spots) {
        return mean(spots);
    };

};

class PayOffAsianCall: public PayOffAsian{
public:
    using PayOffAsian::PayOffAsian;

    virtual double operator () (std::vector<double> spots) {
        return max(average_spot(spots) - strikes[0], 0.0);
    };
};

class PayOffAsianPut: public PayOffAsian{
public:
    using PayOffAsian::PayOffAsian;

    virtual double operator () (std::vector<double> spots) {
        return max(strikes[0] - average_spot(spots), 0.0);
    };
};

#endif