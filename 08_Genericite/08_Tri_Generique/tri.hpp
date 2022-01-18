//---------------------------------------------------------
// Demo           : 08_Tri_Generique
// Fichier        : tri.hpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : tri générique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef tri_h
#define tri_h

//---------------------------------------------------------
template <typename T>
void echanger (T&, T&);

//---------------------------------------------------------
template <typename T>
void trier (T& t);

//---------------------------------------------------------
#include "triImpl.hpp"

#endif /* tri_h */
