//---------------------------------------------------------
// Demo           : 08_parcours_fonction
// Fichier        : 08_parcours_fonction.cpp
// Version        : 01 - 2022.01.16
// Auteur(s)      : BREGUET Guy-Michel
// But            : exemple de foncteur générique utilisé comme fonction dans un parcours
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
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

   // nécessaire pour le foncteur Plus
   Coord operator+ (const Coord& c) const { return {x + c.x, y + c.y}; }

private:
   T x;
   T y;
};

//---------------------------------------------------
// foncteur comme paramètre générique de fonction
template <typename T>
class Plus {
public:
   Plus(const T& t) : valeur(t) {};
   T operator() (const T& actuel) const { return actuel + valeur; }; 
private:
   const T& valeur;
};

//---------------------------------------------------
template <typename T, typename Fonction>
void parcourir(vector<T>& vecteur, Fonction fonction) {
   for (T& t : vecteur)
      t = fonction(t);
}

//---------------------------------------------------
template <typename T>
void test (vector<T>& vecteur, const T& valeur) {
   cout << endl;
   cout << "vecteur " << vecteur << endl; 
   parcourir(vecteur, Plus(valeur));
   cout << "vecteur " << vecteur << endl; 
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

   test<int>(vInt, 2);
   test<double>(vDouble, 2.1);
   test<Coord<int>>(vCoordInt, {1, 2});

   return EXIT_SUCCESS;
}

//    vecteur [4, 8, 3, 9, 8, 2, 1, 5, 6]
//    vecteur [6, 10, 5, 11, 10, 4, 3, 7, 8]
//    
//    vecteur [4.1, 8.1, 3.1, 9.1, 8.1, 2.1, 1.1, 5.1, 6.1]
//    vecteur [6.2, 10.2, 5.2, 11.2, 10.2, 4.2, 3.2, 7.2, 8.2]
//    
//    vecteur [(0, 1), (1, 0), (4, 5), (1, 4), (4, 5)]
//    vecteur [(1, 3), (2, 2), (5, 7), (2, 6), (5, 7)]

