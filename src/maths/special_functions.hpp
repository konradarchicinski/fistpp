#ifndef SPECIAL_FUNCTIONS_HPP
#define SPECIAL_FUNCTIONS_HPP

#define _USE_MATH_DEFINES

#include <cmath>
#include <cfloat>
#include <limits>

double erfinv(double y);
double betainc(double a, double b, double x);
double gammainc(double a, double x);

#endif