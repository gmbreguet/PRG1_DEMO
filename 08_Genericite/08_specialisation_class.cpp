//---------------------------------------------------------
// Demo           : 08_specialisation_class
// Fichier        : 08_specialisation_class.cpp
// Version        : 02 - 2022.01.-15
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme utilisé pour sélectionner une class
//                  en cas de spécialisation et de surcharge
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------
// 1) class générique
//---------------------------------------------------
template <typename T, typename U>
class C {
public:
   C(T t, U u) : t(t), u(u) { cout << "1) C<T, U>" << endl; }
private:
   T t;
   U u;
};

//---------------------------------------------------
// 2) spécialisation de 1)
//---------------------------------------------------
template <typename T>
class C<T, T> {
public:
   C(T t1, T t2) : t1(t1), t2(t2) { cout << "2) C<T, T>" << endl; }
private:
   T t1;
   T t2;
};

//---------------------------------------------------
// 3) spécialisation partielle de 1)
// compile au contraire des fonctions
// avec spécialisation partielle
//---------------------------------------------------
template <typename U>
class C<int, U> {
public:
   C(int i, U u) : i(i), u(u) { cout << "3) C<int, U>" << endl; }
private:
   int i;
   U   u;
};

///---------------------------------------------------
// 4) spécialisation complète de 1)
//---------------------------------------------------
template <>
class C<int, float> {
public:
   C(int i, float f) : i(i), f(f) { cout << "4) C<int, float>" << endl; }
private:
   int   i;
   float f;
};

//---------------------------------------------------
int main() {

   //------------------------------------------------
   // par déduction (dès C++17)
   //------------------------------------------------
   // NB : la déduction des paramètres génériques n'est possible que
   //      - depuis C++17
   //      - en fonction du/des paramètre(s) du constructeurs
   //        => C() => pas de déduction
   //------------------------------------------------
// C c01( 1,   2);               //  {1 2 3 4} ∩ {1 2 3  } => {  2 3  } => ambiguous
   C c02( 1,   2.f);             //  {1 2 3 4} ∩ {1   3 4} => {  2 3  } => 4) C<int, float>
   C c03('a', 'b');              //  {1 2    } ∩ {1 2    } => {1 2    } => 2) C<char, char>
   C c04(true, 2.);              //  {1      } ∩ {1      } => {1      } => 1) C<bool, double>

   //------------------------------------------------
   // paramètres génériques explicitement nommés
   //------------------------------------------------
// C<int, int>   c11(1, 2);      //  {1 2 3 4} ∩ {1 2 3  } => {  2 3  } => ambiguous
// C<int, int>   c21(1, 2);      //  {1 2 3 4} ∩ {1 2 3  } => {  2 3  } => ambiguous
   C<int, char>  c23(1, 2);      //  {1 2 3 4} ∩ {1   3  } => {    3  } => 3) C<int, char>
   C<int, float> c24(1, 2);      //  {1 2 3 4} ∩ {1   3 4} => {      4} => 4) C<int, float>

   return EXIT_SUCCES;
}

