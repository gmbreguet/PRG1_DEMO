//----------------------------------------------------------
// Demo           : 07_constructor_explicit
// Fichier        : main.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-17
// But            : démontrer les constructeurs
//                  et contraintes liees a explicit
// Modifications  :
// Remarque(s)    : NILL
//----------------------------------------------------------

#include <iostream>

using namespace std;

//----------------------------------------------------------
class A {
public:
            A()            { a=0;   cout << "A::A()"         << endl; }
            A(int      i)  { a=i;   cout << "A::A(int)"      << endl; }
            A(double   d)  { a=d;   cout << "A::A(double)"   << endl; }
            A(const A& c)  { a=c.a; cout << "A::A(const A&)" << endl; }
private:
   int a;
};

//----------------------------------------------------------
class B {
public:
            B()            { b=0;   cout << "B::B()"         << endl; }
   explicit B(int      i)  { b=i;   cout << "B::B(int)"      << endl; }
   explicit B(double   d)  { b=d;   cout << "B::B(double)"   << endl; }
   explicit B(const B& c)  { b=c.b; cout << "B::B(const B&)" << endl; }
private:
   int b;
};

//----------------------------------------------------------
int main() {

   A a0;           // A::A()
   A a01(2);       // A::A(int)
   A a02=2;        // A::A(int)
   A a03{2};       // A::A(int)
   A a04={2};      // A::A(int)
   A a05(1.2);     // A::A(double)
   A a06=1.2;      // A::A(double)
   A a07{1.2};     // A::A(double)
   A a08={1.2};    // A::A(double)
   A a09(a0);      // A::A(const A&)
   A a10=a0;       // A::A(const A&)
   A a11{a0};      // A::A(const A&)
   A a12={a0};     // A::A(const A&)

   cout << endl;

   B b0;           // B::B()
   B b01(2);       // B::B(int)
// B b02=2;        // B::B(int)
   B b03{2};       // B::B(int)
// B b04={2};      // B::B(int)
   B b05(1.2);     // B::B(double)
// B b06=1.2;      // B::B(double)
   B b07{1.2};     // B::B(double)
// B b08={1.2};    // B::B(double)
   B b09(b0);      // B::B(const B&)
// B b10=b0;       // B::B(const B&)
   B b11{b0};      // B::B(const B&)
// B b12={b0};     // B::B(const B&)

}
