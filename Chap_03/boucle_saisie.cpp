
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


int main () {

   // ------------------------------------------
   // saisie une valeur entre MIN et MAX
   // ------------------------------------------
   const string MSG_ERREUR = "/!\\ erreur de saisie ..."s;
   const int    MIN        = -5,
                MAX        =  8;
   int          saisie;    // ne peuvent pas être déclarés
   bool         erreur;    // ... dans la boucle

   do {
      // message et saisie
      cout << "saisie [" << MIN << " - " << MAX << "] : ";
      cin >> saisie;

      // saisie et vérification en même temps
      // erreur = not(cin >> saisie) or saisie < MIN or saisie > MAX;

      // vérification
      erreur = cin.fail() or saisie < MIN or saisie > MAX;
      if (erreur) {
         cout << MSG_ERREUR << endl;
         cin.clear();
      }

      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(erreur);

   
   cout << "votre saisie : " << saisie << endl;

   // ---------------------------------------------
   // fin de programme
   // ---------------------------------------------
   cout << endl << endl;
   cout << "presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}
