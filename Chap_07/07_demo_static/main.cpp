#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // cout et cin

#include "Classe.h"

using namespace std;

int main() {
   
   Classe::afficherStat();    // méthode statique (hors objet)
   cout << endl;
   
   {
      Classe c1(10);
      c1.afficherObj();
      cout << endl;

      Classe c2(20);
      c2.afficherObj();
      cout << endl;
   }
   
   Classe::afficherStat();    // méthode statique (hors objet)
   cout << endl;

   Classe c3(30);
   c3.afficherObj();
   cout << endl;

   c3.afficherStat();         // méthode statique via un objet
//   Classe::afficherObj();   // pas possible
   
   return EXIT_SUCCESS;
}
