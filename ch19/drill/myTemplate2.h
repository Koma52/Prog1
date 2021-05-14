#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S {
    explicit S(T myVal = 0) : val{myVal} { }

    S& operator=(const T&);

    T& get();
    const T& get() const;

private:
    T val;
};

template<typename T>
T& S<T>::get() { return val; }

template<typename T>
const T& S<T>::get() const { return val; }

template<typename T>
S<T>& S<T>::operator=(const T& newVal) {
    val = newVal;
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

template<typename T>
void read_val(T& v) {
    std::cin >> v;
}