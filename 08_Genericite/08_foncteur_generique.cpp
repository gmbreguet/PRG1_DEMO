//---------------------------------------------------------
// Demo           : 08_foncteur_generique
// Fichier        : 08_foncteur_generique.cpp
// Version        : 01 - 2022.01.15
// Auteur(s)      : BREGUET Guy-Michel
// But            : exemple de foncteur générique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <cmath>        // hypot
#include <algorithm>
#include <vector>

using namespace std;

//---------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   os << "[";
   for(size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   } 
   os << "]";
   return os;
}

//---------------------------------------------------
template <typename T>
class Coord;                     // pré-déclaration pour la fonction amie

//---------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const Coord<T>& c) {
   os << "(" << c.x << ", " << c.y << ")";
   return os;
}

//---------------------------------------------------
template <typename T>
class Coord {
   friend ostream& operator<< <T>(ostream& os, const Coord<T>& c);

public:
   Coord(T x, T y) : x(x), y(y) {};

   bool operator< (const Coord& c) const {
      return hypot(x, y) < hypot(c.x, c.y); }

   bool operator== (const Coord& c) const {
      return x == c.x and y == c.y; }

private:
   T x;
   T y;
};

//---------------------------------------------------
// foncteur de comparaison
// nb les & pour éviter les copies
template <typename T>
class LowerThan {
public:
   LowerThan(const T& t) : t(t) {};
   bool operator() (const T& other) {return other < t; }; 
private:
   const T& t;
};

//---------------------------------------------------
template <typename T>
void test (const vector<T>& vecteur, const T& valeur) {
   cout << endl;
   cout << "vecteur : " << vecteur << endl; 
   cout << "nbre de "  << valeur << " : " << count(vecteur.begin(), vecteur.end(), valeur) << endl;
   cout << "nbre < a " << valeur << " : " << count_if(vecteur.begin(), vecteur.end(), LowerThan(valeur)) << endl;
}

//---------------------------------------------------
using VectInt        = vector<int>;
using VectDouble     = vector<double>;
using VectCoordInt   = vector<Coord<int>>;

//---------------------------------------------------
int main() {

   // vecteurs à traiter
   VectInt      vInt        = {4,  8,  3,  9,  8,  2,  1,  5,  6};
   VectDouble   vDouble     = {4., 8., 3., 9., 8., 2., 1., 5., 6.};
   VectCoordInt vCoordInt   = {{0, 1}, {1, 0}, {4, 5}, {1, 4}, {4, 5}};
   
   test<int>(vInt, 8);
   test<double>(vDouble, 8.);
   test<Coord<int>>(vCoordInt, {4, 5});

   return EXIT_SUCCESS;
}

