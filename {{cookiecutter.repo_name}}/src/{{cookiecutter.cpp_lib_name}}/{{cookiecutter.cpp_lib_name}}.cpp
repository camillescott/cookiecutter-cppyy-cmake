#include <iostream>

#include "{{cookiecutter.cpp_lib_name}}/{{cookiecutter.cpp_lib_name}}.hh"

namespace {{cookiecutter.cpp_namespace}} {

int {{cookiecutter.cpp_lib_name.capitalize()}}Widget::get() const {
    return n;
}

}
