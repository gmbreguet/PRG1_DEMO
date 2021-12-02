//---------------------------------------------------------
// Fichier        : annexes.h (h pour header)
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-09-15
// But            : ce fichier ne contient uniquement les
//                  déclarations mises à disposition par la librairie
//
//                  Ce fichier doit  documenter les elements
//                  mis à disposition de l'utilisateur
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

//-------------------------------------------------------------------------
// /!\ eviter les inclusions multiples
#ifndef annexe

   #define annexe

   // UNIQUEMENT les includes pour les éléments nécessaires au .h
   #include <string>          // nécessaire pour les paramètres
   //using namespace std;     // à mettre dans le .cpp pour ne
                              // pas le transmettre à l'appelant, ici main
                              // => ajouter std::

   //-------------------------------------------------------------------------
   // déclaration mise à disposition par le .h
   extern const int CONSTANTE;

   // un sous-programme
   void sousPgm (const std::string& msg);

#endif
