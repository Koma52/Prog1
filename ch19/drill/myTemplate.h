#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S {
    S (T myVal = 0) : val{myVal} { }

    S& operator=(const T&);

    T& get();
    const T& get() const;

private:
    T val;
};

template<typename T>
T& S<T>::get(){ return val; }

template<typename T>
const T& S<T>::get() const { return val; }

template<typename T>
S<T>& S<T>::operator=(const T& newValue){
    val = newValue;
    return *this;
}

template<typename T>
std::istream& operator>>(std::istream& is, T& v){
    T newVal;

    is >> newVal;

    v = newVal;

    return is;
}

template<typename T>
void read_val(T& v){
    std::cin >> v;
}