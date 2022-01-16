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
#include <algorithm>    // count, count_if
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
   Coord() : x(0), y(0) {}
   Coord(T x, T y) : x(x), y(y) {}
   Coord(const Coord& c) { x = c.x; y = c.y; } 

   Coord& operator= (const Coord& c) {
      x = c.x;
      y = c.y;
      return *this;
   }

   // distance de (0, 0)
   bool operator< (const Coord& c) const {
      return hypot(x, y) < hypot(c.x, c.y); }

   // même position
   bool operator== (const Coord& c) const {
      return x == c.x and y == c.y; }

private:
   T x;
   T y;
};

//---------------------------------------------------
// foncteur de comparaison
template <typename T>
class LowerThan {
public:
   LowerThan(const T& t) : ref(t) {};
   bool operator() (const T& actual) { return actual < ref; }; 
private:
   const T& ref;
};

//---------------------------------------------------
template <typename T>
void test (const vector<T>& vecteur, const T& valeur) {
   cout << endl;
   cout << "vecteur " << vecteur << endl; 
   cout << "nbre de " << valeur  << " : " << count   (vecteur.begin(), vecteur.end(),           valeur)  << endl;
   cout << "nbre <  " << valeur  << " : " << count_if(vecteur.begin(), vecteur.end(), LowerThan(valeur)) << endl;
}

//---------------------------------------------------
// exemples de using génériques
using VectInt        = vector<int>;
using VectDouble     = vector<double>;
using VectCoordInt   = vector<Coord<int>>;

//---------------------------------------------------
int main() {

   // vecteurs à traiter
   VectInt      vInt        = {4,   8,   3,   9,   8,   2,   1,   5,   6};
   VectDouble   vDouble     = {4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1};
   VectCoordInt vCoordInt   = {{0, 1}, {1, 0}, {4, 5}, {1, 4}, {4, 5}};

   test<int>(vInt, 8);
   test<double>(vDouble, 8.1);
   test<Coord<int>>(vCoordInt, {4, 5});

   return EXIT_SUCCESS;
}

//    vecteur [4, 8, 3, 9, 8, 2, 1, 5, 6]
//    nbre de 8 : 2
//    nbre <  8 : 6
//    
//    vecteur [4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1]
//    nbre de 8.1 : 2
//    nbre <  8.1 : 6
//    
//    vecteur [(0, 1), (1, 0), (4, 5), (1, 4), (4, 5)]
//    nbre de (4, 5) : 2
//    nbre <  (4, 5) : 3

