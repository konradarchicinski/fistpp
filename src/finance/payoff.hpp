#ifndef PAYOFF_HPP
#define PAYOFF_HPP

#include "../maths/minmax.hpp"

class PayOff {
public:
    PayOff(){};
    virtual ~PayOff(){};

    virtual double operator()(double spot) const=0;
};

class PayOffCall: public PayOff {
private:
    double strike;

public:
    PayOffCall(double strike_);
    virtual ~PayOffCall(){};

    virtual double operator()(double spot) const;
};

class PayOffPut: public PayOff {
private:
    double strike;

public:
    PayOffPut(double strike_);
    virtual ~PayOffPut(){};

    virtual double operator()(double spot) const;
};

#endif