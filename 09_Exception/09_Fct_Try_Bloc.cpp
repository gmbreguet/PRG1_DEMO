// --------------------------------------------------------------
// But      : demontrer les differents cas des exceptions en C++
// Auteur   : GM Breguet
// Date     : 28 avril 2020
// --------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

#define VALEUR_DEF -1

//-------------------------------------------------
// pour démontrer la réception d'une exception
// appelée dans les constructeurs de la classe C
int oops(int n) {
   if (n<0)
      throw invalid_argument("oops !!");
   return n;
}

//-------------------------------------------------
class C {
public:
   C();           // avec try-bloc pour une exception locale
   C(int n);      // sans try-bloc pour une exception dans la liste d'initialisation
   C(double n);   // avec try-bloc pour une exception dans la liste d'initialisation
private:
   const int n;
};

//-------------------------------------------------
// constructeur avec try-bloc
// pour une exception levée localement
C::C()
try : n(VALEUR_DEF) {
   if(n<=0) {
      throw invalid_argument("C::C n is negative !!");
   }
}
catch (logic_error& e) {
   cout << "exception dans C::C()" << endl;
   cout << e.what() << endl;
   throw;   // le throw est implicite
}

//-------------------------------------------------
// constructeur SANS try-bloc
// avec une exception reçue dans la liste d'initialisation
C::C(int n)
: n( oops(n) ) {
   try {
      cout << "l'objet est pret";
   }
   catch(logic_error& e) {
      cout << "exception dans C::C(int n)" << endl;
      cout << e.what() << endl;
      throw;   // le throw n'est pas implicite
   }
}
      
//-------------------------------------------------
// constructeur AVEC try-bloc
// avec une exception reçue dans la liste d'initialisation
C::C(double n)
try : n( oops( (int)n ) ) {
   cout << "l'objet est pret";
}
catch(logic_error& e) {
   cout << "exception dans C::C(double n)" << endl;
   cout << e.what() << endl;
   throw;   // le throw est implicite
}

//-------------------------------------------------
int main () {
      
   int valeur;
   
   //-------------------------------------------------
   while (true) {
      try {
         // saisie du choix
         cout << "votre choix : ";
         cin  >> valeur;
      
         switch (valeur) {
            // => avec try-bloc pour une exception levée localement
            case  1 : { C c;       }; break;

            // sans try-block avec une exception reçue dans la liste d'initialisation
            case  2 : { C c(-1);   }; break;

            // avec try-block avec une exception reçue dans la liste d'initialisation
            case  3 : { C c(-1.0); }; break;

            default : return EXIT_SUCCESS;
         } // switch
      } // try
      
      catch (logic_error& e) {
         cout << "exception dans main" << endl;
         cout << e.what() << endl;
      }
      
   } // while

   return EXIT_SUCCESS;
}
