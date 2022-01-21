//---------------------------------------------------------
// Demo           : 08 - ex 8.4
// Fichier        : 08_specialisation_fonction_ex_8_4.cpp
// Version        : 01 - 2022.01.21
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme de résolution de surcharges
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T, typename U> void f(T,   U,   int)   { cout << 1 << endl; };
template <typename T>             void f(T,   T,   short) { cout << 2 << endl; };
template <typename T>             void f(T,   int, int)   { cout << 3 << endl; };
                                  void f(int, int, int)   { cout << 4 << endl; };

int main() {

   char  c = 'A';
   short s =  1;
   int   i =  2, j = 3;
   float x =  4.f;
      
   f(i, j, c);
   f(i, j, s);
   f(i, j, x);
   
   return EXIT_SUCCESS;
}

// =====================================
// Correction ex 8.4
// =====================================
// p => promotion nécessaire faut de type exacte
// c => conversion nécessaire faut de type exacte

// ------------------------------------------------------------------------------------------------
// 1) Avec les fonctions 1, 2, 3, 4
// ------------------------------------------------------------------------------------------------
// a) <int, int, char>  => {1, 2, 3, 4} {1, 2, 3, 4} {4p}      => 4 (promotion fct ordinaire)
// b) <int, int, short> => {1, 2, 3, 4} {1, 2, 3, 4} {2}       => 2 (type exact)
// c) <int, int, float> => {1, 2, 3, 4} {1, 2, 3, 4} {4c}      => 4 (conversion fct ordinaire)
//
// ------------------------------------------------------------------------------------------------
// 2) Avec les fonctions 2, 3, 4
// ------------------------------------------------------------------------------------------------
// a) <int, int, char>  => {2, 3, 4} {2, 3, 4} {4p}            => 4 (promotion fct ordinaire)
// b) <int, int, short> => {2, 3, 4} {2, 3, 4} {2}             => 2 (type exact)
// c) <int, int, float> => {2, 3, 4} {2, 3, 4} {4c             => 4 (conversion fct ordinaire)
//
// ------------------------------------------------------------------------------------------------
// 3) Avec les fonctions 1, 2, 3 (pas de fonction ordinaire)
// ------------------------------------------------------------------------------------------------
// a) <int, int, char>  => {1, 2, 3} {1, 2, 3} {1p, 2c, 3p}    => 3 (promotion, plus spécialisée)
// b) <int, int, short> => {1, 2, 3} {1, 2, 3} {2}             => 2 (type exact)
// c) <int, int, float> => {1, 2, 3} {1, 2, 3} {1c, 2c, 3c}    => {2, 3} aucun n’est plus spécialisée
//
// ------------------------------------------------------------------------------------------------
// 4) Avec les fonctions 1, 2 (pas de fonction ordinaire)
// ------------------------------------------------------------------------------------------------
// a) <int, int, char>  => {1, 2} {1, 2} {1p, 2c}              => 1 (promotion, plus spécialisée)
// b) <int, int, short> => {1, 2} {1, 2} {2}                   => 2 (type exact)
// c) <int, int, float> => {1, 2} {1, 2} {1c, 2c}              => {1, 2} (2 candidats => ambigu)

// ================================================================================================
// Algorithme de résolution de surcharge (voir slides du chap 8)
// ================================================================================================
// 1) Etablir la liste des fonctions viables (génériques ou pas) en tenant compte des ...
//    a) Nom de la fonction (y.c. visibilité du namespace)
//    b) Nombre de paramètres (exact ou plus grand avec paramètres par défaut)
//    c) Type exact ou conversion possible pour les paramètres non-génériques
//    d) Déduction d’arguments pour les paramètres génériques non spécifiés explicitement
// 2) S’il y a plusieurs candidates, déterminer si une est « meilleure que toutes les autres»
//    a) Au sens de l’algorithme de résolution de surcharge du chapitre 4
//       - individuellement pour chaque paramètre : type exact > promotion > ajustement
//       - puis intersection des choix des paramètres
//    b) Si 2.1 ne détermine pas d’ordre entre 2 fonctions, au sens de l’ordre partiel
//       « plus spécialisé », sachant qu’une fonction non-générique est
//       plus spécialisée qu’une fonction générique
//
// Si l’algorithme sélectionne une unique fonction, elle est appelée.
// S’il sélectionne 0 ou plusieurs fonctions, il y a erreur de compilation.
// ================================================================================================
