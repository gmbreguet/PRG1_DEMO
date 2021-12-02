//---------------------------------------------------------
// Fichier        : 05_init_vector_array.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : démontrer les initialisations possibles de vector et array
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

//---------------------------------------------------------
using Vecteur1D = vector<int>;
using Vecteur2D = vector<Vecteur1D>;
// https://www.cplusplus.com/reference/vector/vector/vector/

using Array1D   = array<int,3>;
using Array2D   = array<Array1D, 3>;
// https://www.cplusplus.com/reference/array/array/array

Array1D a1global;                            // [0, 0, 0]   => initialisé à 0

//---------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur1D& v);
ostream& operator<< (ostream& os, const Vecteur2D& v);

ostream& operator<< (ostream& os, const Array1D& a);
ostream& operator<< (ostream& os, const Array2D& a);

//---------------------------------------------------------
int main() {

   //------------------------------------------------------
   // Vecteurs 1D
   //------------------------------------------------------
   Vecteur1D v1a;                               // []
   Vecteur1D v1b();                             // /!\ => déclaration d'une fonction
   Vecteur1D v1c(5);                            // [0, 0, 0]   => constructeur
   Vecteur1D v1d(3, 2);                         // [2, 2, 2]   => constructeur
   Vecteur1D v1e{1, 2, 3};                      // [1, 2, 3]   => liste d'initialisation
   Vecteur1D v1f = {1, 2, 3};                   // [1, 2, 3]   => par agrégat
   Vecteur1D v1g = Vecteur1D{1, 2, 3};          // [1, 2, 3]   => constructeur par copie
   Vecteur1D v1h; v1h = v1g;                    // [1, 2, 3]   => operateur de copie
//   cout << v1d << endl;

   //------------------------------------------------------
   // Vecteurs 2D
   //------------------------------------------------------
   Vecteur2D v2a;                               // []
   Vecteur2D v2b(3);                            // [[], [], []]
   Vecteur2D v2c(3, v1d);                       // [[2, 2, 2], [2, 2, 2], [2, 2, 2]]
   Vecteur2D v2d(3, {1, 2, 3});                 // [[1, 2, 3], [1, 2, 3], [1, 2, 3]]
   Vecteur2D v2e(3, Vecteur1D{1, 2, 3});        // [[1, 2, 3], [1, 2, 3], [1, 2, 3]]
   Vecteur2D v2f = {{1, 2, 3}, {4, 5, 6}};      // [[1, 2, 3], [4, 5, 6]]
   Vecteur2D v2g = {v1c, v1d, v1f};             // [[0, 0, 0, 0, 0], [2, 2, 2], [1, 2, 3]]
//   cout << v2g << endl;

   //------------------------------------------------------
   // Array 1D
   //------------------------------------------------------
   Array1D a1a;                                 // [?, ?, ?]   => non initialisé
   Array1D a1b{1, 2, 3};                        // [1, 2, 3]   => liste d'initialisation
   Array1D a1c = {1, 2, 3};                     // [1, 2, 3]   => par agrégat
   Array1D a1d = Array1D{1, 2, 3};              // [1, 2, 3]   => constructeur par copie
   Array1D a1e; a1e = a1b;                      // [1, 2, 3]   => operateur de copie
   static Array1D a1f;                          // [0, 0, 0]   => initialisé à 0 (static)
//   cout << a1a << endl;

   //------------------------------------------------------
   // Array 2D
   //------------------------------------------------------
   Array2D a2a;                                 // []
   Array2D a2b = {Array1D{1}, Array1D{4, 5}};   // [[1, 0, 0], [4, 5, 0], [0, 0, 0]]
   Array2D a2c = {a1a, a1b, a1c};               // [[0, 0, 0, 0, 0], [2, 2, 2], [1, 2, 3]]
   cout << a2b << endl;

   return EXIT_SUCCESS;
}

//------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur1D& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur2D& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
ostream& operator<< (ostream& os, const Array1D& a) {
   os << "[";
   for (size_t i=0; i<a.size(); ++i) {
      if (i)
         os << ", ";
      os << a[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
ostream& operator<< (ostream& os, const Array2D& a) {
   os << "[";
   for (size_t i=0; i<a.size(); ++i) {
      if (i)
         os << ", ";
      os << a[i];
   }
   os << "]";
   return os;
}
