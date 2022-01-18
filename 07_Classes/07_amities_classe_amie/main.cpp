//---------------------------------------------------------
// Demo           : 07_amities_classe_amie
// Fichier        : main.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'utilisation de classes amies
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

#include "personne.hpp"
#include "date.hpp"

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
