//---------------------------------------------------------
// Demo           : 06_string
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
#include <cstring>      // strlen (chaine C)
#include <iomanip>

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
   string str6("aaa\0bbb");
   string str7("aaa\0bbb"s);
   string str8("aaa",  5);       // => indéterminé
   string str9("aaa"s, 3);       // => vide
// string str10("aaa"s, 4);      // => pos > size => out_of_range

   cout << "str1                 : ";           afficher(str1);
   cout << "str2(3, 'a')         : ";           afficher(str2);
   cout << "str4(\"une chaine C\") : ";           afficher(str4);
   cout << "str5(\"un string\"s    : ";           afficher(str5);
   cout << "str6                 : ";           afficher(str6);
   cout << "str7                 : ";           afficher(str7);
   cout << "str8                 : ";           afficher(str8);
   cout << "str9                 : ";           afficher(str9);

   //----------------------------------------------------------------
   cout << endl << "taille et capacite"   << endl;
   cout << "str1                 : ";           afficher(str1);
   cout << "str1.size()          : "   <<       str1.size()       << endl;
   cout << "str1.length()        : "   <<       str1.length()     << endl;
   cout << "str1.capacity()      : "   <<       str1.capacity()   << endl;
   cout << "str1.data()          : " << (void*)str1.data()        << endl;

   cout << "str2                 : ";           afficher(str2);
   cout << "str2.size()          : "   <<       str2.size()       << endl;
   cout << "str2.length()        : "   <<       str2.length()     << endl;
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl;

   cout << endl;
   cout << "str2.resize(5)"            << endl; str2.resize(5);
   cout << "str2                 : ";           afficher(str2);
   cout << "str2.size()          : "   <<       str2.size()       << endl;
   cout << "str2.length()        : "   <<       str2.length()     << endl;
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl;

   cout << endl;
   cout << "str2.resize(10, '-')"      << endl; str2.resize(10, '-');
   cout << "str2                 : ";           afficher(str2);
   cout << "str2.size()          : "   <<       str2.size()       << endl;
   cout << "str2.length()        : "   <<       str2.length()     << endl;
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl;

   cout << endl;
   cout << "str2.resize(8, '-')"       << endl; str2.resize(8, '-');
   cout << "str2                 : ";           afficher(str2);
   cout << "str2.size()          : "   <<       str2.size()       << endl;
   cout << "str2.length()        : "   <<       str2.length()     << endl;
   cout << "str2.capacity()      : "   <<       str2.capacity()   << endl;

   //----------------------------------------------------------------
   cout << endl << "contenu"           << endl;
   cout << "str2.data()          : "   <<       str2.data()       << endl;
   cout << "str2.c_str()         : "   <<       str2.c_str()      << endl;
   cout << "strlen(str2.data())  : "   <<strlen(str2.data())      << endl;
   cout << "strlen(str2.c_str()) : "   <<strlen(str2.c_str())     << endl;

   //----------------------------------------------------------------
   cout << endl << "string vs c_str()" << endl;
   cout << "str2[1] = '\\0'"           << endl; str2[1] = '\0';
   cout << "str2                 : ";           afficher(str2);
   cout << "str2.size()          : "   <<       str2.size()       << endl;
   cout << "str2.length()        : "   <<       str2.length()     << endl;
   cout << "str2.data()          : "   <<       str2.data()       << endl;
   cout << "str2.c_str()         : "   <<       str2.c_str()      << endl;
   cout << "strlen(str2.data())  : "   <<strlen(str2.data())      << endl;
   cout << "strlen(str2.c_str()) : "   <<strlen(str2.c_str())     << endl;
   cout << "str2.data()[0]       : "   <<       str2.data()[0]    << endl;
   cout << "*(str2.data())       : "   <<       *(str2.data())    << endl;
   cout << "str2.c_str()[0]      : "   <<       str2.c_str()[0]   << endl;
   cout << "*(str2.c_str())      : "   <<       *(str2.c_str())   << endl;

   //----------------------------------------------------------------
   // en général, les méthodes retournent un string&
   // mais pas substr par exemple
   string str3("hello");
   str3.substr(1, 3);
   cout << "str3.substr(1, 3)             : " << str3 << endl;
   cout << "str3.substr(3, 10).size()     : " << str3.substr(3, 10).size()       << endl;
   cout << "str3.substr(3, 10) = \"toto\"   : " << (str3.substr(3, 10) = "toto") << endl;
   cout << "str3                          : " << str3                            << endl;

   return EXIT_SUCCESS;
}

//----------------------------------------------------------------
void afficher(const string& s) {
   cout << left << setw(15) << s;
   cout << "\t=> ";
   for (char c : s)
      cout << (unsigned short int)c << "  ";
   cout << endl;
}


//      constructeurs
//      str1                 :                   =>
//      str2(3, 'a')         : aaa               => 97  97  97
//      str4("une chaine C") : une chaine C      => 117  110  101  32  99  104  97  105  110  101  32  67
//      str5("un string"s    : un string         => 117  110  32  115  116  114  105  110  103
//      str6                 : aaa               => 97  97  97
//      str7                 : aaa bbb           => 97  97  97  0  98  98  98
//      str8                 : aaa s             => 97  97  97  0  115
//      str9                 :                   =>
//
//      taille et capacite
//      str1                 :                   =>
//      str1.size()          : 0
//      str1.length()        : 0
//      str1.capacity()      : 22
//      str1.data()          : 0x7ff7bfeff201
//      str2                 : aaa               => 97  97  97
//      str2.size()          : 3
//      str2.length()        : 3
//      str2.capacity()      : 22
//
//      str2.resize(5)
//      str2                 : aaa               => 97  97  97  0  0
//      str2.size()          : 5
//      str2.length()        : 5
//      str2.capacity()      : 22
//
//      str2.resize(10, '-')
//      str2                 : aaa  -----        => 97  97  97  0  0  45  45  45  45  45
//      str2.size()          : 10
//      str2.length()        : 10
//      str2.capacity()      : 22
//
//      str2.resize(8, '-')
//      str2                 : aaa  ---          => 97  97  97  0  0  45  45  45
//      str2.size()          : 8
//      str2.length()        : 8
//      str2.capacity()      : 22
//
//      contenu
//      str2.data()          : aaa
//      str2.c_str()         : aaa
//      strlen(str2.data())  : 3
//      strlen(str2.c_str()) : 3
//
//      string vs c_str()
//      str2[1] = '\0'
//      str2                 : a a  ---          => 97  0  97  0  0  45  45  45
//      str2.size()          : 8
//      str2.length()        : 8
//      str2.data()          : a
//      str2.c_str()         : a
//      strlen(str2.data())  : 1
//      strlen(str2.c_str()) : 1
//      str2.data()[0]       : a
//      *(str2.data())       : a
//      str2.c_str()[0]      : a
//      *(str2.c_str())      : a
//      str3.substr(1, 3)             : hello
//      str3.substr(3, 10).size()     : 2
//      str3.substr(3, 10) = "toto"   : toto
//      str3                          : hello
