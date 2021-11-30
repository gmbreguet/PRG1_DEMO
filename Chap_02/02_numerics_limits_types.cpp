/*
 ------------------------------------------------------------------------------
 Fichier       : 02-03_climits.cpp
 Auteur(s)     : BREGUET Guy-Michel
 Date          : 2020-09-15
 But           : utilisation de numerics_limits<type>::xx
 Remarque(s)   : NILL
 ------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int main () {

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::min()            : " << numeric_limits<bool>::min()           << endl;
   cout << "numeric_limits<char>::min()            : " << numeric_limits<char>::min()           << endl;
   cout << "numeric_limits<short>::min()           : " << numeric_limits<short>::min()          << endl;
   cout << "numeric_limits<int>::min()             : " << numeric_limits<int>::min()            << endl;
   cout << "numeric_limits<long>::min()            : " << numeric_limits<long>::min()           << endl;
   cout << "numeric_limits<float>::min()           : " << numeric_limits<float>::min()          << endl;
   cout << "numeric_limits<double>::min()          : " << numeric_limits<double>::min()         << endl;
   cout << "numeric_limits<long double>::min()     : " << numeric_limits<long double>::min()    << endl;

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::lowest()         : " << numeric_limits<bool>::lowest()        << endl;
   cout << "numeric_limits<char>::lowest()         : " << numeric_limits<char>::lowest()        << endl;
   cout << "numeric_limits<short>::lowest()        : " << numeric_limits<short>::lowest()       << endl;
   cout << "numeric_limits<int>::lowest()          : " << numeric_limits<int>::lowest()         << endl;
   cout << "numeric_limits<long>::lowest()         : " << numeric_limits<long>::lowest()        << endl;
   cout << "numeric_limits<float>::lowest()        : " << numeric_limits<float>::lowest()       << endl;
   cout << "numeric_limits<double>::lowest()       : " << numeric_limits<double>::lowest()      << endl;
   cout << "numeric_limits<long double>::lowest()  : " << numeric_limits<long double>::lowest() << endl;

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::max()            : " << numeric_limits<bool>::max()           << endl;
   cout << "numeric_limits<char>::max()            : " << numeric_limits<char>::max()           << endl;
   cout << "numeric_limits<short>::max()           : " << numeric_limits<short>::max()          << endl;
   cout << "numeric_limits<int>::max()             : " << numeric_limits<int>::max()            << endl;
   cout << "numeric_limits<long>::max()            : " << numeric_limits<long>::max()           << endl;
   cout << "numeric_limits<float>::max()           : " << numeric_limits<float>::max()          << endl;
   cout << "numeric_limits<double>::max()          : " << numeric_limits<double>::max()         << endl;
   cout << "numeric_limits<long double>::max()     : " << numeric_limits<long double>::max()    << endl;

   cout << "-----------------------------------------------------------------------------"      << endl;
   cout << "numeric_limits<bool>::digits           : " << numeric_limits<bool>::digits          << endl;
   cout << "numeric_limits<char>::digits           : " << numeric_limits<char>::digits          << endl;
   cout << "numeric_limits<short>::digits          : " << numeric_limits<short>::digits         << endl;
   cout << "numeric_limits<int>::digits            : " << numeric_limits<int>::digits           << endl;
   cout << "numeric_limits<long>::digits           : " << numeric_limits<long>::digits          << endl;
   cout << "numeric_limits<float>::digits          : " << numeric_limits<float>::digits         << endl;
   cout << "numeric_limits<double>::digits         : " << numeric_limits<double>::digits        << endl;
   cout << "numeric_limits<long double>::digits    : " << numeric_limits<long double>::digits   << endl;

   cout << "-----------------------------------------------------------------------------"      << endl;
   // Fin du programme
   cout << "presser ENTER pour quitter" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}
