//---------------------------------------------------------
// Demo           : 07_amities_fct_independante_amie_de_plusieurs_classes
// Fichier        : c1.hpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : classe c1
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef C1_H
#define C1_H

class C2;

class C1 {
   friend void afficher(const C1& c1, const C2& c2);
public:
   C1(int n = 0);
private:
   int n;
};

#endif
