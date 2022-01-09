//---------------------------------------------------------
// Demo           : 08_specialisation_partielle_class
// Fichier        : 08_specialisation_partielle_class.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-13
// But            : démontrer l'algorithme utilisé pour sélectionner une class
//                  en cas de spécialisation et de surcharge
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//---------------------------------------------------
// fonctions génériques
//---------------------------------------------------
template <typename T, typename U>
void f(T t, U u) {
   cout << "f<T, U>" << endl;
}

//// specialisation partielle => ne compile pas
//template <typename U>
//void f<int, U>(int t, U u) {}  // ne compile pas

// specialisation complete
template <>
void f<int, float>(int t, float u) {
   cout << "f<int, float>" << endl;
}

//---------------------------------------------------
// surcharge, pas spécialisation
template <typename U>
void f(int t, U u) {
   cout << "f<int, U>" << endl;
}

//---------------------------------------------------
// surcharge non générique
void f(int t, double d) {
   cout << "f(int, double)" << endl;
}

//---------------------------------------------------
// classes génériques
//---------------------------------------------------
template <typename T, typename U>
class C {
public:
   C() { cout << "C<T, U>" << endl; }
private:
   T t;
   U u;
};

// specialisation partielle
// compile au contraire des fonctions
// avec spécialisation partielle
template <typename U>
class C<int, U> {
public:
   C() { cout << "C<int, U>" << endl; }
private:
   int i;
   U   u;
};

// specialisation complete
template <>
class C<int, float> {
public:
   C() { cout << "C<int, float>" << endl; }
private:
   int   i;
   float f;
};


//---------------------------------------------------
int main() {
   //------------------------------------------------
   // fonctions génériques
   //------------------------------------------------
   cout << "01) ";    f('a', 'b');     // => {} f<T, U>
   cout << "02) ";    f(1.2, 3);       // => {} f<T, U>
   cout << "03) ";    f(1, 2.3f);      // => {} f<int, U>
   cout << "04) ";    f(1, 2);         // => {} f<int, U>

   cout << "11) ";    f<>('a', 'b');   // => {} f<T, U>
   cout << "12) ";    f<>(1.2, 3);     // => {} f<T, U>
   cout << "13) ";    f<>(1, 2.3f);    // => {} f<int, U>
   cout << "14) ";    f<>(1, 2);       // => {} f<int, U>

   //------------------------------------------------
   // classes génériques
   //------------------------------------------------
}

