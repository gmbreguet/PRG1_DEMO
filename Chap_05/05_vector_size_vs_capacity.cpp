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
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//---------------------------------------------------------
void putHeader(const string& ACTION, int MARGE);

//---------------------------------------------------------
int main() {

   const int MARGE   =     17;
   const int STEP    =  10000;
   const int MAX     = 100000;

   using Vect = vector<int>;
   Vect  v;

   //---------------------------------------------------------
   putHeader("RESIZE", MARGE);
   v.resize(100);
   cout  << setw(MARGE) << left  << "v(100)"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
   
   v.resize(10000);
   cout  << setw(MARGE) << left  << "v.resize(1000)"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
   
   v.resize(10);
   cout  << setw(MARGE) << left  << "v.resize(10)"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
   

   //---------------------------------------------------------
   putHeader("CAPACITY", MARGE);
   v.reserve(10);
   v.shrink_to_fit();
   cout  << setw(MARGE) << left  << "v.reserve(10)"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
   
   v.reserve(1000);
   cout  << setw(MARGE) << left  << "v.reserve(1000)"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
   
   v.reserve(10);
   cout  << setw(MARGE) << left  << "v.reserve(10)"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
   
   v.resize(10);
   cout  << setw(MARGE) << left  << "v.resize(10)"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;
   
   v.shrink_to_fit();
   cout  << setw(MARGE) << left  << "v.shrink_to_fit()"
         << setw(MARGE) << right << v.size()
         << setw(MARGE) << right << v.capacity()
         << endl;


   //---------------------------------------------------------
   putHeader("PUSH_BACK", MARGE);
   v.resize(0);
   for (int i=1; i<=MAX; ++i) {
      v.push_back(i);

      // affichage stats
      if (i % STEP == 0)
         cout  << setw(MARGE) << right << i
               << setw(MARGE) << right << v.size()
               << setw(MARGE) << right << v.capacity()
               << endl;
   }
   

   //---------------------------------------------------------
   putHeader("POP_BACK", MARGE);
   for (int i=MAX; i>=0; --i) {
      // affichage stats
      if (i % STEP == 0)
         cout  << setw(MARGE) << right << i
               << setw(MARGE) << right << v.size()
               << setw(MARGE) << right << v.capacity()
               << endl;

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
