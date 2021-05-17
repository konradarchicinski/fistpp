#include "distribution.hpp"

double Distribution::ppf(double q) {
    double quantile = mean();
    double qt = cdf(quantile);

    double multiplier;
    if (std::isfinite(variance()))
        multiplier = sqrt(variance());
    else
        multiplier = scale;

    double left_border, right_border;
    if (std::isfinite(left_support))
        left_border = left_support;
    else
        left_border = -4 * multiplier + mean();
    if (std::isfinite(right_support))
        right_border = right_support;
    else
        right_border = 4 * multiplier + mean();

    while (q < cdf(left_border) || q > cdf(right_border))
    {
        left_border *= 2;
        right_border *= 2;
    }

    int iteration = 0;
    while (fabs(qt - q) >= QUANTILE_TOLERANCE)
    {
        if (qt < q)
            left_border = quantile;
        else
            right_border = quantile;

        quantile = (left_border + right_border) / 2;
        qt = cdf(quantile);

        if (iteration > ITERATIONS_LIMIT)
            break;

        iteration++;
    }

    return quantile;
}

void Distribution::set_generator(double lower_bound,
                                 double upper_bound,
                                 unsigned long long int seed) {
    generator = MersenneTwister(lower_bound, upper_bound, seed);
}

double Distribution::random_number() {
    return ppf(generator.random_uniform());
}

std::vector<double> Distribution::simulate(
    unsigned long long int simulations_number, 
    unsigned long long int seed) {
    
    if (seed != 1)
        set_generator(0.0, 1.0, seed);

    std::vector<double> random_numbers(simulations_number);

    for (int i = 0; i < simulations_number; i++)
        random_numbers[i] = random_number();

    return random_numbers;
}
