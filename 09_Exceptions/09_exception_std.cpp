//---------------------------------------------------------
// Demo           : 09_exception_std
// Fichier        : 09_exception_std.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-13
// But            : démontrer l'utilisation l'utilisation standards
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

//-------------------------------------------------
// rappel
//-------------------------------------------------
//    exception
//    L  bad_alloc
//    L  logic_error
//       L  invallid_argument
//       L  length_error
//       L  out_of_range
//       L  ...
//    L  runtime_error
//       L  overflow_error
//       L  range_error
//       L  ...
//    L  ...

//-------------------------------------------------
class Rectangle {
public:
   Rectangle(int largeur  = 0,
             int longueur = 0);
   int surface() const;
private:
   int largeur;
   int longueur;
};

//-------------------------------------------------
Rectangle::Rectangle(int largeur, int longueur) {
   
   if (largeur < 0 or longueur < 0)
      throw invalid_argument("Rectangle::Rectangle - invalid parameter");
   
   this->largeur  = largeur;
   this->longueur = longueur;
}

//-------------------------------------------------
int Rectangle::surface() const {
   
   // calcul de s dans un type large
   unsigned long long s = (unsigned long long)largeur;
   s *= (unsigned long long)longueur;
   
   if (s > numeric_limits<int>::max())
      throw overflow_error("Rectangle::surface - overflow");
   
   return (int)s;
}

//-------------------------------------------------
int main () {

   int valeur;
   
   while (true) {

      try {
         // saisie du choix
         cout << "votre choix : ";
         cin  >> valeur;
                  
         switch (valeur) {
            // gestion des differents cas
             case 0 : throw int(0);
               
             case 1 : throw bad_alloc();
               
            case 2 : {
               Rectangle r(0, -1);
            }
            case 3 : {
               Rectangle r(10000000, 10000000);
               cout << "surface : " << r.surface();
            }

            default : return EXIT_SUCCESS;
         }
      }
      
//      //----------------------------------
//      // essayer
//      //----------------------------------
//      // 1  sans ce catch (laissé en commentaire
//      // 2  avec ce catch (à décommenter
//      // 2a sans & => catch (exception   e) {...}
//      // 2b avec & => catch (exception&  e) {...}
//      // 3  en mettant ce catch après tous les autres
//      //----------------------------------
//      catch (exception  e) {
//         cout  << "catch - exception   "
//               << "=> " << e.what()     << endl;
//      }

      //----------------------------------
      catch (bad_alloc& e) {
         cout << "catch - bad_alloc"   << endl;
         cout << "=> " << e.what()     << endl;
      }

      //----------------------------------
      catch (logic_error& e) {
         cout << "catch - logic_error"   << endl;
         cout << "=> " << e.what()     << endl;
      }

      //----------------------------------
      catch (runtime_error& e) {
         cout << "catch - runtime_error"   << endl;
         cout << "=> " << e.what()     << endl;
      }

   }  // while

   return EXIT_SUCCESS;
}
