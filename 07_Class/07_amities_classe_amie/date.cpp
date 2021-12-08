//---------------------------------------------------------
// Fichier        : date.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : implémentation de la classe date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "date.h"

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

