#include "descriptive_statistics.hpp"

double mean(std::vector<double> values)
{
    double running_sum = 0.0;
    int n = values.size();

    for (int i = 0; i < n; i++)
        running_sum += values[i];

    return running_sum / n;
}

double variance(std::vector<double> values, int df)
{
    float values_mean = mean(values);
    float running_sum = 0.0;
    int n = values.size();

    for (int i = 0; i < n; i++)
        running_sum += (values[i] - values_mean) * (values[i] - values_mean);

    return running_sum / (n - df);
}

double standard_deviation(std::vector<double> values, int df)
{
    return sqrt(variance(values, df));
}