# {{cookiecutter.repo_name}}: cppyy-generated bindings for {{cookiecutter.cpp_lib_name}}

[![Build Status](https://travis-ci.org/{{cookiecutter.github_username}}/{{cookiecutter.repo_name}}.svg?branch=master)](https://travis-ci.org/{{cookiecutter.github_username}}/{{cookiecutter.repo_name}})

This project is set of Python bindings for {{cookiecutter.cpp_lib_name}} using
[cppyy](https://bitbucket.org/wlav/cppyy/src/master/). The project template comes from [camillescott's cookiecutter recipe](https://github.com/camillescott/cookiecutter-cppyy-cmake), in which the CMake sources are based on the bundled cppyy CMake modules, with a number of improvements and changes:

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

    git clone https://github.com/{{cookiecutter.github_username}}/{{cookiecutter.repo_name}}
    cd cppyy-knn

    mkdir build; cd build
    cmake ..
    make install

And then to test:

    py.test -v -s {{cookiecutter.pkg_name}}/tests/test_{{cookiecutter.cpp_lib_name}}.py
