#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // cout et cin
#include <limits>    // numeric_limits<streamsize>
#include <iomanip>   // setw(...) et setprecision(...)

using namespace std;

int main() {

   cout << "digits         "  << numeric_limits<float>::digits          << endl;    // 24
   cout << "digits10       "  << numeric_limits<float>::digits10        << endl;    // 6
   cout << "max_digits10   "  << numeric_limits<float>::max_digits10    << endl;    // 9
   cout << "min_exponent10 "  << numeric_limits<float>::min_exponent10  << endl;    // -37
   cout << "max_exponent10 "  << numeric_limits<float>::max_exponent10  << endl;    // 38
   cout << "espilon        "  << numeric_limits<float>::epsilon()       << endl;    // 1.19209e-07

   cout << endl;
   cout << "digits         "  << numeric_limits<double>::digits         << endl;    // 53
   cout << "digits10       "  << numeric_limits<double>::digits10       << endl;    // 15
   cout << "max_digits10   "  << numeric_limits<double>::max_digits10   << endl;    // 17
   cout << "min_exponent10 "  << numeric_limits<double>::min_exponent10 << endl;    //-307
   cout << "max_exponent10 "  << numeric_limits<double>::max_exponent10 << endl;    // 308
   cout << "espilon        "  << numeric_limits<double>::epsilon()      << endl;    // 2.22045e-16

   cout << fixed      << setprecision(20) << 1.2 << endl;   // 1.19999999999999995559
   cout << scientific << setprecision(20) << 1.2 << endl;   // 1.19999999999999995559

   // fin de programme
   cout << "Presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}

