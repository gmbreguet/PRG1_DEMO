// ------------------------------------------------------------------------------
// Fichier     : 05_tris.cpp
// Auteur(s)   : BREGUET Guy-Michel
// Date        : 2021-12-01
// But         : démontrer les tris de bases
//                - tri à bulles
//                - tri par insertions
//                - tri par sélection
// Remarque(s) : NILL
// ------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm> // swap et
#include <iomanip>   // setw
#include <ctime>     // alea::srand(time..)
#include <limits>    // alea::numeric_limits<int>

using namespace std;

//---------------------------------------------------------
using vecteur = vector<int>;
using uintll  = unsigned long long;
//---------------------------------------------------------

ostream& operator<<(ostream& os, const vecteur& v);
int generateur();

uintll bubbleSort1(vecteur& v);
uintll bubbleSort2(vecteur& v);
uintll insertSort(vecteur& v);
uintll selectionSort(vecteur& v);

// vecteur reçu en copie volontairment
// ptr de fonction => action à faire sur le tableau
void test(vecteur v,                      // vecteur par copie
          uintll  (*fct)(vecteur&),       // tri à faire sur la tableau
          bool    coutVecteur = true);    // afficher vecteur? => false/true

//---------------------------------------------------------
int main() {

   // vecteurs de travail
   const bool    coutVecteur     = false;

   // vecteurs de travail
   const vecteur RANDOM          = {9, 5, 2, 6, 7, 3, 4, 1, 8};
   const vecteur CROISSANT       = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   const vecteur DECROISSANT     = {9, 8, 7, 6, 5, 4, 3, 2, 1};
   const vecteur PART_CROISSANT  = {9, 8, 7, 6, 1, 2, 3, 4, 5};

   // test des tri
   cout << endl << "tri à bulles " << endl;
   test(RANDOM,         bubbleSort1,   coutVecteur);
   test(CROISSANT,      bubbleSort1,   coutVecteur);
   test(DECROISSANT,    bubbleSort1,   coutVecteur);
   test(PART_CROISSANT, bubbleSort1,   coutVecteur);

   cout << endl << "tri à bulles optimisé " << endl;
   test(RANDOM,         bubbleSort2,   coutVecteur);
   test(CROISSANT,      bubbleSort2,   coutVecteur);
   test(DECROISSANT,    bubbleSort2,   coutVecteur);
   test(PART_CROISSANT, bubbleSort2,   coutVecteur);

   cout << endl << "tri par insertion " << endl;
   test(RANDOM,         insertSort,    coutVecteur);
   test(CROISSANT,      insertSort,    coutVecteur);
   test(DECROISSANT,    insertSort,    coutVecteur);
   test(PART_CROISSANT, insertSort,    coutVecteur);

   cout << endl << "tri par selection " << endl;
   test(RANDOM,         selectionSort, coutVecteur);
   test(CROISSANT,      selectionSort, coutVecteur);
   test(DECROISSANT,    selectionSort, coutVecteur);
   test(PART_CROISSANT, selectionSort, coutVecteur);

   cout << endl << "grand tableau " << endl;
   vecteur TRES_GRAND(10'000);
   generate(TRES_GRAND.begin(), TRES_GRAND.end(), generateur);

   test(TRES_GRAND,     bubbleSort1,   coutVecteur);
   test(TRES_GRAND,     bubbleSort2,   coutVecteur);
   test(TRES_GRAND,     insertSort,    coutVecteur);
   test(TRES_GRAND,     selectionSort, coutVecteur);

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
uintll bubbleSort1(vecteur& v){
   unsigned long cpt = 0;
   if (v.size() > 0){
      for (size_t i = 0; i < v.size() - 1; ++i){
         for (size_t j = 1; j < v.size() - i; ++j){
            if (v[j - 1] > v[j]) {
               ++cpt;   // nbre de swaps
               swap(v[j - 1], v[j]); // permutation
            }
         } // for j
      } // for i
   } // if
   return cpt;
}

//---------------------------------------------------------
uintll bubbleSort2(vecteur& v){
   unsigned long cpt = 0;
   if (v.size() > 0) {
      bool fini = false;
      size_t taille = v.size();
      while (!fini){
         fini = true;
         for (size_t i = 0; i < taille - 1; ++i){
            if (v[i] > v[i + 1]){
               swap(v[i], v[i + 1]);
               ++cpt;   // nbre de swaps
               fini = false;
            } // if
         } // for
         --taille;
      } // while
   } // if
   return cpt;
}

//---------------------------------------------------------
uintll insertSort(vecteur& v){
   unsigned long cpt = 0;
   int tmp;
   size_t j;
   for (size_t i = 1; i < v.size(); ++i) {
      tmp = v[i];
      j   = i;
      while (j >= 1 and v[j - 1] > tmp) {
         v[j] = v[j - 1];
         --j;
      } // while
      ++cpt;   // nbre d'insertion
      v[j] = tmp;
   } // for
   return cpt;
}

//---------------------------------------------------------
uintll selectionSort(vector<int>& v) {
   unsigned long cpt = 0;
   if (v.size() > 0) {
      size_t iMin;
      for (size_t i = 0; i < v.size() - 1; ++i) {
         iMin = i;
         for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[iMin])
               iMin = j;
         } // for

         ++cpt;   // nbre de swaps
         swap(v[i], v[iMin]); // permutation
      } // for
   } // if
   return cpt;
}

//---------------------------------------------------------
void test(vecteur v,
          uintll  (*fct)(vecteur&),
          bool    coutVecteur) {

   const int     W               = 4;  // setw(W) affectations

   if (coutVecteur) {
      cout << endl;
      cout << "avant : " << v << endl;
   }

   unsigned long cpt = fct(v);

   if (coutVecteur) {
      cout << "apres : " << v << endl;
   }

   cout << setw(W) << cpt << " affectations" << endl;
}

//---------------------------------------------------------
ostream& operator<<(ostream& os, const vecteur& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }

   os << "]";
   return os;
}

//---------------------------------------------------------
int generateur() {
   // initialisation du générateur
   static bool first = true;
   if (first) {
      srand((unsigned)time(NULL));
      first = false;
   }

   // generation d'une valeur aléatoire
   return rand() % numeric_limits<int>::max();
}
