//---------------------------------------------------------
// Demo           : 07_constructor
// Fichier        : vecteur.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : operateurs sur vector
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include "vecteur.hpp"

using namespace std;

//--------------------------------------------------------
ostream& operator <<(ostream& os, const Vecteur& v) {
   return os << "(" << v.x << "," << v.y << ")";   
}

//--------------------------------------------------------
istream& operator >>(istream& is, Vecteur& v) {
   const char
      DEBUT = '(',
      FIN = ')',
      MILIEU = ',';
   bool saisieOK;
   Vecteur tmp;

   saisieOK = is.get() == DEBUT &&
              is >> tmp.x &&
              is.get() == MILIEU &&
              is >> tmp.y &&
              is.get() == FIN &&
              is.peek() == '\n';
   
   is.sync();
   
   if (saisieOK)
      v = tmp;
   else
      is.clear(is.rdstate() | ios::failbit);

   return is;   
}

//--------------------------------------------------------
bool operator ==(const Vecteur& v1, const Vecteur& v2) {
   return v1.x == v2.x && v1.y == v2.y;
}

Vecteur::Vecteur(double x, double y) : x(x), y(y) {}
