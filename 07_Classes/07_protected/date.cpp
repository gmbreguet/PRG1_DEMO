//---------------------------------------------------------
// Demo           : 07_protected
// Fichier        : date.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : implémentation de la classe date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "date.hpp"

#include <iostream>
using namespace std;


//--------------------------------------------------------
Date::Date (const int jour,
            const int mois,
            const int annee) {
   this->jour  = jour;
   this->mois  = mois;
   this->annee = annee;
}

//--------------------------------------------------------
Date::Date (const Date& date) {
   this->jour  = date.jour;
   this->mois  = date.mois;
   this->annee = date.annee;
}

//--------------------------------------------------------
Date& Date::operator= (const Date& date) {
   this->jour  = date.jour;
   this->mois  = date.mois;
   this->annee = date.annee;
   return *this;
}

//--------------------------------------------------------
void Date::afficher() const {
   cout << jour << "/" << mois << "/" << annee;
}

