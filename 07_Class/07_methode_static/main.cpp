//---------------------------------------------------------
// Demo           : 07_methode_static
// Fichier        : main.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-07
// But            : démontrer méthodes static
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // cout et cin

#include "classe.h"

using namespace std;

int main() {
   
   Classe::afficherStat();    // méthode statique (hors objet)
   cout << endl;
   
   {
      Classe c1(10);
      c1.afficherObj();
      cout << endl;

      Classe c2(20);
      c2.afficherObj();
      cout << endl;
   }
   
   Classe::afficherStat();    // méthode statique (hors objet)
   cout << endl;

   Classe c3(30);
   c3.afficherObj();
   cout << endl;

   c3.afficherStat();         // méthode statique via un objet
//   Classe::afficherObj();   // pas possible
   
   return EXIT_SUCCESS;
}
