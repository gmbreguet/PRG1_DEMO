//---------------------------------------------------------
// Fichier        : 04_librairie
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-09-15
// But            : exemple d'utilisation d'une
//                  librairie personnelle
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

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
