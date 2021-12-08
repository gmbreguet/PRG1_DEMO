//---------------------------------------------------------
// Fichier        : 07_amities_classe_amie.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : démontrer l'utilisation de classes amies
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

#include "personne.h"
#include "date.h"

using namespace std;

//--------------------------------------------------------
int main() {
   
   Date     date   (11, 2, 2013);
   Personne charly ("Chappelin", date, Personne::Sexe::HOMME);
   
   date.afficher();
   cout << endl;
   charly.afficher();

   return EXIT_SUCCESS;
}
