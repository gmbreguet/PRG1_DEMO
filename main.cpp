#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <vector>
#include <array>

using namespace std;

using Type      = int;
using vecteur1D = vector<Type>;
using vecteur2D = vector<vecteur1D>;


//------------------------------------------------------
ostream& operator<< (ostream& os, const array<int, 10>& a) {
   os << "[";
   for (size_t i=0; i<a.size(); ++i) {
      if (i)
         os << ", ";
      os << a[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
ostream& operator<< (ostream& os, const vecteur1D& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
ostream& operator<< (ostream& os, const vecteur2D& v) {
   for (size_t i=0; i<v.size(); ++i) {
      os << v[i] << endl;
   }
   return os;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {
   vecteur1D v1;
   vecteur2D v2;

   v1.resize(2);
   v2.resize(10);

   cout << "v1.size()         "  << v1.size()         << endl;
   cout << "v2.size()         "  << v2.size()         << endl;

   // définir les dimensions
   for (size_t i=0; i<v2.size(); ++i)
      v2.at(i).resize(i);

   // afficher les dimensions
   cout << v1 << endl
        << v2;
//      cout << "v2.at(i).size()   "  << v2.at(i).size()   << endl;


   vecteur2D v3 = {v1, vecteur1D(6), vecteur1D(3)};
   cout << endl;
   cout << v3 << endl;

   vecteur2D v4(10, vecteur1D(4) );
   cout << v4 << endl;

   cout << "nbre colonnes : " << v2.size()         << endl;    //  nbre de lignes
   cout << "nbre colonnes : " << v2.at(0).size()   << endl;    //  nbre de colonnes

   v4.resize(3);
   v4.at(2).resize(3);
   cout << endl;
   cout << v4 << endl;


   char  tab1[10][80];
   char* tab2[10];

   // ---------------------------------------------
   // array
   // ---------------------------------------------
   array<int, 10> tableau1 = {1, 2, 3, 4, 5};
   array<int, 12> tableau2 = {1, 2, 3, 4, 5};
   cout << endl << tableau1 << endl;
   cout << endl << tableau2 << endl;

   // ---------------------------------------------
   // fin de programme
   // ---------------------------------------------
   cout << endl << endl;
   cout << "presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}
