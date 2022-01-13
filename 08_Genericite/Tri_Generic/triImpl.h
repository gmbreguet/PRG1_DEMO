//---------------------------------------------------------
// Demo           : 08_Tri_Generique
// Fichier        : triImpl.h
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2022-01-12
// But            : tri générique
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef triImpl_h
#define triImpl_h

//--------------------------------------------------------------
template <typename T>
void echanger (T& gauche, T& droite) {
   T temp = gauche;
   gauche = droite;
   droite = temp;
}

//--------------------------------------------------------------
// NB : depend de "<" du type considéré
template <typename T>
void trier(vector<T>& v) {
   for (auto i = v.begin()+1; i < v.end(); ++i)
      for (auto j = v.begin(); j < i; ++j)
         if (*i < *j)
            echanger(*i, *j);
}

#endif /* triImpl_h */
