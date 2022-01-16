//---------------------------------------------------------
// Demo           : 08_class_en_et_non-gen
// Fichier        : 08_sclass_en_et_non-gen
// Version        : 01 - 2022.01.15
// Auteur(s)      : BREGUET Guy-Michel
// But            : peut-on surcharger une classe ?
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------
// 1) class générique
//---------------------------------------------------
template <typename T, typename U>
class C {
public:
   C(T t, U u) : t(t), u(u) { cout << "1) C<T, U>" << endl; }
private:
   T t;
   U u;
};

//---------------------------------------------------
// 2) class générique spécialisée
//---------------------------------------------------
template <typename T>
class C<T, T> {
public:
   C(T t1, T t2) : t1(t1), t2(t2) { cout << "2) C<T, T>" << endl; }
private:
   T t1;
   T t2;
};

//---------------------------------------------------
// 3) class non-générique
// => ne compile pas
//---------------------------------------------------
// class C {
// public:
//    C(int i1, int i2) : i1(i1), i2(i2) { cout << "3) C" << endl; }
// private:
//    int i1;
//    int i2;
// };


//---------------------------------------------------
int main() {

   C c;           // class non générique

   return EXIT_SUCCESS;
}

