//---------------------------------------------------------
// Demo           : 07_protected
// Fichier        : main.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-13
// But            : démontrer l'utilisation d'une
//                  propriété protected
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

#include "personne.h"
#include "date.h"

using namespace std;

//--------------------------------------------------------
class A {
   public:
      A() :aPublic(1), aPrivate(2), aProtected(3) {}

      double aPublic;

      double getaPublic    () const {return aPublic;};
      double getaPrivate   () const {return aPrivate;}
      double getaProtected () const {return aProtected;}

   private:
      double aPrivate;

   protected:
      double aProtected;
};

//--------------------------------------------------------
class B: public A {
   public:
   B(){
      aPublic    = 0;
      aProtected = 0;
      // aPrivate   = 0;
   }
   
   private:
      string bb;
};

//--------------------------------------------------------
int main() {
   
   A a;
   cout << "aPublic    : " << a.getaPublic()    << endl
        << "aPrivate   : " << a.getaPrivate()   << endl
        << "aProtected : " << a.getaProtected() << endl;
   
   cout << endl;
   Date     date   (11, 2, 2013);
   Personne charly ("Chappelin", date, Sexe::HOMME);
   
   date.afficher();
   cout << endl;
   charly.afficher();

   getchar();
   return EXIT_SUCCESS;
}
