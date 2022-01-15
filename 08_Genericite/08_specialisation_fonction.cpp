//---------------------------------------------------------
// Demo           : 08_specialisation_fonction
// Fichier        : 08_specialisation_fonction.cpp
// Version        : 02 - 2022.01.15
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme utilisé pour sélectionner une fonction
//                  en cas de spécialisation et de surcharge
//                  CHAQUE SELECTION EST ILLUSTREE EN DETAIS
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

//---------------------------------------------------
// 1) fonction générique
template <typename T, typename U>
void f(T t, U u);

//---------------------------------------------------
// 2) specialisation partielle => PAS POSSIBLE
//template <typename U> void f<int, U>(int t, U u);

//---------------------------------------------------
// 3) specialisation complete de 1
template <>
void f<int, float>(int t, float u);

//---------------------------------------------------
// 4) surcharge de 1 => pas spécialisation
// NB : le 1er paramètre permet une conversion vers int
template <typename U>
void f(int t, U u);

//---------------------------------------------------
// 5) surcharge ordinaire (non générique)
void f(int t, double d);

int main() {
   //------------------------------------------------
   // par déduction
   //------------------------------------------------
   cout << "11) ";    f('a', 'b');           // {1  4  } ∩ {1  4  } => {1  4  } => 1 f<T, U>          types exactes
   cout << "12) ";    f(1.2, 3);             // {1  4  } ∩ {1  4  } => {1  4  } => 1 f<T, U>          types exactes
   cout << "13) ";    f(1, 2.3f);            // {1  4 5} ∩ {1  4  } => {1  4  } => 4 f<int, U>        surcharge
   cout << "14) ";    f(1, 2);               // {1  4 5} ∩ {1  4  } => {1  4  } => 4 f<int, U>        surcharge
   cout << "15) ";    f(1, 2.3);             // {1  4 5} ∩ {1  4 5} => {1  4 5} => 5 f<int, double>   fonction ordinaire (non générique)

   //------------------------------------------------
   // par déduction
   // avec <> seules les fonctions génériques sont considérées
   //------------------------------------------------
   cout << "21) ";    f<>('a', 'b');         // {1  4  } ∩ {1  4  } => {1  4  } => 1 f<T, U>          types exactes
   cout << "22) ";    f<>(1.2, 3);           // {1  4  } ∩ {1  4  } => {1  4  } => 1 f<T, U>          types exactes
   cout << "23) ";    f<>(1, 2.3f);          // {1  4  } ∩ {1  4  } => {1  4  } => 4 f<int, U>        surcharge
   cout << "24) ";    f<>(1, 2);             // {1  4  } ∩ {1  4  } => {1  4  } => 4 f<int, U>        surcharge
   cout << "25) ";    f<>(1, 2.3);           // {1  4  } ∩ {1  4  } => {1  4  } => 4 f<int, U>        surcharge

   //------------------------------------------------
   // par déduction partielle
   // avec <...> seules les fonctions génériques sont considérées
   //------------------------------------------------
   cout << "31) ";    f<int>('a', 'b');      // {1  4  } ∩ {1  4  } => {1  4  } => 1 f<T, U>          type exact, sinon il y aurait ajustement de type
   cout << "32) ";    f<int>(1.2, 3);        // {1  4  } ∩ {1  4  } => {1  4  } => 4 f<int, U>        surcharge (warning : 1.2 converti en int)
   cout << "33) ";    f<int>(1, 2.3f);       // {1  4  } ∩ {1  4  } => {1  4  } => 3 f<int, float>    /!\ spécialisation disponible !!
   cout << "34) ";    f<int>(1, 2);          // {1  4  } ∩ {1  4  } => {1  4  } => 4 f<int, U>        surcharge
   cout << "35) ";    f<int>(1, 2.3);        // {1  4  } ∩ {1  4  } => {1  4  } => 1 f<T, U>          type exact, sinon il y aurait ajustement de type
   //                                            |  |       |  |
   //                                            |  |       |  *------ <int>     => 2ème paramètre effectif converti en int
   //                                            |  |       *--------- <int, ?>  => 2ème paramtère déduit => type exact
   //                                            |  *----------------- int       => 1er  paramètre effectif converti en int
   //                                            *-------------------- <int, ?>  => 1er  paramètre effectif converti en int

   //------------------------------------------------
   // les paramètres génériques sont explicitement fixés
   //------------------------------------------------
   cout << "41) ";    f<int, int>('a', 'b'); // {1     } ∩ {1     } => {1     } => 1 f<T, U>
   cout << "42) ";    f<int, int>(1.2, 3);   // {1     } ∩ {1     } => {1     } => 1 f<T, U>          warning : 1.2  converti en int
   cout << "43) ";    f<int, int>(1, 2.3f);  // {1     } ∩ {1     } => {1     } => 1 f<T, U>          warning : 2.3f converti en int
   cout << "44) ";    f<int, int>(1, 2);     // {1     } ∩ {1     } => {1     } => 1 f<T, U>
   cout << "45) ";    f<int, int>(1, 2.3);   // {1     } ∩ {1     } => {1     } => 1 f<T, U>          warning : 2.3  converti en int
   //                  <int, int> => nécessairement 2 paramètres génériques

   return EXIT_SUCCESS;
}

//---------------------------------------------------
// 1) fonction générique
template <typename T, typename U>
void f(T t, U u) {
   cout << "f<T, U>" << endl;
}

//---------------------------------------------------
// 2) specialisation partielle => PAS POSSIBLE
//template <typename U>
//void f<int, U>(int t, U u) {
//   cout << "f<int, U>" << endl;
//}

//---------------------------------------------------
// 3) specialisation complete
template <>
void f<int, float>(int t, float u) {
   cout << "f<int, float>" << endl;
}

//---------------------------------------------------
// 4) surcharge de 1 => pas spécialisation
template <typename U>
void f(int t, U u) {
   cout << "f<int, U>" << endl;
}

//---------------------------------------------------
// 5) surcharge ordinaire (non générique)
void f(int t, double d) {
   cout << "f(int, double)" << endl;
}
