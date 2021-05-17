#ifndef OPTION_HPP
#define OPTION_HPP

#include <cmath>

#include "payoff.hpp"
#include "../distributions/distribution.hpp"
#include "../distributions/normal_distribution.hpp"
#include "../maths/descriptive_statistics.hpp"


class Option {
private:
    PayOff& payoff;
    Distribution& distribution;

public:
    std::vector<double>* strikes;
    double* spot;
    double expiry;
    double volatility;
    double risk_free_rate;

    Option(PayOff& payoff_,
           Distribution& distribution_,
           double expiry_,
           double volatility_,
           double risk_free_rate_);

    double estimate_price(unsigned long number_of_paths=100000);
    std::vector<double> simulate_path(double current_spot);
};

#endif