FiSt++
==============

`FiSt++` or `fistpp` stands for Finance and Statistics, it is a simple package containing a collection of selected basic tools used in finance and statistics. Package is mostly written in C++, with Python bindings allowing run all functionalities using Python interpreter.

Python wrapper is built with [pybind11](https://github.com/pybind/pybind11).


Installation
------------

**On Linux, OS X and Windows** *(tested on Python 3.6+)*

 - clone this repository by `git clone https://github.com/konradarchicinski/fistpp`
 - run `pip install ./fistpp` from the folder where the repository was downloaded

*for Windows installation of Visual Studio 2015 may be required*


Examples
---------

Simulating numbers from the Standard Normal Distribution
```python
import fistpp as fs

norm = fs.NormalDistribution()
norm_sample = norm.simulate(100)
```

Simulating numbers from the Student's t-distribution
```python
t = fs.StudentTDistribution()
t_sample = t.simulate(100)
```

Performing Welch's t-test
```python
welch_ttest = fs.WelchTTest(norm_sample, t_sample)
welch_ttest.pvalue("two-sided")
```