//---------------------------------------------------------
// Demo           : 09_Terminaison
// Fichier        : 09_Terminaison.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-13
// But            : démontrer la terminaison de programme
//                  en cas d'exceptions
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdexcept>
using namespace std;

//-------------------------------------------------
class A {
public:
   A(char c) : c(c)  { cout << "constructeur (" << c << ")" << endl; };
  ~A()               { cout << "destructeur ("  << c << ")" << endl; };
private:
   char c;
};

//-------------------------------------------------
int f_EXIT_SUCCESS() {
   return EXIT_SUCCESS;
}

//-------------------------------------------------
[[noreturn]] void f_exit() {
   exit(EXIT_SUCCESS);
}

//-------------------------------------------------
// voir commentaire no 4
[[noreturn]] void f_quick_exit() {
//   quick_exit(EXIT_SUCCESS);
   _Exit(EXIT_SUCCESS);
}

//-------------------------------------------------
[[noreturn]] void f_Exit() {
   _Exit(EXIT_SUCCESS);
}

//-------------------------------------------------
void onExit1() {
   cerr << "appel de exit no 1" << endl;
}

//-------------------------------------------------
void onExit2() {
   cerr << "appel de exit no 2" << endl;
}
      
//-------------------------------------------------
void onTerminate() {
   cerr << "appel de terminate" << endl;
}

//-------------------------------------------------
int main () {

   //--------------------------
   // branchement des handlers
   //--------------------------
   // procedure appelee apres une sortie "exit"
   atexit(onExit1);                 // utilisation de onExit
   atexit(onExit2);                 // utilisation de onExit

   //--------------------------
   // procedure appelee lorsqu'une exception n'est pas traitee
   // une seule fonction peut être appelée
   set_terminate(onTerminate);      // utilisation de onTerminate


   //--------------------------
   int valeur;
          A   a('a');   // pour vérifier constructeur et destructeur
   static A   b('b');   // pour vérifier constructeur et destructeur

   while (true) {

      try {
         // saisie du choix
         cout << "votre choix : ";
         cin  >> valeur;
         cout << endl;

         switch (valeur) {
            // gestion des differents cas
            case 1 : return EXIT_SUCCESS;    break;   // voir commentaire 1
            case 2 : return EXIT_FAILURE;    break;   // voir commentaire 2
            case 3 : exit(2);                break;   // voir commentaire 3
            case 4 : f_EXIT_SUCCESS;         break;   // voir commentaire 4
            case 5 : f_exit();               break;   // voir commentaire 5
            case 6 : f_quick_exit();         break;   // voir commentaire 6
            case 7 : f_Exit();               break;   // voir commentaire 7
            case 8 : throw 'a';              break;   // voir commentaire 8
         }
      }
      
      catch(int e) {
         cout << "catch(int e) : " << e << endl;
      }
   } // while

   return EXIT_SUCCESS;
}

//-------------------------------------------------
// commentaires
//-------------------------------------------------
// 1) sortie normale
//    => les 2 destructeurs sont appelés
//    => les fonctions de atexit sont appelées
//
// 2) sortie normale
//    => les 2 destructeurs sont appelés
//    => les fonctions de atexit sont appelées
//
// 3) Semblerait que, en C++, les destructeurs des objets alloués automatiquement
//    ne soient pas appelés comme affirmé sur le slide
//    => seul le destructeur de b (static) est appelé
//    => les fonctions de atexit sont appelées
//
// 4) le "int" est obligatoire pour la compilation
//    une simple fonction qui retourne la valeur
//    EXIT_SUCCESS => pas de terminaison
//    => ne quite pas le programme
//
// 5) comme le return EXIT_SUCCESS mais depuis une fonction
//    => ailleurs que dans la fonction main
//    => seul le destructeur de b (static) est appelé
//    => les fonctions de atexit sont appelées
//
// 6) quick_exit ne semble pas dispo sur mon Mac ?
//    https://stackoverflow.com/questions/36825196/quick-exit-not-available
//
// 7) sortie immédiate
//    => aucun destructeur n'est appelé
//    => les fonctions de atexit sont PAS appelées
//
// 8) une exception n'est pas traitée
//    => les fonctions de setTerminate sont appelées
// [[noreturn]]
// The noreturn attribute is supposed to be used for functions that don't return to the caller.
// That doesn't mean void functions (which do return to the caller - they just don't return a value),
// but functions where the control flow will not return to the calling function after the function finishes
