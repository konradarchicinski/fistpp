#include "payoff.hpp"

PayOffCall::PayOffCall(double strike_) {
    strike = strike_;
}
double PayOffCall::operator()(double spot) const {
    return max(spot - strike, 0.0);
}

PayOffPut::PayOffPut(double strike_) {
    strike = strike_;
}
double PayOffPut::operator()(double spot) const {
    return max(strike - spot, 0.0);
}