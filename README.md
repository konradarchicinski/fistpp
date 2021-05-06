st++
==============

`st++` or `stpp` stands for statistics++ and it describes simple statistical package written in C++, with Python binding.

Python wrapper is built with [pybind11](https://github.com/pybind/pybind11).


Installation
------------

**On Linux, OS X and Windows** *(tested on Python 3.6+)*

 - clone this repository by `git clone https://github.com/konradarchicinski/stpp`
 - run `pip install ./stpp` from the folder where the repository was downloaded

*for Windows installation of Visual Studio 2015 may be required*


Examples
---------

Simulating numbers from the Standard Normal Distribution
```python
import stpp

norm = stpp.NormalDistribution()
norm_sample = norm.simulate(100)
```

Simulating numbers from the Student's t-distribution
```python
t = stpp.StudentTDistribution()
t_sample = t.simulate(100)
```

Performing Welch's t-test
```python
welch_ttest = stpp.WelchTTest(norm_sample, t_sample)
welch_ttest.pvalue("two-sided")
```