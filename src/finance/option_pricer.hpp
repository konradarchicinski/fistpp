#ifndef OPTION_PRICER_HPP
#define OPTION_PRICER_HPP

#include <string>
#include <cmath>
#include "payoff.hpp"
#include "../distributions/normal_distribution.hpp"

class OptionPricer {
private:
    PayOff* payoff_pointer;

    double monte_carlo_pricer(
        const PayOff &payoff, unsigned long number_of_paths);

public:
    double expiry;
    double strike;
    double spot;
    double volatility;
    double risk_free_rate;

    OptionPricer(double expiry_,
                 double strike_,
                 double spot_,
                 double volatility_,
                 double risk_free_rate_);
    ~OptionPricer();

    double estimate_price(
        std::string option_type, unsigned long number_of_paths);

};

#endif