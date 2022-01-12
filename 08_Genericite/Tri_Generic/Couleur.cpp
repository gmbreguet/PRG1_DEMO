//---------------------------------------------------------
// Demo           : 08_Tri_Generique
// Fichier        : Couleur.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2022-01-12
// But            : Classe Couleur
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "Couleur.h"
using namespace std;

//---------------------------------------------------------
const string Couleur::COULEUR[] = {"black",  "white", "red",   "green",    "blue", "cyan", "magenta",
                                   "yellow", "lime",  "brown", "darkgray", "gray", "lightgray",
                                   "olive",  "orange", "pink", "purple",   "teal", "violet"};

//---------------------------------------------------------
ostream& operator << (ostream& os, const Couleur& c) {
   os << string(c);
   return os;
}

//---------------------------------------------------------
bool Couleur::operator < (const Couleur& c) const {
   return this->couleur < c.couleur;
}

//---------------------------------------------------------
Couleur::operator string() const {
   return COULEUR[ (size_t)couleur ];
}

