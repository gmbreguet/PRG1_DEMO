//---------------------------------------------------------
// Demo           : 09_Terminaison
// Fichier        : 09_Terminaison.cpp
// Version        : 02 2022-01-26
// Auteur(s)      : BREGUET Guy-Michel
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
            case 1 : return EXIT_SUCCESS;    break;
            case 2 : return EXIT_FAILURE;    break;
            case 3 : exit(2);                break;
            case 4 : f_EXIT_SUCCESS();       break;
            case 5 : f_exit();               break;
            case 6 : f_quick_exit();         break;
            case 7 : f_Exit();               break;
            case 8 : throw 'a';              break;
         }
      }
      
      catch(int e) {
         cout << "catch(int e) : " << e << endl;
      }
   } // while

   return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------
// Résultats et commentaires ...
//-----------------------------------------------------------------------------
// 1) sortie EXIT_SUCCESS
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 1
//    
//    destructeur (a)
//    destructeur (b)
//    appel de exit no 2
//    appel de exit no 1
//    
//    => les 2 destructeurs sont appelés
//    => les fonctions de atexit sont appelées
//
//-----------------------------------------------------------------------------
// 2) sortie EXIT_FAILURE
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 2
//    
//    destructeur (a)
//    destructeur (b)
//    appel de exit no 2
//    appel de exit no 1
//
//    => les 2 destructeurs sont appelés
//    => les fonctions de atexit sont appelées
//
//-----------------------------------------------------------------------------
// 3) exit(2)
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 3
//    
//    destructeur (b)
//    appel de exit no 2
//    appel de exit no 1
//
//    Semblerait que, en C++, les destructeurs des objets alloués automatiquement
//    ne soient pas appelés comme affirmé sur le slide
//
//    => seul le destructeur de b (static) est appelé
//    => les fonctions de atexit sont appelées
//
//-----------------------------------------------------------------------------
// 4) fonction return EXIT_SUCCESS
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 4
//    
//    votre choix : 
//
//    une simple fonction qui retourne la valeur
//    EXIT_SUCCESS => pas de terminaison
//    => ne quite pas le programme
//
//-----------------------------------------------------------------------------
// 5) comme le return EXIT_SUCCESS mais depuis une fonction
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 5
//    
//    destructeur (b)
//    appel de exit no 2
//    appel de exit no 1
//
//    => ailleurs que dans la fonction main
//    => seul le destructeur de b (static) est appelé
//    => les fonctions de atexit sont appelées
//
//-----------------------------------------------------------------------------
// 6) quick_exit
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 6
//
//    ne semble pas dispo sur mon Mac ?
//    https://stackoverflow.com/questions/36825196/quick-exit-not-available
//
//-----------------------------------------------------------------------------
// 7) sortie immédiate
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 7
//    
//    => aucun destructeur n'est appelé
//    => les fonctions de atexit sont PAS appelées
//
//-----------------------------------------------------------------------------
// 8) une exception n'est pas traitée
//-----------------------------------------------------------------------------
//    constructeur (a)
//    constructeur (b)
//    votre choix : 8
//    
//    appel de terminate
//    libc++abi: terminate_handler unexpectedly returned
//    Abort trap: 6
//
//    => la fonction de setTerminate est appelée
//    NB : une seule fonction est possible
//
//-----------------------------------------------------------------------------
// [[noreturn]]
// The noreturn attribute is supposed to be used for functions that don't return to the caller.
// That doesn't mean void functions (which do return to the caller - they just don't return a value),
// but functions where the control flow will not return to the calling function after the function finishes
//
