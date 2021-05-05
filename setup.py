import os, sys

from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
from pybind11 import get_cmake_dir

__version__ = "0.0.1"

SOURCE_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "src")


def _source_files():
    source_files = list()
    for path, subdirs, files in os.walk(SOURCE_DIR):
        for name in files:
            source_file = os.path.join(path, name)
            if source_file.endswith(".cpp"):
                source_files.append(source_file)

    return source_files


def main():

    with open("README.md", "r", encoding="utf-8") as fh:
        long_description = fh.read()

    ext_modules = [
        Pybind11Extension("stpp",
                          _source_files(),
                          define_macros=[('VERSION_INFO', __version__)])
    ]

    setup(name="stpp",
          version=__version__,
          author="Konrad Archicinski",
          author_email="konrad.archicinski@gmail.com",
          description="Simple statistical Python package written in C++.",
          long_description=long_description,
          long_description_content_type="text/markdown",
          url="https://github.com/konradarchicinski/stpp",
          project_urls={
              "Bug Tracker": "https://github.com/konradarchicinski/stpp/issues"
          },
          classifiers=[
              "Programming Language :: Python :: 3",
              "License :: OSI Approved :: MIT License",
              "Operating System :: OS Independent"
          ],
          ext_modules=ext_modules,
          cmdclass={"build_ext": build_ext},
          zip_safe=False,
          python_requires=">=3.6")


if __name__ == "__main__":
    main()
