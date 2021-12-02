// --------------------------------------------------------------
// But      : demontrer les differents cas des exceptions en C++
// Auteur   : GM Breguet
// Date     : 3 avril 2020
// --------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <exception>

// ajout de string et to_string pour simplifier
#define FILE_NAME    string(__FILE__)
#define FCT_NAME     string(__func__)
#define LINE_NO      to_string(__LINE__)
#define LINE_FCT     LINE_NO + ") " + FCT_NAME


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
class depassement : public runtime_error {
public:
   explicit depassement(const string& s) : runtime_error(s) {}
   explicit depassement(const char*   s) : runtime_error(s) {}
};

//-------------------------------------------------
class parametre : public logic_error {
public:
   explicit parametre(const string& s) : logic_error(s) {}
   explicit parametre(const char*   s) : logic_error(s) {}
};

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
   
   if (largeur < 0)
      throw parametre(LINE_FCT + " => largeur < 0\n");
   
   if (longueur < 0)
      throw parametre(LINE_FCT + " => longueur < 0\n");
   
   this->largeur  = largeur;
   this->longueur = longueur;
}

//-------------------------------------------------
int Rectangle::surface() const {
   
   // calcul de s dans un type large
   unsigned long long s = (unsigned long long)largeur;
   s *= (unsigned long long)longueur;
   
   if (s > numeric_limits<int>::max())
      throw depassement(LINE_FCT + " => overflow");
   
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
            case 1 : {
               Rectangle r(0, -1);
            }
            case 2 : {
               Rectangle r(10000000, 10000000);
               cout << "surface : " << r.surface();
            }

            default : return EXIT_SUCCESS;
         }
      }
      
      //----------------------------------
      catch (parametre& e) {
         cout << "EXCEPTION parametre"    << endl;
         cout << e.what()                 << endl;
      }

      //----------------------------------
      catch (depassement& e) {
         cout << "EXCEPTION depassement"  << endl;
         cout << e.what()                 << endl;
      }

   }  // while

   return EXIT_SUCCESS;
}
