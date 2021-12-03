//---------------------------------------------------------
// Fichier        : 07_amities_classe_amie.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : démontrer l'utilisation de classes amies
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

#include "personne.h"
#include "date.h"

using namespace std;

class Test {
public:
   Test () {i=0;};
   Test& operator++ ();
   Test  operator++ (int);
   int getI() {return i;}
private:
   int i;
};

Test& Test::operator++ () {
   ++i;
   return *this;
}

Test  Test::operator++ (int) {
   Test tmp = *this;
   ++(*this); // utilisation du ++Test
   return tmp;
}

//--------------------------------------------------------
int main() {
   
   Test t;  cout << t.getI() << endl;
   ++t;     cout << t.getI() << endl;
   t++;     cout << t.getI() << endl;

   
   cout << endl;
   Date     date   (11, 2, 2013);
   Personne charly ("Chappelin", date, Sexe::HOMME);
   
   date.afficher();
   cout << endl;
   charly.afficher();

   getchar();
   return EXIT_SUCCESS;
}
