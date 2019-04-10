set(_headers
    {{cookiecutter.cpp_lib_name}}/{{cookiecutter.cpp_lib_name}}.hh
)

set(_sources
    {{cookiecutter.cpp_lib_name}}/{{cookiecutter.cpp_lib_name}}.cpp
)

foreach (path ${_headers})
    list(APPEND LIB_HEADERS ${CMAKE_SOURCE_DIR}/src/${path})
endforeach(path)

foreach (path ${_sources})
    list(APPEND LIB_SOURCES ${CMAKE_SOURCE_DIR}/src/${path})
endforeach(path)
