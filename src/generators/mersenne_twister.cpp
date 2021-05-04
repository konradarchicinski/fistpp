#include "mersenne_twister.hpp"

MersenneTwister::MersenneTwister(double lower_bound,
                                 double upper_bound,
                                 unsigned long long int seed)
    : generator(seed), uniform(lower_bound, upper_bound) {}
MersenneTwister::~MersenneTwister() {}

double MersenneTwister::random_uniform() {
    return uniform(generator);
}
