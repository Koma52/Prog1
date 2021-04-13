#include "../../GUI-lib/std_lib_facilities.h"

struct B1{
    virtual void vf() { cout << "B1::vf()" << endl; };
    void f() { cout << "B1::f()" << endl; };
    virtual void pvf() = 0;
};

struct D1:B1{
    void vf() override { cout << "D1::vf()" << endl; };
    void f() { cout << "D1::f()" << endl; };
    void pvf() override { cout << "D1::pvf()" << endl; };
};

struct D2:D1{
    void pvf() override { cout << "D2::pvf()" << endl; };
};

struct B2 {
    virtual void pvf() = 0;
};

struct D21 : B2 {
    string szoveg = "kacsa";
    void pvf() override { cout << szoveg << '\n'; }
};

struct D22 : B2 {
    int szam = 52;
    void pvf() override { cout << szam << '\n'; }
};

void f (B2& b2)
{
    b2.pvf();
}

int main()
try {

    /* Not working because there's a pure virtual function in it
    B1 b;
    b.vf();
    b.f();
    */

   // Not working because pure virt func from parent not defined
    D1 d;
    d.vf();
    d.f();
    d.pvf();
    

    B1& B1ref {d};
    B1ref.vf();
    B1ref.f();
    B1ref.pvf();

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    cout << "----------------------" << endl;

    D21 d21;
    D22 d22;

    f(d21);
    f(d22);

    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
} 
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}