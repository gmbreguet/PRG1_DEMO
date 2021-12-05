//---------------------------------------------------------
// Fichier        : 05_supression.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-05
// But            : comparer des algorithmes de supressions O(n) et O(n2)
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

using Type      = int;
using Vecteur1D = vector<Type>;


//------------------------------------------------------
ostream& operator<< (ostream& os, const Vecteur1D& v);

//------------------------------------------------------
void supprimerPos(Vecteur1D& v, size_t pos);
void supprimerValeurOn(Vecteur1D& v, const Type& valeur);
void supprimerValeurOn2(Vecteur1D& v, const Type& valeur);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   //---------------------------------------------------
   Vecteur1D vect = {2, 3, 5, 7, 11, 13};
   cout << "vect : " << vect << endl;
   supprimerPos(vect, 2);
   cout << "vect : " << vect << endl;


}  // main


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
void supprimerPos(Vecteur1D& v, size_t pos) {

   // ne rien faire si vide ou pos mal positionné
   if (v.empty() or pos >= v.size())
      return;

   // décaler toutes les valeurs adjacentes
   for (size_t i=pos; i<v.size()-1; ++i) {
      v[i] = v[i+1];
   }

   // mise à jour de la taille
//   v.resize(v.size()-1);
}

//------------------------------------------------------
void supprimerValeurOn2(Vecteur1D& v, const Type& valeur){

   using Iter = Vecteur1D::iterator;

   // parcourir tout le tableau
   for (Iter it=v.begin(); it!=v.end(); ++it) {

      // si la valeur est trouvée
      if (*it == valeur)  {


         // réduire la taille après le décallage
         v.resize(v.size() - 1);
      }  // if

   } // for
}


//------------------------------------------------------
void supprimerValeurOn(Vecteur1D& v, const Type& valeur) {

//   for (auto it=v.begin(); it!=v.end(); ++it) {
//
//      if (*it == valeur) // si la valeur est trouvée {
//
//         // écrire sélectivement les valeurs adjacentes
//
//         }
//   }
}

