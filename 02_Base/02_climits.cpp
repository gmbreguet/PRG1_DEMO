//---------------------------------------------------------
// Demo           : 02_climits
// Fichier        : 02_climits.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-10-01
// But            : Utilisation de climnits et débordements
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>

using namespace std;

int main () {
   // declaration des variables et initialisation
   int         unEntier     =    1;
   float       unReel       = 10.0;
   double      unDouble     = 20.0;
   long double unLongDouble = 3.14;

   char        unCaractere  = 'a';
   bool        unBool       = false;

   /**************************************************************************/

   // Message de bienvenue
   cout << endl;
   cout << "*********************************************" << endl
        << "* Programme qui donne les caracteristiques  *" << endl
        << "* des differents types en c++               *" << endl
        << "*********************************************" << endl;

   cout << "----------------------------------------------------------"<< endl;
   // Manipulation des entiers
   cout << "le nombre d'octet pour <int>           : " << sizeof(int)  << endl;
   cout << "unEntier est de type int et vaut       : " << unEntier     << endl;
   cout << "Valeur min de int                      : " << INT_MIN      << endl;
   cout << "Valeur max de int                      : " << INT_MAX      << endl;
   cout << "Valeur max de int + 1                  : " << INT_MAX + 1  << endl;

   unEntier = 21474836470.;   //INT_MAX * 10;
   cout << "Valeur max (overflow <= int)           : " << unEntier     << endl;

   unEntier = 21474836470;    //INT_MAX * 10;
   cout << "Valeur max (overflow <= double)        : " << unEntier     << endl;

   cout << "----------------------------------------------------------"<< endl;
   // Manipulation des reel
   cout << "le nombre d'octet pour <float>         : " << sizeof(float)<< endl;
   cout << "digit                                  : " << FLT_DIG      << endl;
   cout << "unReel est de type float et vaut       : " << unReel       << endl;
   cout << "Valeur min de float                    : " << FLT_MIN      << endl;
   cout << "Valeur max de float                    : " << FLT_MAX      << endl;
   cout << "Valeur max de float + 1                : " << FLT_MAX + 1  << endl;
   cout << "Valeur max de float * 10               : " << FLT_MAX * 10 << endl;

   cout << "----------------------------------------------------------"<< endl;
   // Manipulation des double reel
   cout << "le nombre d'octet pour <double>        : " <<sizeof(double)<< endl;
   cout << "digit                                  : " << DBL_DIG      << endl;
   cout << "unReel est de type double et vaut      : " << unDouble     << endl;
   cout << "Valeur min de double                   : " << DBL_MIN      << endl;
   cout << "Valeur max de double                   : " << DBL_MAX      << endl;
   cout << "Valeur max de double + 1               : " << DBL_MAX + 1  << endl;
   cout << "Valeur max de double * 10              : " << DBL_MAX * 10 << endl;

   cout << "----------------------------------------------------------"<< endl;
   // Manipulation des long double reel
   cout << "le nombre d'octet pour <long double>   : " << sizeof(long double)
        << endl;
   cout << "digit                                  : " << LDBL_DIG     << endl;
   cout << "unReel est de type long double et vaut : " << unLongDouble << endl;
   cout << "Valeur min de long double              : " << LDBL_MIN     << endl;
   cout << "Valeur max de long double              : " << LDBL_MAX     << endl;
   cout << "Valeur max de long double + 1          : " << LDBL_MAX + 1 << endl;
   cout << "Valeur max de long double * 10         : " << LDBL_MAX * 10<< endl;

   cout << "----------------------------------------------------------"<< endl;
   // Manipulation des Caractere
   cout << "le nombre d'octet pour <char>          : " << sizeof(char) << endl;
   cout << "unCaractere est de type char et vaut   : " << unCaractere  << endl;
   cout << "Valeur min de char                     : " << CHAR_MIN     << endl;
   cout << "Valeur max de char                     : " << CHAR_MAX     << endl;
   cout << "Valeur max de char + 1                 : " << CHAR_MAX + 1 << endl;

   cout << "----------------------------------------------------------"<< endl;
   // Manipulation des boolean
   cout << "le nombre d'octet pour <bool>          : " << sizeof(bool) << endl;
   cout << "unBool est de type bool et vaut        : " << unBool       << endl;
   cout << "nbre de bits pour un char              : " << CHAR_BIT     << endl;
   cout << "Valeur min de bool                     : " << false        << endl;
   cout << "Valeur max de bool                     : " << true         << endl;
   cout << "Valeur max de bool + 1                 : " << unBool + 1   << endl;


   cout << "----------------------------------------------------------"<< endl;
   cout << "----------------------------------------------------------"<< endl;

   // Fin du programme
   cout << "presser ENTER pour quitter" << endl;
   getchar(); // system("pause"); en C++
   return EXIT_SUCCESS;
}

//    *********************************************
//    * Programme qui donne les caracteristiques  *
//    * des differents types en c++               *
//    *********************************************
//    ----------------------------------------------------------
//    le nombre d'octet pour <int>           : 4
//    unEntier est de type int et vaut       : 1
//    Valeur min de int                      : -2147483648
//    Valeur max de int                      : 2147483647
//    Valeur max de int + 1                  : -2147483648
//    Valeur max (overflow <= int)           : 2147483647
//    Valeur max (overflow <= double)        : -10
//    ----------------------------------------------------------
//    le nombre d'octet pour <float>         : 4
//    digit                                  : 6
//    unReel est de type float et vaut       : 10
//    Valeur min de float                    : 1.17549e-38
//    Valeur max de float                    : 3.40282e+38
//    Valeur max de float + 1                : 3.40282e+38
//    Valeur max de float * 10               : inf
//    ----------------------------------------------------------
//    le nombre d'octet pour <double>        : 8
//    digit                                  : 15
//    unReel est de type double et vaut      : 20
//    Valeur min de double                   : 2.22507e-308
//    Valeur max de double                   : 1.79769e+308
//    Valeur max de double + 1               : 1.79769e+308
//    Valeur max de double * 10              : inf
//    ----------------------------------------------------------
//    le nombre d'octet pour <long double>   : 16
//    digit                                  : 33
//    unReel est de type long double et vaut : 3.14
//    Valeur min de long double              : 3.3621e-4932
//    Valeur max de long double              : 1.18973e+4932
//    Valeur max de long double + 1          : 1.18973e+4932
//    Valeur max de long double * 10         : inf
//    ----------------------------------------------------------
//    le nombre d'octet pour <char>          : 1
//    unCaractere est de type char et vaut   : a
//    Valeur min de char                     : 0
//    Valeur max de char                     : 255
//    Valeur max de char + 1                 : 256
//    ----------------------------------------------------------
//    le nombre d'octet pour <bool>          : 1
//    unBool est de type bool et vaut        : 0
//    nbre de bits pour un char              : 8
//    Valeur min de bool                     : 0
//    Valeur max de bool                     : 1
//    Valeur max de bool + 1                 : 1
//    ----------------------------------------------------------
//    ----------------------------------------------------------
//    presser ENTER pour quitter
