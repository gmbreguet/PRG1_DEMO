//---------------------------------------------------------
// Demo           : 07_constructor_defaut
// Fichier        : main.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-13
// But            : démontrer les bases des constructeurs
//                  par defaut
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------
// une classe dont la propriété est public
// pas recommandé selon le principe de l'encapsulation
class A {
public:
   int valeur;
};

//---------------------------------------------------------
int main() {
   // constructeur par defaut
   A a1;
   cout << "a1 : " << a1.valeur << endl;
   a1.valeur = 12;
   cout << "a1 : " << a1.valeur << endl;

   // constructeur par copie
   A a2 = a1;
   cout << "a2 : " << a2.valeur << endl;

   // constructeur par copie
   A a3(a2);
   cout << "a3 : " << a3.valeur << endl;
   
   // operateur d'affectation
   A a4;
   a4 = a3;
   cout << "a4 : " << a4.valeur << endl;

   return EXIT_SUCCESS;
}

