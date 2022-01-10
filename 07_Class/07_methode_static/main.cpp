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

#include "Classe.h"

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
/*
CONST_STAT : 100
next       : 1
total      : 0

NO_OBJ     : 1
valeur     : 10
CONST_STAT : 100
next       : 2
total      : 1
CONST_STAT : 100
next       : 2
total      : 1
CONST_STAT : 100
next       : 2
total      : 1

NO_OBJ     : 2
valeur     : 20
CONST_STAT : 100
next       : 3
total      : 2
CONST_STAT : 100
next       : 3
total      : 2
CONST_STAT : 100
next       : 3
total      : 2

CONST_STAT : 100
next       : 3
total      : 0

NO_OBJ     : 3
valeur     : 30
CONST_STAT : 100
next       : 4
total      : 1
CONST_STAT : 100
next       : 4
total      : 1
CONST_STAT : 100
next       : 4
total      : 1

CONST_STAT : 100
next       : 4
total      : 1
*/
