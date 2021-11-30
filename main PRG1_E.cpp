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

//------------------------------------------------------
using vecteur = vector<char>;
using matrice = vector<vecteur>;

//------------------------------------------------------
ostream& operator<< (ostream& os, const array<int, 10>& a) {
   os << "[";
   for (size_t i=0; i<a.size(); ++i) {
      if (i)
         os << ", ";
      os << a.at(i);
   }
   os << "]";
   return os;
}
//------------------------------------------------------
ostream& operator<< (ostream& os, const vecteur& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v.at(i);
   }
   os << "]";
   return os;
}

//------------------------------------------------------
ostream& operator<< (ostream& os, const matrice& m) {
   for (size_t i=0; i<m.size(); ++i) {
      os << m.at(i) << endl;
   }
   return os;
}

//------------------------------------------------------
vector<int> creer(size_t taille) {
   vector<int> local(taille);
   int valeur = 0;
   for (int& i : local)
      i = ++valeur;
   return local;
}


//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   /*
   vector<int> tmp = creer(5);
   cout << tmp << endl;

   vecteur v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   matrice m = {v, v, v, v, v};
   cout << tmp << endl;

   int* ptr = v.data();

   // operateurs de flux
   cout << endl;
   cout << m << endl;


   cout << "sizeof(v): " << sizeof(v)  << endl;
   cout << "sizeof(v): " << sizeof(v)/sizeof(int)  << endl;
   cout << "taille   : " << v.size()               << endl;
   cout << "capacité : " << v.capacity()           << endl;
   cout << "front    : " << v.front()              << endl;
   cout << "back     : " << v.back()               << endl;

   v.resize(3);
   v.reserve(1);
   cout << endl;
   cout << "taille   : " << v.size()               << endl;
   cout << "capacité : " << v.capacity()           << endl;
   cout << "front    : " << v.front()              << endl;
   cout << "back     : " << v.back()               << endl;

   cout << endl;

   for (int i=0; i<10; ++i)
      v.push_back(10 * i);
   cout << "taille   : " << v.size()               << endl;
   cout << "capacité : " << v.capacity()           << endl;
   cout << "front    : " << v.front()              << endl;
   cout << "back     : " << v.back()               << endl;

   // pop_back
   cout << endl;
   cout << "back     : " << v.back()               << endl;
   v.pop_back();
   cout << "back     : " << v.back()               << endl;
*/

   // ---------------------------------------------
   // vecteur 2D
   // ---------------------------------------------
   vecteur v1;
   v1.resize(4);

   matrice v2 = {v1, v1, v1};
   v2.resize(10);

//   cout << "taille   : " << v1.size()              << endl;
   cout << "taille   : " << v2.size()              << endl;
   cout << "taille   : " << v2.at(0).size()        << endl;
   cout << "taille   : " << v2.at(1).size()        << endl;

   for (size_t i=0; i<v2.size(); ++i)
      v2.at(i).resize(i);

   cout << v1 << endl;
   cout << v2 << endl;

   // ---------------------------------------------
   // array
   // ---------------------------------------------
   array<int, 10> a1 = {1, 2, 3, 4, 5};
   array<int, 20> a2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   cout << a1 << endl;
//   cout << a2 << endl;
   cout << "sizeof() : " << sizeof(a1)              << endl;
   cout << "taille   : " << a1.size()               << endl;

   array<int, 0> a3;
   cout << "sizeof() : " << sizeof(a3)              << endl;
   cout << "taille   : " << a3.size()               << endl;


   // ---------------------------------------------
   // fin de programme
   // ---------------------------------------------
   cout << endl << endl;
   cout << "presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}
