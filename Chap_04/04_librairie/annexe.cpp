/* Fichier : annexes.cpp (le corps de sous-programmes du .h)
 * Auteur  : Guy-Michel Breguet / HEIG-VD
 * Date    : 05.11.2020
 *
 * But     : ne contient que les définitions
 *
 * Remarque(s) :
 *
 * Modifications : Date / Auteur / Raison
 *
 */

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
