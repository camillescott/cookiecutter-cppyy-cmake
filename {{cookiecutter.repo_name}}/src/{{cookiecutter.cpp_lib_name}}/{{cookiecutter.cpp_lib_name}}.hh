namespace {{cookiecutter.cpp_namespace}} {

class {{cookiecutter.cpp_lib_name.capitalize()}}Widget {
protected:

    int n;

public:

    {{cookiecutter.cpp_lib_name.capitalize()}}Widget(int n)
        : n(n) 
    {
    }

    int get() const;

};


template <typename T>
class {{cookiecutter.cpp_lib_name.capitalize()}}Gadget {
    
    T n;

public:

    {{cookiecutter.cpp_lib_name.capitalize()}}Gadget(T n)
        : n(n)
    {
    }

    T get() {
        return n;
    }
};

}
