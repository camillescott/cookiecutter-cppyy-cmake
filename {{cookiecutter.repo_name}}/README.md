# cppyy-knn: An example of cppyy-generated bindings for a simple knn implementation

[![Build Status](https://travis-ci.org/camillescott/cppyy-knn.svg?branch=master)](https://travis-ci.org/camillescott/cppyy-knn)

This is an example project showing how to integrate a C++ kNearestNeighbors implementation with
[cppyy](https://bitbucket.org/wlav/cppyy/src/master/) to enable calling from Python. It's c++ code
comes from an [alternative example](https://github.com/jclay/cppyy-knearestneighbors-example) which
uses cppyy's bundled cmake sources; this version is based on my own rewrite first demonstrated in
[cppyy-bbhash](https://github.com/camillescott/cppyy-bbhash). This packaging implementation makes a 
number of improvements and changes:

- `genreflex` and a selection XML are use instead of a direct `rootcling` invocation. This makes
    name selection much easier.
- Python package files are generated using template files. This allows them to be customized for the
    particular library being wrapped.
- The python package is more complete: it includes a MANIFEST, LICENSE, and README; it properly
    recognizes submodules; it includes a tests submodule for bindings tests; it directly copies a
    python module file and directory structure for its pure python code.
- The cppyy initializor routine has basic support for packaging cppyy pythonizors. These are stored
    in the pythonizors/ submodule, in files of the form `pythonize_*.py`. The pythonizor routines
    themselves should be named `pythonize_<NAMESPACE>_*.py`, where `<NAMESPACE>` refers to the
    namespace the pythonizor will be added to in the `cppyy.py.add_pythonization` call. These will
    be automatically found and added by the initializor.

cppyy-bbhash has a more complicated C++ codebase, with templating and namespaces; however, it's
header only and I opted to simply compile it into a static library and bundle it with the bindings'
shared library. Here, I've created dynamic library, linked the cppyy bindings library against it,
set up things to be relocatable, and set up all the install targets to install both the library
headers and SO and the Python wheel.

## Repo Structure

- `CMakeLists.txt`: The CMake file for bindings generation.
- `selection.xml`:  The genreflex selection file.
- `interface.hh`:   The interface header used by genreflex. Should include the headers and template
    declarations desired in the bindings.
- `cmake/`: CMake files for the build. Should not need to be modified.
- `pkg_templates/`: Templates for the generated python package. Users can modify the templates to
    their liking; they will be configured and copied into the build and package directory.
- `py/`: Python package structure that will be copied into the generated package. Add any pure
    python code you'd like include in your bindings package here.
- `py/initializor.py`: The cppyy bindings initializor that will be copied in the package. Do not
    delete!

## Example Usage

For this repository with anaconda:

    conda create -n cppyy-example python=3 cmake cxx-compiler c-compiler clangdev libcxx libstdcxx-ng libgcc-ng pytest
    conda activate cppyy-example 
    pip install cppyy clang

    git clone https://github.com/camillescott/cppyy-knn
    cd cppyy-knn

    mkdir build; cd build
    cmake ..
    make install

And then to test:

    py.test -v -s cppyy_simpleknn/tests/test_knn.py

I still generate the `knn` c++ executable; it gets spit out in the build directory. The test files
demonstrates the bindings usage:

```python
from cppyy.gbl import std
from cppyy_simpleknn import NearestNeighbors, Point


def test_point_iter_pythonizor():
    pt = Point(1.0, 2.0)
    test = [p for p in pt]
    assert test == [1.0, 2.0]


def test_point_repr_pythonizor():
    pt = Point(1.0, 2.0)
    assert repr(pt) == '(1.0, 2.0)'


def test_knn_nearest():
    knn = NearestNeighbors()
    points = [Point(2,0), Point(1,0), Point(0,10), Point(5,5), Point(2,5)]
    knn.points = std.vector[Point](points)
    result = [tuple(res) for res in knn.nearest(Point(0.0, 0.0), 3)]
    assert result == [(1.0, 0.0), (2.0, 0.0), (2.0, 5.0)]
```
