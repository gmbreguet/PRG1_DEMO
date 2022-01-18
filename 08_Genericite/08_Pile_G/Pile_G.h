//---------------------------------------------------------
// Demo           : Pile_G
// Fichier        : Pile_G.h
// Version        : 01 - 2022.01.18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer la compiltion séparée et donner
//                  un exemple des methodes Pile::at()
//                  est des operators Pile::operator[]
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef pile_g_h
#define pile_g_h

#include <vector>

//---------------------------------------------------
template <typename T>
class Pile {
public:
   Pile(size_t capacite);
   bool empiler(const T& valeur);               // => false si pleine
   bool depiler();                              // => false si vide
   T    dernier() const;                        // => abort si vide

   bool estVide()   const;
   bool estPleine() const;

          T& at(size_t pos);                    // => abort si pos>=taille
    const T& at(size_t pos) const;              // => abort si pos>=taille

          T& operator[](size_t pos);            // => abort si pos>=taille
    const T& operator[](size_t pos) const;      // => abort si pos>=taille

private:
   const size_t capacite; 
         size_t taille;
   std::vector<T> tab;
};

#include "Pile_G_impl.h"

#endif /* pile_g_h */
