#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "maths/descriptive_statistics.hpp"
#include "maths/special_functions.hpp"
#include "diagnostics/base.hpp"
#include "generators/mersenne_twister.hpp"
#include "distributions/distribution.hpp"
#include "distributions/chi_square_distribution.hpp"
#include "distributions/exponential_distribution.hpp"
#include "distributions/gamma_distribution.hpp"
#include "distributions/normal_distribution.hpp"
#include "distributions/student_t_distribution.hpp"

namespace py = pybind11;
using namespace py::literals;

PYBIND11_MODULE(stpp, m) {
      m.doc() = "Simple statistical Python package written in C++.";

      py::class_<Distribution>(m, "Distribution")
            .def("simulate", &Distribution::simulate,
                 "simulations_number"_a,
                 "seed"_a=1)
            .def("pdf", &Distribution::pdf, "x"_a)
            .def("cdf", &Distribution::cdf, "x"_a)
            .def("ppf", &Distribution::ppf, "q"_a)
            .def("mean", &Distribution::mean)
            .def("variance", &Distribution::variance);

      py::class_<ChiSquareDistribution, Distribution>(m, "ChiSquareDistribution")
            .def(py::init<int &>());

      py::class_<ExponentialDistribution, Distribution>(m, "ExponentialDistribution")
            .def(py::init<double &>());
            
      py::class_<GammaDistribution, Distribution>(m, "GammaDistribution")
            .def(py::init<double &, double &>());

      py::class_<NormalDistribution, Distribution>(m, "NormalDistribution")
            .def(py::init<double &, double &>());

      py::class_<StudentTDistribution, Distribution>(m, "StudentTDistribution")
            .def(py::init<double &, double &, double &>());

      py::class_<MersenneTwister>(m, "MersenneTwister")
            .def(py::init<double &, double &, unsigned long long int &>(),
                  "lower_bound"_a=0.0,
                  "upper_bound"_a=1.0,
                  "seed"_a=std::chrono::system_clock::now().time_since_epoch().count())
            .def("random_uniform", &MersenneTwister::random_uniform);

      m.def("welch_test", 
            &welch_test,
            "Returns T-statistic from Welch test.",
            "sample1"_a,
            "sample2"_a);

      m.def("mean", 
            &mean,
            "Returns mean from provided values.",
            "values"_a);
      m.def("variance",
            &variance,
            "Returns variance from provided values.",
            "values"_a,
            "df"_a=1);
      m.def("standard_deviation",
            &standard_deviation,
            "Returns standard_deviation from provided values.",
            "values"_a,
            "df"_a=1);

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