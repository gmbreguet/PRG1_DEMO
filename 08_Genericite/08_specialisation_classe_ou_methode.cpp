//---------------------------------------------------------
// Demo           : 08_specialisation_classe_ou_methode
// Fichier        : 08_specialisation_classe_ou_methode.cpp
// Version        : 01 - 2022.01.15
// Auteur(s)      : BREGUET Guy-Michel
// But            : spécialisation classe ou méthode
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------
// 1) class générique
//---------------------------------------------------
template <typename T>
class Time {
public:
   Time(T h, T m) : h(h), m(m) {}
   void put() const { cout << "1) " << h << ":" << m; }
private:
   T h;
   T m;
};

//---------------------------------------------------
// 2) class générique spécialisation
//    => ré-écriture complète de la classe
//---------------------------------------------------
template <>
class Time<double> {
public:
   Time(double h, double m) : h(h), m(m) {}
   void put() const { cout << "2) "  << h << ":" << m; }
private:
   double h;
   double m;
};

//---------------------------------------------------
// 3) spécialisation de la méthode Time::put()
//    => ré-écriture de la méthode seulement
//---------------------------------------------------
template <>
void Time<unsigned>::put() const { cout << "3) "  << h << ":" << m; }

//---------------------------------------------------
// instanciation explicite
template class Time<int>;

//---------------------------------------------------
int main() {

   // utilisation de l'instanciation explicite
   Time t1(12,   23);      t1.put();         cout << endl;     // => 1) 1:23

   // instanciations implicites
   Time t2(12.f, 23.f);    t2.put();         cout << endl;     // => 1) 12:23
   Time t3(12.,  23.);     t3.put();         cout << endl;     // => 2) 12:23
   Time t4(12u,  23u);     t4.put();         cout << endl;     // => 3) 12:23

   return EXIT_SUCCESS;
}

