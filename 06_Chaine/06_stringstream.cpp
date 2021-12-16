//---------------------------------------------------------
// Demo           : 06_string_stream
// Fichier        : 06_string_stream.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-15
// But            : démontrer l'utilisation de stringstream
// Modifications  :
// Remarque(s)    : tuto sympa
//                : https://www.softwaretestinghelp.com/stringstream-class-in-cpp
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

//-------------------------------------------------------------------
using Data    = int;
using Vecteur = vector<Data>;

//-------------------------------------------------------------------
ostream& operator<<(ostream& os, const Vecteur& v);
string to_string(const Vecteur& v);

//-------------------------------------------------------------------
int main() {

   //----------------------------------------------------------------
   // utlisation de sstream transmis a l'operateur <<
   //----------------------------------------------------------------
   stringstream ss;
   ss.str("bonjour");                   // assign dans ss
   cout << ss.str();
   ss.str(" a tous");                   // assign dans ss
   cout << ss.str() << endl;

   cout << endl;
   ss << "hello " << "world" << endl;
   cout << ss.str();                    // toute la chaine yc endl

   ss.str("");                          // assign => efface ss
   cout << ss.str();

   //----------------------------------------------------------------
   // utilisation de sstream pour creer un string
   //----------------------------------------------------------------
   cout << endl;
   Vecteur v{1, 2, 3, 4};
   cout << "vecteur : " << v << endl;

   string output = "vecteur : " + to_string(v);
   cout << output << endl;
   cout << endl;

   return EXIT_SUCCESS;
}

//-------------------------------------------------------------------
string to_string(const Vecteur& v){
   const size_t W =  3;    // espacement
   const char   F = '0';   // caractere fill
   
   stringstream ss;
   ss << "[";
   for(Vecteur::size_type i=0; i<v.size(); ++i) {
      if(i)
         ss << ", ";
      ss << setfill(F) << setw(W) << to_string(v[i]);
   }
   ss << "]";
   
   return ss.str();
}

//-------------------------------------------------------------------
ostream& operator<<(ostream& os, const Vecteur& v){
   return os << to_string(v);
}

//-------------------------------------------------------------------
// output
//-------------------------------------------------------------------
//      bonjour a tous
//
//      hello world
//
//      vecteur : [001, 002, 003, 004]
//      vecteur : [001, 002, 003, 004]
//
