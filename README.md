cookiecutter-cppyy-cmake
========================

A cookiecutter template for using cppyy to generate python bindings for c++ code

Requirements
------------
Install `cookiecutter` command line: `pip install cookiecutter`    

Usage
-----
Generate a new Cookiecutter template layout: `cookiecutter gh:camillescott/cookiecutter-cppyy-cmake `    

You will then be prompted to fill in the values for your project. The project name
can contain spaces; by default, they will be replaced by dashes for the repo name (the name
of the generated folder with the project skeleton) and underscores for the package name
(the name of the python package for the generated bindings). `cpp_lib_name` is the name
of the C++ library being wrapped; it should be different from the `pkg_name`. You needn't
prefix it will "lib," as this will be done for the resulting shared libraries by CMake.
The `cpp_namespace` is the project namespace for the generated code. You don't necessarily need
to keep this in your final project, but for the love of god please namespace your C++ libraries...

See [cppyy-knn](https://github.com/camillescott/cppyy-knn) for an example project.
[cppyy-bbhash](https://github.com/camillescott/cppyy-bbhash) is also based on this template,
though `CMakeLists.txt` is modified to generate a static library.

License
-------
This project is licensed under the terms of the [MIT License](/LICENSE)
