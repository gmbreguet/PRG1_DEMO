//---------------------------------------------------------
// Demo           : 08_specialisation
// Fichier        : 08_specialisation.cpp
// Version        : 02 - 2022.01.15
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme utilisé pour sélectionner une fonction
//                  en cas de spécialisation et de surcharge
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//https://stackoverflow.com/questions/994949/specialize-function-templates-vs-function-overload-vs-class-specializing
// Overload resolution only selects a base template (or a nontemplate function, if one is available).
// Only after it's been decided which base template is going to be selected, and that choice is locked in,
// will the compiler look around to see if there happens to be a suitable specialization of that template
// available, and if so that specialization will get used.


template <typename T, typename U> int f            (T, U)       {return 1;}
template <>                       int f<int, float>(int, float) {return 2;} // specialisation de 1

template <typename U>             int f            (int, U)     {return 3;} // surcharge
template <>                       int f<float>     (int, float) {return 4;} // specialisation de 3

int main() {

   cout << f(int(), float()) << endl; // Affiche 4

   // Overload resolution only selects a base template (or a nontemplate function, if one is available).
   // Only after it's been decided which base template is going to be selected, and that choice is locked in,
   // {1, 3} ∩ {1, 3} => {1, 3} => 3 plus spécialisé

   // will the compiler look around to see if there happens to be a suitable specialization of that template
   // available, and if so that specialization will get used.
   // => 4 plus spécialisée

   return EXIT_SUCCESS;
}
