/* Fichier : main.cpp
 * Auteur  : Guy-Michel Breguet / HEIG-VD
 * Date    : 05.11.2020
 *
 * But     : exemple d'utilisation d'une
 *           librairie personnelle
 *
 * Remarque(s) :
 *
 * Modifications : Date / Auteur / Raison
 *
 */

#include <cstdlib>
#include <iostream>

#include "annexe.h"

using namespace std;

int main () {
   // utlisation d'une declaration de la ibrairie
   cout << "valeur = " << CONSTANTE << endl;

   // appel d'un des sous-programme de la librairie
   sousPgm("message pour la librairie ...\n");

   // appel au sous-programme "cachee" impossible
   //cachee(3);

   // fin de programme
   printf ("fin de programme");
   return EXIT_SUCCESS;
}
