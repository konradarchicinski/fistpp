#include "option_pricer.hpp"

OptionPricer::OptionPricer(double expiry_, 
                           double strike_, 
                           double spot_,
                           double volatility_, 
                           double risk_free_rate_) {
    expiry = expiry_;
    strike = strike_;
    spot = spot_;
    volatility = volatility_;
    risk_free_rate = risk_free_rate_;
}

OptionPricer::~OptionPricer() {
    delete payoff_pointer;
}

double OptionPricer::estimate_price(
    std::string option_type, unsigned long number_of_paths) {
    if (option_type == "Call")
        payoff_pointer = new PayOffCall(strike);
    else if (option_type == "Put")
        payoff_pointer = new PayOffPut(strike);

    return monte_carlo_pricer(*payoff_pointer, number_of_paths);
}

double OptionPricer::monte_carlo_pricer(
    const PayOff &payoff, unsigned long number_of_paths) {
    
    double variance = expiry * pow(volatility, 2);
    double root_variance = sqrt(variance);
    double ito_correction = -0.5*variance;
    double moved_spot = spot * exp(
        risk_free_rate*expiry + ito_correction);

    NormalDistribution norm(0.0, 1.0);
    std::vector norm_dist_sample = norm.simulate(number_of_paths);

    double simulated_spot;
    double simulated_spot_payoff;
    double running_sum = 0.0;
    for (unsigned long i=0; i<number_of_paths; i++) {
        simulated_spot = moved_spot * exp(
            root_variance*norm_dist_sample[i]
        );
        simulated_spot_payoff = payoff(simulated_spot);
        running_sum += simulated_spot_payoff;
    }

    double mean = running_sum / number_of_paths;
    return mean * exp(-risk_free_rate*expiry);
}