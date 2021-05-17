#ifndef EUROPEAN_PAYOFF_HPP
#define EUROPEAN_PAYOFF_HPP

#include "option.hpp"

class PayOffEuropean: public PayOff {
public:
    PayOffEuropean(double strike_, double spot_) {
        strikes.push_back(strike_);
        spot = spot_;
        ticks = 1;
    };
    virtual ~PayOffEuropean() {};

    virtual double operator () (std::vector<double> spots) = 0;
};

class PayOffEuropeanCall: public PayOffEuropean {
public:
    using PayOffEuropean::PayOffEuropean;

    virtual double operator () (std::vector<double> spots) {
        return max(spots[0] - strikes[0], 0.0);
    };
};

class PayOffEuropeanPut: public PayOffEuropean {
public:
    using PayOffEuropean::PayOffEuropean;

    virtual double operator () (std::vector<double> spots) {
        return max(strikes[0] - spots[0], 0.0);
    };
};

#endif
