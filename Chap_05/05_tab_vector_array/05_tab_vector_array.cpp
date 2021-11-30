/*
 --------------------------------------------------------------------
 Laboratoire : demo en classe
 Fichier     : main.cpp
 Auteur(s)   : BREGUET Guy-Michel
 Date        : 2012-12-04 - version initiale
 Date        : 2020-11-30 - mise à jour

 But         : démontrer l'utilisation des différents tableaux C++11
               - tableau C (sans réservations dynamiques)
               - array     à 1 ou 2 dimensions
               - vector    à 1 ou 2 dimensions

 Remarque(s) : NILL

 Compilateur : MinGW-g++ 4.6.2
 --------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <string>       // classe string
#include <array>        // classe array
#include <vector>       // classe vector
#include <algorithm>    // classe algorithm
#include <climits>      // pour INT_MAX

using namespace std;

//-------------------------------------------------------------------
// NB les tableaux sont passés en paramétre "const ... &" afin de ne
//    pas les recopier pour le traitement => gain en temps et  mémoire
//    mais également si le tableau reçu est lui-même une constante
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//    TABLEAU C
//-------------------------------------------------------------------
// l'opérateur de flux << ne peut pas être utilisé en raison des paramètres nécessaires
void putTabC (const int    tab[],
              const size_t TAILLE);

void init(      int    tableau[],
          const size_t TAILLE,
          const int    VALEUR = 0);

//-------------------------------------------------------------------
//    ARRAY à 1 ou 2 dimensions
//-------------------------------------------------------------------
using VecteurArray = array<int, 3>;
using MatriceArray = array<VecteurArray, 3>;

ostream& operator << (ostream& os, const VecteurArray& v);
ostream& operator << (ostream& os, const MatriceArray& m);

void init(VecteurArray& v, const int VALEUR = 0);
void init(MatriceArray& m, const int VALEUR = 0);

//-------------------------------------------------------------------
//    VECTOR à 1 ou 2 dimensions
//-------------------------------------------------------------------
using VecteurVector = vector<int>;
using MatriceVector = vector<VecteurVector>;

ostream& operator << (ostream& os, const VecteurVector& v);
ostream& operator << (ostream& os, const MatriceVector& m);

void init(VecteurVector&  v,
          size_t          TAILLE,
          const int       VALEUR = 0);
void init(MatriceVector&  m,
          size_t          COLONNES,
          size_t          LIGNES,
          const int       VALEUR = 0);

//-------------------------------------------------------------------
int main()
{
   cout << "---------------------" << endl;
   cout << "      TABLEAU C      " << endl;
   cout << "---------------------" << endl;
   int tab[10] = {1, 2, 3, 4, 5, 6, 7}; // agrégat incomplet => reste à 0
   const size_t TAILLE = sizeof(tab) / sizeof(tab[0]);

   putTabC(tab, TAILLE); cout << endl;

   init(tab, TAILLE, 9);
   putTabC(tab, TAILLE); cout << endl;
   cout << endl;

   cout << "---------------------" << endl;
   cout << "      ARRAY          " << endl;
   cout << "---------------------" << endl;
   VecteurArray va1d;
   cout << va1d << endl;

   init(va1d, 12);
   cout << va1d << endl;
   cout << endl;

   MatriceArray ma2d;
   cout << ma2d << endl;

   init(ma2d, 12);
   cout << ma2d << endl;
   cout << endl;

   //https://en.cppreference.com/w/cpp/language/aggregate_initialization
   MatriceArray mat3x3;
   mat3x3 = {1, 2, 3};           // [(1, 2, 3), (0, 0, 0), (0, 0, 0)]
   cout << mat3x3 << endl;
   mat3x3 = {{1, 2, 3}};         // [(1, 2, 3), (0, 0, 0), (0, 0, 0)]
   cout << mat3x3 << endl;
   mat3x3 = {{{1}, {2}, {3}}};   // [(1, 0, 0), (2, 0, 0), (3, 0, 0)]
   cout << mat3x3 << endl;

   cout << "---------------------" << endl;
   cout << "      VECTOR         " << endl;
   cout << "---------------------" << endl;
   VecteurVector vv1d;
   cout << vv1d << endl;

   init(vv1d, 12);
   cout << vv1d << endl;
   cout << endl;

   MatriceVector mv2d;
   cout << mv2d << endl;

   init(mv2d, 2, 3, 12);
   cout << mv2d << endl;
   cout << endl;

   // fin du programme
   return EXIT_SUCCESS;
}


//-------------------------------------------------------------------
//    TABLEAU C
//-------------------------------------------------------------------
void putTabC (const int   tab[],
              const size_t TAILLE) {
   cout << "(";
   for (size_t i=0; i< TAILLE; ++i) {
      if (i)
         cout << ", ";
      cout << tab[i] << " ";
   }
   cout << ")";
}

//-------------------------------------------------------------------
void init (      int    tab[],
           const size_t TAILLE,
           const int    VALEUR) {
   for (size_t i=0; i<TAILLE; ++i)
      tab[i] = VALEUR;

   //------------------------------------------
   // cette boucle ne peut fonctionner car tab est ici
   // un pointeur (une adresse) et non un tableau
   //
   //for (int element : &tableau)
   //   element = valeur;
}

//-------------------------------------------------------------------
// /!\ erreur classique
//-------------------------------------------------------------------
// initialisation d'un tableau C
// le tableau est bien créé et initialisé correctement
// MAIS l'adresse est retournée alors que le tableau est rendu à la mémoire
// le pointeur reçu par l'appelant n'est pas utilisable (ptr fantome)
/*
int* init (const int TAILLE,
           const int valeur = 0) {
   // création d'un tableau local
   int tableau [TAILLE];

   // initialisation du tableau local
   for (int indice=0; indice<TAILLE; indice++)
      tableau[indice] = valeur;

   // retourne l'adresse du tableau local ;( !!
   return tableau;
}
*/

//-------------------------------------------------------------------
//    ARRAY à 1 ou 2 dimensions
//-------------------------------------------------------------------
ostream& operator << (ostream& os, const VecteurArray& v) {
   cout << "(";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   cout << ")";
   return os;
}

//-------------------------------------------------------------------
ostream& operator << (ostream& os, const MatriceArray& m) {
   cout << "[";
   for (size_t i=0; i<m.size(); ++i) {
      if (i)
         os << ", ";
      os << m[i];
   }
   cout << "]";
   return os;
}

//-------------------------------------------------------------------
void init(VecteurArray& v, const int VALEUR) {
   v.fill(VALEUR);
}

//-------------------------------------------------------------------
void init(MatriceArray& m, const int VALEUR) {
   for (VecteurArray& v : m)
      init(v, VALEUR);
}

//-------------------------------------------------------------------
//    VECTOR à 1 ou 2 dimensions
//-------------------------------------------------------------------
ostream& operator << (ostream& os, const VecteurVector& v) {
   cout << "(";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   cout << ")";
   return os;
}

//-------------------------------------------------------------------
ostream& operator << (ostream& os, const MatriceVector& m) {
   cout << "[";
   for (size_t i=0; i<m.size(); ++i) {
      if (i)
         os << ", ";
      os << m[i];
   }
   cout << "]";
   return os;
}

//-------------------------------------------------------------------
void init(VecteurVector& v, size_t TAILLE, const int VALEUR) {
   v.resize(TAILLE);             // nbre d'éléments (colonnes)
   v.assign(v.size(), VALEUR);
}

//-------------------------------------------------------------------
void init(MatriceVector& m, size_t COLONNES, size_t LIGNES, const int VALEUR) {
   m.resize(LIGNES);             // nbre de vecteurs (lignes)
   for (VecteurVector& v : m)    // le & est important !!!
      init(v, COLONNES, VALEUR);
}
