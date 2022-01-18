//---------------------------------------------------------
// Demo           : 08_Tri_Generique
// Fichier        : Couleur.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : Classe Couleur
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "Couleur.hpp"

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
   return couleur < c.couleur;
}

//---------------------------------------------------------
Couleur::operator string() const {
   return COULEUR[ (size_t)couleur ];
}

