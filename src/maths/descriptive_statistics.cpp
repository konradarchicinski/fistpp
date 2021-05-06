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
    double values_mean = mean(values);
    double running_sum = 0.0;
    int n = values.size();

    for (int i = 0; i < n; i++)
        running_sum += pow(values[i] - values_mean, 2);

    return running_sum / (n - df);
}

double standard_deviation(std::vector<double> values, int df)
{
    return sqrt(variance(values, df));
}

double welch_satterthwaite_equation(
    std::vector<double> sample_variances, std::vector<double> nus) {
    double numerator = 0.0;
    double denominator = 0.0;
    double chi;

    for (int i = 0; i < sample_variances.size(); i++) {
        chi = sample_variances[i] / (nus[i] + 1.0);
        numerator += chi;
        denominator += pow(chi, 2) / nus[i];
    }

    return pow(numerator, 2) / denominator;
}