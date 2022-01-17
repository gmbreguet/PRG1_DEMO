//---------------------------------------------------------
// Demo           : Pile_G
// Fichier        : Pile_G_Impl.h
// Version        : 01 - 2022.01.18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer la compiltion séparée et donner
//                  un exemple des methodes Pile::at()
//                  est des operators Pile::operator[]
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef pile_g_impl_h
#define pile_g_impl_h

#include <cassert>

//---------------------------------------------------
template <typename T>
Pile<T>::Pile(size_t capacite)
: capacite(capacite) {
   taille = 0;
   tab.reserve(capacite);
}

//---------------------------------------------------
template <typename T>
bool Pile<T>::empiler(const T& valeur) {
   if (taile >= capacite)
      return false;
   tab[taille++] = valeur;
   return true;
}

//---------------------------------------------------
template <typename T>
bool Pile<T>::depiler() {
   if (taille == 0)
      return false;
   --taille;
   return true;
}

//---------------------------------------------------
template <typename T>
T Pile<T>::dernier() {
   assert(taille);
   return tab[taille-1];
}

//---------------------------------------------------
template <typename T>
bool Pile<T>::estVide() const {
   return taille==0;
}

//---------------------------------------------------
template <typename T>
bool Pile<T>::estPleine() const  {
   return taille == capacite;
}

//---------------------------------------------------
template <typename T>
T& Pile<T>::at(size_t pos) {
   assert(pos<taille);
   return (*this)[pos];
}

//---------------------------------------------------
template <typename T>
const T& Pile<T>::at(size_t pos) const {
   assert(pos<taille);
   return (*this)[pos];
}

//---------------------------------------------------
template <typename T>
T& Pile<T>::operator[](size_t pos) {
   return tab[pos];
}

//---------------------------------------------------
template <typename T>
const T& Pile<T>::operator[](size_t pos) const {
   return tab[pos];
}

#endif /* pile_g_impl_h */
