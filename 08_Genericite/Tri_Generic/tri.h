//---------------------------------------------------------
// Demo           : 08_Tri_Generique
// Fichier        : tri.h
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2022-01-12
// But            : tri générique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef tri_h
#define tri_h

#include <iostream>
#include <vector>

//---------------------------------------------------------
template <typename T>
void echanger (T&, T&);

//---------------------------------------------------------
template <typename T>
void trier    (T& t);

//---------------------------------------------------------
#include "triImpl.h"

#endif /* tri_h */
