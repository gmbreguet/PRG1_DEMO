//---------------------------------------------------------
// Fichier        : 06_chaineC.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-07
// But            : démontrer les éléments de base des chaines C
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//-------------------------------------------------------------------
int main() {

   //----------------------------------------------------------------
   cout << endl << "constantes litérales" << endl;
   const char* ptr1 = "Hello";   // const nécessaire
   const char* ptr2 = "Hello";
   const char* ptr3 = "Bonjour";

   cout << " ptr1          : "   <<        ptr1    << endl; // Hello
   cout << " ptr2          : "   <<        ptr2    << endl; // Hello
   cout << "*ptr1          : "   <<       *ptr1    << endl; // H
   cout << "*ptr2          : "   <<       *ptr2    << endl; // H
   cout << "(void*)ptr1    : "   << (void*)ptr1    << endl; // la meme ...
   cout << "(void*)ptr2    : "   << (void*)ptr2    << endl; // ... adresse

//   ptr1[0] = 'h';     // contantes litérales => pas possible

   ptr3 = ptr1;         // affectation possible mais seul le pointeur est mis à jour.
                        // /!\ la chaine "Bonjour" east perdue !!

   cout << " ptr3          : "   <<        ptr3    << endl; // Hello

   //----------------------------------------------------------------
   cout << endl << "tableau de caractères" << endl;
   char chaine1[] = "Hello";
   char chaine2[] = "Hello";

   cout << " chaine1       : "   <<        chaine1 << endl; // adresses des ...
   cout << " chaine2       : "   <<        chaine2 << endl; // ... tableaux
   cout << "*chaine1       : "   <<       *chaine1 << endl; // H
   cout << "*chaine2       : "   <<       *chaine2 << endl; // H
   cout << "(void*)chaine1 : "   << (void*)chaine1 << endl; // adresses ...
   cout << "(void*)chaine2 : "   << (void*)chaine2 << endl; // ... différentes

   chaine1[0] = 'h';    // tableau de caractères => ok
//   chaine1 = chaine2;   // pas d'affectation globale entre tableaux

   //----------------------------------------------------------------
   cout << endl << "Caractères spéciaux" << endl;
   // une chaine peut contenir des caractères spéciaux
   char chaine3[] = "Bon\tjour\0tout le monde";
   cout << " chaine3       : "   <<        chaine3 << endl; // Bon(tab)jour

   return EXIT_SUCCESS;
}
