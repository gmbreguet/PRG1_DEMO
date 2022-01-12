//---------------------------------------------------------
// Demo           : 07_amities_fct_operateurs_independantes_amies
// Fichier        : main.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : démontrer des fonctions et classes amies
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include "vecteur.h"

using namespace std;

int main() {
   Vecteur v1, v2;
   
   cout << "Entrez le vecteur 1 au format : (x,y) > ";
   if (cin >> v1) {
      cout << "Entrez le vecteur 2 au format : (x,y) > ";
      if (cin >> v2) {
         cout << v1 << endl;
         cout << v2 << endl;
         cout << "v1 == v2 : " << boolalpha << (v1 == v2) << endl;
         system("PAUSE");
         return EXIT_SUCCESS;
      }
   }
   cout << "Saisie incorrecte !\n";
   
   return EXIT_FAILURE;
}
