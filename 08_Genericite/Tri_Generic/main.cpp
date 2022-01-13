//---------------------------------------------------------
// Demo           : 08_Tri_Generique
// Fichier        : main.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2022-01-12
// But            : demontration d'un tri générique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "tri.h"
#include "Couleur.h"

using namespace std;

using VectInt     = vector<int>;
using VectCouleur = vector<Couleur>;
using VectString  = vector<string>;

//--------------------------------------------------------------
template <typename T>
ostream& operator << (ostream& os, const vector<T>& v);

//----------------------------------------
template <typename V>
void test (V& v) {
   cout << v << endl;
   trier(v);
   cout << v << endl;
   cout << endl;
}

//--------------------------------------------------------------
int main () {

   // vecteurs à trier
   VectInt     vInt      = {4, 8, 3, 9, 7, 2, 1, 5, 6};
   VectString  vString   = {"pomme", "citron", "orange", "banane"};
   VectCouleur vCouleur  = {Couleur::Liste::ORANGE, Couleur::Liste::GRAY, Couleur::Liste::CYAN, Couleur::Liste::RED};
   
   cout  << string(Couleur::Liste::ORANGE) << endl;
   cout  << (string)Couleur::Liste::ORANGE << endl;

   //-------------------------------------
   // tris génériques
   test(vInt);
   test(vString);
   test(vCouleur);
   
   //-------------------------------------
   return EXIT_SUCCESS;
}

//--------------------------------------------------------------
template <typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
   os << "[";
   for (size_t i=0; i<v.size(); i++) {
      if (i)
         os << ", ";
      os << v.at(i);
   }
   os << "]";
   return os;
}
/*
[4, 8, 3, 9, 7, 2, 1, 5, 6]
[1, 2, 3, 4, 5, 6, 7, 8, 9]

[pomme, citron, orange, banane]
[banane, citron, orange, pomme]

[orange, gray, cyan, red]
[red, cyan, gray, orange]
*/
