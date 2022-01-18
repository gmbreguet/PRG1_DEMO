//---------------------------------------------------------
// Demo           : 07_protected
// Fichier        : personne.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : implémentation de la classe personne
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "personne.hpp"
#include <iostream>

using namespace std;


//--------------------------------------------------------
Personne::Personne(const string& nom,
                   const Date&   date,
                   const Sexe&   sexe) {
   this->nom       = nom;
   this->naissance = date;
   this->sexe      = sexe;
}

//--------------------------------------------------------
void Personne::afficher() const {
   cout << "nom   = " << nom << endl;
   cout << "annee = " << naissance.annee << endl;
}
