#ifndef DOUBLE_DIGITAL_PAYOFF_HPP
#define DOUBLE_DIGITAL_PAYOFF_HPP

#include "payoff.hpp"

class PayOffDoubleDigital: public PayOff {
public:
    PayOffDoubleDigital(double lower_strike, double upper_strike, double spot_) {
        strikes.push_back(lower_strike);
        strikes.push_back(upper_strike);
        spot = spot_;
        ticks = 1;
    };
    virtual ~PayOffDoubleDigital() {};

    virtual double operator () (std::vector<double> spots) {
        if (spots[0] <= strikes[0])
            return 0;
        if (spots[0] >= strikes[1])
            return 0;
        return 1;
    };
};

#endif