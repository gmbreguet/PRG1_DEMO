//---------------------------------------------------------
// Demo           : 09_Try_Catch
// Fichier        : 09_Try_Catch.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-13
// But            : démontrer les try-catch
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

//-------------------------------------------------
// fonction ordinaire levant une exception
// retour à l'appelant avec une exception en cours
void throwInt() {
   throw 1;
}

//-------------------------------------------------
// fonction ordinaire levant et traitant
// une exception en interne => retour au code normal
void f() {
   try {
      throw 1;
   }
   catch(int i) {
      cout << "dans la fonction : " << i  << endl;
   }
   cout << "retour normal ..."      << endl;
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
         
         int& refInt = valeur;
         
         switch (valeur) {
            // gestion des differents cas
            case  0 : throw  valeur;            // valeur entiere
            case  1 : throw  (short)valeur;     // short => catch(...)
            case  2 : throw refInt;             // référence sur un entier
            case  3 : throw &valeur;            // adresse sur un entier
            case  4 : throw 1.2;                // double => catch(...)
            case  5 : throw 'a';                // caractere
            case  6 : throw "chaine";           // chaine de caracteres
            case  7 : throw string("string");   // string
            case  8 : throw true;               // boolean => catch(...)
            case  9 : throwInt();               // throw 1 depuis une fonction
            case 10 : f(); break;               // retour normal => break

            default : return EXIT_SUCCESS;
         }
      }
      
      //----------------------------------
      // traite exception de type int
      // /!\ ne fonctionne qu'avec des "int", unsigned int est different !!!
      //     const n'a pas d'influence car utile pour la copie (parametre)
      catch (int valeur) {
         cout << "constante entiere : " << valeur << endl;
      }
      
      //----------------------------------
      // traite exception avec un ptr sur entier
      // /!\ un ptr sur un float est un type different !!!
      catch (const int* valeur) {
         cout << "ptr sur entier : " << *valeur << endl;
      }
      
      //----------------------------------
      // traite exception avec des caracteres
      // /!\ pas de conversion implicite avec des entiers
      catch (char car) {
         cout << "caractere : " << car << endl;
         try{
            throw 1.2;
         }
         catch(double v) {
            cout << "dans le catch car : " << v << endl;
         }
      }
      
      //----------------------------------
      // traite exception avec des chaines de caracteres
      // /!\ le "const" est IMPORTANT !!!!
      //     different d'un string
      catch (const char* chaine) {
         cout << "chaine1 : " << chaine << endl;
         //-----------------------------------------------
         // lever une exception dans un traite-exception
         try {
            try {
               throw;      // lever cette meme exception
            }
            catch(int val) {
               // ne rien faire
            }
         }

         //-----------------------------------------------
         catch (const char* chaine) {
            cout << "chaine2 : " << chaine << endl;
         }
      }

      //----------------------------------
      // traite exception avec des string
      catch (const string& chaine) {
         cout << "string : " << chaine << endl;
      }

      // traite TOUTES les exceptions (restantes)
      // /!\ doit etre obligatoirement en DERNIERE position (heureusement!)
      // /!\ impossible de recuperer l'objet ici :(
      catch (...) {
         cout << "je prends tout ..." << endl;
      }
   }

   return EXIT_SUCCESS;
}
