from cppyy.gbl import std
from {{cookiecutter.pkg_name}} import {{cookiecutter.cpp_lib_name}}Widget, {{cookiecutter.cpp_lib_name}}Gadget


def test_{{cookiecutter.pkg_name}}_widget():
    w = {{cookiecutter.cpp_lib_name}}Widget(-3)
    assert w.get() == -3


@pytest.mark.parametrize("member_t, member_val", [(int, 1), (float, 3.1), (bool, False)])
def test_{{cookiecutter.pkg_name}}_gadget(member_t, member_val):
    g = {{cookiecutter.cpp_lib_name}}Gadget[member_t](member_val)
    assert g.get() == member_val
