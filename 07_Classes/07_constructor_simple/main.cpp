//---------------------------------------------------------
// Demo           : 07_constructor_simple
// Fichier        : main.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-17
// But            : démontrer les bases des constructeurs
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

//------------------------------------------------------
class A {
public:                    // si un constructeur est présent,
                           // aucun constructeur n'est créé par le compilateur
// A() = default;          // default pour quand meme le créer
   A(int cste);
   explicit A(int cste, char c, int i);

   void afficher() const;

private:
   const int CSTE;         // constant mais différent pour chaque objet
   char c   = 'b';         // valeurs par défaut utilisées uniquement si ...
   int  i   =  10;         // pas de paramètre avec valeur par défaut
};

//------------------------------------------------------
A::A(int cste) : CSTE(cste) {
// const int CSTE = 12;    // ne compile pas
   this->c = 'a';
   this->i =  0;
}

A::A(int cste, char c, int i) : CSTE(cste) {
// const int CSTE = 12;    // ne compile pas
   this->c = c;
   this->i = i * (isupper(c) ? 10 : 1);   // majuscule i*10
}

//------------------------------------------------------
void A::afficher() const {
   cout << CSTE   << ", "
        << c      << ", "
        << i      << endl;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   cout << "constructeurs simples ..." << endl;
//   A a1;              a1.afficher();
   A a2(12, 'b', 2);    a2.afficher();
   A a3(23, 'B', 2);    a3.afficher();

   A a4(34);            a4.afficher();

   cout << endl;
   cout << "explicit ..." << endl;
   A a5 = a4;           a5.afficher();    // ok
   A a6 = (12, 'b', 2); a6.afficher();    // /!\ liste de valeurs => a6 = 2, a, 0
// A a7 = {12, 'b', 2}; a7.afficher();    // pas possible à cause d'explicit

   return EXIT_SUCCESS;
}

//      constructeurs simples ...
//      12, b, 2
//      23, B, 20
//      34, a, 0
//
//      explicit ...
//      34, a, 0
//      2, a, 0
