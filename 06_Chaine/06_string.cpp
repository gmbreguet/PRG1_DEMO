//---------------------------------------------------------
// Fichier        : 06_string.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-07
// But            : démontrer les éléments de base des string
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------
// afficher s et lister les valeurs ASCII des caractères contenus
void afficher(const string& s);

//-------------------------------------------------------------------
int main() {

   //----------------------------------------------------------------
   cout << endl << "constructeurs"       << endl;
   string str1;                  // string vide
   string str2(3, 'a');          // "aaa"
// string str3(3);               // pas de constructeur
   string str4("une chaine C");
   string str5("un string"s);

   cout << "str1                 : ";           afficher(str1);            // ""
   cout << "str2                 : ";           afficher(str2);            // "aaa"
   cout << "str4                 : ";           afficher(str4);            // "une chaine C"
   cout << "str5                 : ";           afficher(str5);            // "un string"

   //----------------------------------------------------------------
   cout << endl << "taille et capacite"   << endl;
   cout << "str2                 : ";           afficher(str2);            // "aaa"
   cout << "str2.size()          : "   <<       str2.size()       << endl; // => 3
   cout << "str2.length()        : "   <<       str2.length()     << endl; // => 3
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl; // => 22

   cout << endl;
   cout << "str2.resize(5)"            << endl; str2.resize(5);
   cout << "str2                 : ";           afficher(str2);            // "aaa"
   cout << "str2.size()          : "   <<       str2.size()       << endl; // => 5
   cout << "str2.length()        : "   <<       str2.length()     << endl; // => 5
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl; // => 22

   cout << endl;
   cout << "str2.resize(10, '-')"      << endl; str2.resize(10, '-');
   cout << "str2                 : ";           afficher(str2);            // "aaa"
   cout << "str2.size()          : "   <<       str2.size()       << endl; // => 10
   cout << "str2.length()        : "   <<       str2.length()     << endl; // => 10
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl; // => 22

   cout << endl;
   cout << "str2.resize(8, '-')"       << endl; str2.resize(8, '-');
   cout << "str2                 : ";           afficher(str2);            // "aaa"
   cout << "str2.size()          : "   <<       str2.size()       << endl; // => 8
   cout << "str2.length()        : "   <<       str2.length()     << endl; // => 8
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl; // => 22

   //----------------------------------------------------------------
   cout << endl << "contenu"           << endl;
   cout << "str2.data()          : "   <<       str2.data()       << endl; // "aaa"
   cout << "str2.c_str()         : "   <<       str2.c_str()      << endl; // "aaa"
   cout << "strlen(str2.data())  : "   <<strlen(str2.data())      << endl; // => 3
   cout << "strlen(str2.c_str()) : "   <<strlen(str2.c_str())     << endl; // => 3


   return EXIT_SUCCESS;
}

//----------------------------------------------------------------
void afficher(const string& s) {
   cout << s;
   cout << "\t=> ";
   for (char c : s)
      cout << (unsigned short int)c << "  ";
   cout << endl;
}
