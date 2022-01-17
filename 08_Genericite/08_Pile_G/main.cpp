//---------------------------------------------------------
// Demo           : 08_Pile_G
// Fichier        : main.cpp
// Version        : 01 - 2022.01.18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer la compiltion séparée et donner
//                  un exemple des methodes Pile::at()
//                  est des operators Pile::operator[]
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include "Pile_G.h"

using namespace std;

//---------------------------------------------------
int main() {

   Pile<int> pile(10);
   int i=0;
   while (not pile.estPleine()) {
      cout << "empiler("<< i << ")"          << endl;
      pile.empiler(i++);
   }

   cout << endl;
   cout << "pile[5]    : " << pile[5]        << endl;
   cout << "pile.at(5) : " << pile.at(5)     << endl;

   cout << endl;
   cout << "pile[5]    = 10"                 << endl;
   pile[5] = 10;
   cout << "pile[5]    : " << pile[5]        << endl;

   cout << endl;
   cout << "pile.at(5) = 20" << endl;
   pile.at(5) = 20;
   cout << "pile.at(5) : " << pile.at(5)     << endl;

   cout << endl;
   while (not pile.estVide()) {
      cout << "dernier : " << pile.dernier() << endl;
      pile.depiler();
   }

   return EXIT_SUCCESS;
}

