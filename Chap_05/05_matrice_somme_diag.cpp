//---------------------------------------------------------
// Fichier        : 05_matrice_somme_diag.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-01
// But            : déterminer la somme des éléments diagonaux d'une matrice
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//---------------------------------------------------------
// types de données
using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

//---------------------------------------------------------
// fonctions auxiliaires
ostream& operator<<(ostream& os, const Vecteur& v);
ostream& operator<<(ostream& os, const Matrice& m);

//---------------------------------------------------------
bool estCarree(const Matrice& m);
bool sommesElementsDiagonaux(const Matrice& matrice,
                             int&  sommeDiagGauche,
                             int&  sommeDiagDroite);
void test(const Matrice& m);

//---------------------------------------------------------
int main() {

   Matrice m1;
   Matrice m2 = {{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}};
   Matrice m3 = {{1, 2, 3},
                 {4, 5},
                 {7, 8, 9}};
   Matrice m4 = {{1, 2, 3},
                 {4, 5, 6}};

   test(m1);
   test(m2);
   test(m3);
   test(m4);

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
bool estCarree(const Matrice& m) {
   if (m.empty())
      return true;
   for (size_t i=0; i<m.size(); ++i) {
      if (m[i].size() != m.size())
         return false;
   }
   return true;
}

//---------------------------------------------------------
bool sommesElementsDiagonaux(const Matrice& matrice,
                             int& sommeDiagGauche,
                             int& sommeDiagDroite) {

   if (!estCarree(matrice))
      return false;

   const size_t TAILLE = matrice.size();
   sommeDiagGauche = sommeDiagDroite = 0;
   for (size_t i = 0; i < TAILLE; ++i) {
      sommeDiagGauche += matrice[i][i];
      sommeDiagDroite += matrice[i][TAILLE - i - 1];
   }

   return true;
}

//---------------------------------------------------------
void test(const Matrice& m) {
   int sommeDG = 0,
       sommeDD = 0;
   cout << m << endl;
   const bool carree = sommesElementsDiagonaux(m, sommeDG, sommeDD);
   if (carree) {
      cout << "somme DG : " << sommeDG << endl;
      cout << "somme DG : " << sommeDG << endl;
   }
   else
      cout << "/!\\ la matrie n'est pas carrée" << endl;
   cout << endl;
}

//---------------------------------------------------------
ostream& operator<<(ostream& os, const Vecteur& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }

   os << "]";
   return os;
}

//---------------------------------------------------------
ostream& operator<<(ostream& os, const Matrice& m) {
   if (m.empty())
      cout << "[]";
   for (size_t i=0; i<m.size(); ++i) {
      os << m[i] << endl;
   }
   return os;
}
