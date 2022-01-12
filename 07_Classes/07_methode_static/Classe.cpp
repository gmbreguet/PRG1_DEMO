//---------------------------------------------------------
// Demo           : 07_methode_static
// Fichier        : classe.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-07
// But            : démontrer méthodes static
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "Classe.h"

#include <iostream>  // cout et cin
#include <string>

using namespace std;

//---------------------------------------------------------------------
// à mettre dans le .cpp
const int Classe::CONST_STAT  = 100;
      int Classe::total       =   0;
      int Classe::next        =   1;

//---------------------------------------------------------------------
Classe::Classe(int valeur)
   : NO_OBJ(next), valeur(valeur) {
      ++total;
      ++next;
}

//---------------------------------------------------------------------
Classe::~Classe() {
   --total;
}

//---------------------------------------------------------------------
void Classe::afficherStat() {
   cout  << "CONST_STAT : " << Classe::CONST_STAT    << endl
         << "next       : " << next          << endl
         << "total      : " << total         << endl;
//   afficherObj();          // pas possible
//   this->afficherObj();    // le this n'a aucun sens

//   cout << valeur;   // pas possible, relatif à un objet
}

//---------------------------------------------------------------------
void Classe::afficherObj() const {
   cout  << "NO_OBJ     : " << this->NO_OBJ  << endl
         << "valeur     : " << this->valeur  << endl;
// valeur = 3 ; // méthode const => pas possible
   afficherStat();         // 3 manières d'appeler
   Classe::afficherStat(); // .. la méthode static
   this->afficherStat();   // .. afficherStat()
}
