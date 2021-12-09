//---------------------------------------------------------
// Fichier        : 06_string-find_first_of.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-09
// But            : démontrer l'utilisation de string::find_first_of
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   const string MOT     = "informatique";
   const string PONCT   = " -_,.;:!'\"";

   string chaine = "L’orientation informatique logicielle est caractérisée par "
                   "une solide base en programmation, en méthodologies de développement, "
                   "en modélisation et traitement de données, en développement d’applications "
                   "et services Internet, en architectures client-serveur des systèmes "
                   "informatiques et en développement d’applications pour systèmes mobiles.";

   // position de tous les mots "et"
   size_t pos = 0;
   cout << endl
        << "positions du mot \"informatique\"     : ";
   while ( (pos=chaine.find(MOT, pos)) != string::npos)
      cout << pos++ << " ";
   cout << endl;

   // position de toutes les ponctuations
   pos = 0;
   cout << endl
        << "toutes les ponctuations             : ";
   while ( (pos=chaine.find_first_of(PONCT, pos)) != string::npos)
      cout << (int)chaine.at(pos++) << " ";
   cout << endl;

   // recherche de plusieurs caractères
   // https://www.cplusplus.com/reference/string/string/find_first_of/
   cout << endl
   << "recherche de plusieurs caractères"       << endl;
   //                      012345678912
   string s      = string("Hello World!");
   string vowels = string("aeiouyAEIOUY"); // voyelles

   cout << "=> string" << endl;
   cout << s.find_first_of(vowels)              << endl; // 1  H<e>llo World!
   cout << s.find_first_of(vowels, 1)           << endl; // 1  H<e>llo World!
   cout << s.find_first_of(vowels, 2)           << endl; // 4  Hell<o> World!
   cout << s.find_first_of(vowels, s.size())    << endl; // string::npos
   cout << s.find_first_of(vowels, 5)           << endl; // 7  Hello W<o>rld!
   //                        |     |_________________ position de recherche dans le string s
   //                        |_______________________ liste de caractères à chercher

   cout << endl;
   cout << "=> char*" << endl;
   cout << s.find_first_of('x')                 << endl; // string::npos
   cout << s.find_first_of("Good Bye!")         << endl; // 1  H<e>llo World!
   cout << s.find_first_of("Good Bye!", 0, 4)   << endl; // 4  Hell<o> World!
   cout << s.find_first_of("Good Bye!", 6, 2)   << endl; // 7  Hello W<o>rld!
   cout << s.find_first_of("Good Bye!", 6, 4)   << endl; // 7  Hello W<o>rld!
   //                           |       |   |________ nbre de chars de la liste à utiliser
   //                           |       |____________ position de recherche dans le string s
   //                           |____________________ liste de caractères à chercher

   return EXIT_SUCCESS;
}


//      positions du mot "informatique"     : 16 281
//
//      toutes les ponctuations             : 32 32 32 32 32 32 32 32 32 32 44 32 32 32 32 44 32 32 32 32 32 32 44 32 32 32 32 32 32 44 32 32 32 45 32 32 32 32 32 32 32 32 32 32 46
//
//      recherche de plusieurs caractères
//      => string
//      1
//      1
//      4
//      18446744073709551615
//      7
//
//      => char*
//      18446744073709551615
//      1
//      4
//      7
//      7
//      Program ended with exit code: 0
