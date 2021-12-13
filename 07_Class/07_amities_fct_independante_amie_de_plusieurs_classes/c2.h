//---------------------------------------------------------
// Demo           : 07_amities_fct_independante_amie_de_plusieurs_classes
// Fichier        : c2.h
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : classe c2
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef C2_H
#define C2_H

class C1;

class C2 {
   friend void afficher(const C1& c1, const C2& c2);
public:
   C2(double x = 0.0);
private:
   double x;
};

#endif

