//---------------------------------------------------------
// Fichier        : annexes.cpp (le corps de sous-programmes du .h)
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-09-15
// But            : ne contient que les définitions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include "annexe.h"    // inclure la spec de ce .cpp

using namespace std;

const int CONSTANTE = 12;

//-------------------------------------------------------------------------
// un sous-programme interne à la librairie
void cachee (const int valeur) {
   cout << valeur;
}

//-------------------------------------------------------------------------
// un sous-programme visible par main
void sousPgm (const string& msg) {
   cout << msg;
   cachee(CONSTANTE);  // appel de la fonction interne
}
