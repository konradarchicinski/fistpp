#include "base.hpp"


double StatisticalTest::hypothesis_statitic(std::string alternative, double cdf) {
    if (alternative == "two-sided") {
        return 2.0 * (1.0 - cdf);
    } else if (alternative == "one-sided") {
        return cdf;
    } else {
        return 1.0 - cdf;
    }
}

TTest::TTest(std::vector<double> sample1, std::vector<double> sample2) {
    n1 = sample1.size();
    n2 = sample2.size();
    mean1 = mean(sample1);
    mean2 = mean(sample2);
    sample_variance1 = variance(sample1, 1);
    sample_variance2 = variance(sample2, 1);
}
double TTest::degrees_of_freedom() {
    return n1 + n2 - 2.0;
}
double TTest::tstatistic() {
    double pooled_standard_deviation = sqrt(
        ((n1 - 1.0) * sample_variance1 + (n2 - 1.0) * sample_variance2) / (n1 + n2 - 2.0) 
    );
    return (mean1 - mean2) / (pooled_standard_deviation * sqrt(1.0/n1 + 1.0/n2));
}
double TTest::pvalue(std::string alternative) {
    StudentTDistribution student_t(0.0, 1.0, degrees_of_freedom()); 
    return hypothesis_statitic(alternative, student_t.cdf(fabs(tstatistic())));
}

double WelchTTest::degrees_of_freedom() {
    std::vector<double> sample_variances = {sample_variance1, sample_variance2};
    std::vector<double> degrees_of_freedom_vector = {n1 - 1.0, n2 - 1.0};
    return welch_satterthwaite_equation(sample_variances, degrees_of_freedom_vector);
}
double WelchTTest::tstatistic() {
    return (mean1 - mean2) / sqrt(sample_variance1 / n1 + sample_variance2 / n2);
}
