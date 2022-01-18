//---------------------------------------------------------
// Demo           : 07_amities_fct_independante_amie_de_plusieurs_classes
// Fichier        : main.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer des fonctions et classes amies
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include "c1.hpp"
#include "c2.hpp"
using namespace std;

//--------------------------------------------------------
void afficher(const C1& c1, const C2& c2) {
   cout << "(" << c1.n << ", " << c2.x << ")\n";
}
 
//--------------------------------------------------------
int main() {
   C1 c1;
   C2 c2(1.0);
   afficher(c1, c2); // affichera (0, 1)

   return EXIT_SUCCESS;
}
