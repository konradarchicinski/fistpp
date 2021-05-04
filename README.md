st++
==============

`st++` or `stpp` stands for statistics++ — it is a simple statistical package written in C++,
bind with Python wrapper.

Project wrapper is built with [pybind11](https://github.com/pybind/pybind11).


Installation
------------

**On Unix (Linux, OS X)**

 - clone this repository
 - `pip install ./stpp`

**On Windows (tested on Python 3.5+)**

 - clone this repository
 - `pip install ./stpp`


 Test call
---------

```python
import stpp
norm = stpp.NormalDistribution(0.0, 1.0)
norm.simulate(10)
```