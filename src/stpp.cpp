#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "maths/descriptive_statistics.hpp"
#include "maths/special_functions.hpp"
#include "diagnostics/location_tests.hpp"
#include "generators/mersenne_twister.hpp"
#include "distributions/distribution.hpp"
#include "distributions/chi_square_distribution.hpp"
#include "distributions/exponential_distribution.hpp"
#include "distributions/gamma_distribution.hpp"
#include "distributions/normal_distribution.hpp"
#include "distributions/student_t_distribution.hpp"
#include "finance/option_pricer.hpp"

namespace py = pybind11;
using namespace py::literals;

PYBIND11_MODULE(fistpp, m) {
      m.doc() = "Simple statistical Python package written in C++.";

      py::class_<Distribution>(m, "Distribution")
            .def_readwrite("left_support", &Distribution::left_support)
            .def_readwrite("right_support", &Distribution::right_support)
            .def_readwrite("location", &Distribution::location)
            .def_readwrite("scale", &Distribution::scale)
            .def("simulate", &Distribution::simulate,
                 "simulations_number"_a,
                 "seed"_a=1)
            .def("pdf", &Distribution::pdf, "x"_a)
            .def("cdf", &Distribution::cdf, "x"_a)
            .def("ppf", &Distribution::ppf, "q"_a)
            .def("mean", &Distribution::mean)
            .def("variance", &Distribution::variance);
      py::class_<ChiSquareDistribution, Distribution>(m, "ChiSquareDistribution")
            .def(py::init<int &>(), "k"_a=2)
            .def_readwrite("k", &ChiSquareDistribution::k);
      py::class_<ExponentialDistribution, Distribution>(m, "ExponentialDistribution")
            .def(py::init<double &>(), "lambda"_a=1.0)
            .def_readwrite("lambda", &ExponentialDistribution::lambda);        
      py::class_<GammaDistribution, Distribution>(m, "GammaDistribution")
            .def(py::init<double &, double &>(), "k"_a=2.0, "theta"_a=1.0)
            .def_readwrite("k", &GammaDistribution::k)
            .def_readwrite("theta", &GammaDistribution::theta);
      py::class_<NormalDistribution, Distribution>(m, "NormalDistribution")
            .def(py::init<double &, double &>(), "mu"_a=0.0, "sigma"_a=1.0)
            .def_readwrite("mu", &NormalDistribution::mu)
            .def_readwrite("sigma", &NormalDistribution::sigma);
      py::class_<StudentTDistribution, Distribution>(m, "StudentTDistribution")
            .def(py::init<double &, double &, double &>(), 
                  "mu"_a=0.0, "sigma"_a=1.0, "nu"_a=4.0)
            .def_readwrite("mu", &StudentTDistribution::mu)
            .def_readwrite("sigma", &StudentTDistribution::sigma)
            .def_readwrite("nu", &StudentTDistribution::nu);
      py::class_<MersenneTwister>(m, "MersenneTwister")
            .def(py::init<double &, double &, unsigned long long int &>(),
                  "lower_bound"_a=0.0,
                  "upper_bound"_a=1.0,
                  "seed"_a=std::chrono::system_clock::now().time_since_epoch().count())
            .def("random_uniform", &MersenneTwister::random_uniform);

      py::class_<StatisticalTest>(m, "StatisticalTest")
            .def("pvalue", &StatisticalTest::pvalue, "alternative"_a="one-sided")
            .def("hypothesis_statitic", &StatisticalTest::hypothesis_statitic, 
                 "alternative"_a="one-sided", "cdf"_a);
      py::class_<TTest, StatisticalTest>(m, "TTest")
            .def(py::init<std::vector<double> &, std::vector<double> &>(), 
                  "sample1"_a, "sample2"_a)
            .def("degrees_of_freedom", &TTest::degrees_of_freedom)
            .def("tstatistic", &TTest::tstatistic);
      py::class_<WelchTTest, TTest>(m, "WelchTTest")
            .def(py::init<std::vector<double> &, std::vector<double> &>(), 
                  "sample1"_a, "sample2"_a);


      m.def("mean", 
            &mean,
            "Returns mean from provided values.",
            "values"_a);
      m.def("variance",
            &variance,
            "Returns variance from provided values.",
            "values"_a,
            "df"_a=0);
      m.def("standard_deviation",
            &standard_deviation,
            "Returns standard_deviation from provided values.",
            "values"_a,
            "df"_a=0);
      m.def("welch_satterthwaite_equation",
            &welch_satterthwaite_equation,
            "Returns approximation to the effective degrees of freedom.",
            "variances"_a, 
            "nus"_a);

      m.def("erfinv",
            &erfinv,
            "Returns inverse error function value in `y`.",
            "y"_a);
      m.def("betainc",
            &betainc,
            "Returns beta incomplete function value in `x` for `a` and `b`.",
            "a"_a,
            "b"_a,
            "x"_a);
      m.def("gammainc",
            &gammainc,
            "Returns gamma incomplete function value in `x` for `a`.",
            "a"_a,
            "x"_a);
}