//---------------------------------------------------------
// Fichier        : 05_vector_size_vs_capacity.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : démontrer l'évolution de size et capacity
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//---------------------------------------------------------
using Vect = vector<int>;

//---------------------------------------------------------
void putHeader (const string& ACTION, int MARGE);
void putDetails(const Vect& v, const string& msg);

//---------------------------------------------------------
const int MARGE   =      17;
const int STEP    =  10'000;
const int MAX     = 100'000;

//---------------------------------------------------------
int main() {

   Vect  v;

   //---------------------------------------------------------
   cout  << "-----------------------------------------------------"  << endl;
   cout << "sizeof de vecteurs : " << endl;
   cout << "Vect(  0)   : " << sizeof(Vect(  0))   << " octets" << endl;
   cout << "Vect( 10)   : " << sizeof(Vect( 10))   << " octets" << endl;
   cout << "Vect(100)   : " << sizeof(Vect(100))   << " octets" << endl;

   //---------------------------------------------------------
   putHeader("RESIZE", MARGE);
   v.resize(100);          putDetails(v, "v(100)");
   v.resize(10'000);       putDetails(v, "v.resize(1000)");
   v.resize(10);           putDetails(v, "v.resize(10)");


   //---------------------------------------------------------
   putHeader("CAPACITY", MARGE);
   v.reserve(10);
   v.shrink_to_fit();      putDetails(v, "v.reserve(10)");
   v.reserve(1000);        putDetails(v, "v.reserve(1000)");
   v.reserve(10);          putDetails(v, "v.reserve(10)");
   v.resize(10);           putDetails(v, "v.resize(10)");
   v.shrink_to_fit();      putDetails(v, "v.shrink_to_fit()");

   //---------------------------------------------------------
   putHeader("PUSH_BACK", MARGE);
   v.resize(0);
   v.shrink_to_fit();
   for (int i=1; i<=MAX; ++i) {
      v.push_back(i);

      // affichage stats
      if (i % STEP == 0)
         putDetails(v, "push_back ... " + to_string(i));
   }
   

   //---------------------------------------------------------
   putHeader("POP_BACK", MARGE);
   for (int i=MAX; i>=0; --i) {
      // affichage stats
      if (i % STEP == 0)
         putDetails(v, "pop_back ... " + to_string(i));

      v.pop_back();
   }

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
void putHeader(const string& ACTION, int MARGE) {
   cout  << "-----------------------------------------------------"  << endl
         << ACTION                                                   << endl
         << setw(MARGE) << right << "INSTRUCTION"
         << setw(MARGE) << right << "TAILLE"
         << setw(MARGE) << right << "CAPACITY"                       << endl
         << "-----------------------------------------------------"  << endl;
}

//---------------------------------------------------------
void putDetails(const Vect& v, const string& msg) {
   cout  << setw(MARGE) << left  << msg
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
}
