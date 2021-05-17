#include "option.hpp"

Option::Option(PayOff& payoff_,
               Distribution& distribution_,
               double expiry_,
               double volatility_,
               double risk_free_rate_)
               : payoff(payoff_),
                 distribution(distribution_) {
    expiry = expiry_;
    volatility = volatility_;
    risk_free_rate = risk_free_rate_;
    strikes = &payoff.strikes;
    spot = &payoff.spot;
}

double Option::estimate_price(unsigned long number_of_paths) {
    // double variance = expiry * pow(volatility, 2);
    // double root_variance = sqrt(variance);
    // double ito_correction = -0.5*variance;
    // double moved_spot = *spot * exp(risk_free_rate * expiry + ito_correction);

    // double simulated_spot;
    std::vector<double> spots;
    double simulated_spot_payoff;
    double running_sum = 0.0;

    for (unsigned long i=0; i<number_of_paths; i++) {
        // simulated_spot = moved_spot * exp(
        //     root_variance * distribution.random_number());
        spots = simulate_path(*spot);

        simulated_spot_payoff = payoff(spots);
        running_sum += simulated_spot_payoff;
    }

    double mean = running_sum / number_of_paths;
    return mean * exp(-risk_free_rate*expiry);
}

std::vector<double> Option::simulate_path(double current_spot) {
    double ito_correction = -0.5*volatility * volatility * expiry;
    double drift = (risk_free_rate * expiry - ito_correction) / payoff.ticks;

    std::vector<double> path;
    double cummulative_shocks = 0.0;

    for (unsigned long i=0; i<payoff.ticks; i++) {
        cummulative_shocks += (
            drift + volatility * sqrt(expiry / double(payoff.ticks))) * distribution.random_number();
        path.push_back(current_spot * exp(cummulative_shocks));
    }

    return path;
};
