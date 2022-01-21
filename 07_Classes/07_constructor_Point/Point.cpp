//---------------------------------------------------------
// Demo           : 07_constructor
// Fichier        : Point.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer les bases des constructeurs
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>

#include "Point.hpp"

using namespace std;

//----------------------------------------------------
// constructeurs
//----------------------------------------------------
Point::Point()
: nom("defaut"), x(0), y(0) {
   cout << "constructeur sans paramètre ..." << endl;
   // this->nom = "nouveau";  // pas possible car const
}

//----------------------------------------------------
Point::Point(const string& nom, int x, int y)
: nom(nom), x(x), y(y) {
   // this->nom = "nouveau";  // pas possible car const
   cout << "constructeur avec paramètre ..." << endl;
}

//----------------------------------------------------
Point::Point(const Point& point) : nom(point.nom) {
   // this->nom   = point.nom;       // <= pas possible car const
   this->x     = point.x;
   this->y     = point.y;
   cout << "constructeur de copie..." << endl;
}

   //----------------------------------------------------
   Point& Point::operator=(const Point& point) {
//      this->nom   = point.nom;    // <= pas possible car const
      this->x     = point.x;
      this->y     = point.y;
      cout << "operateur d'affectation ..." << endl;
      return *this;
   }

//----------------------------------------------------
// destructeur
//----------------------------------------------------
Point::~Point () {
   cout << "destructeur ..." << endl;
}

//----------------------------------------------------
// methode afficher
//----------------------------------------------------
void Point::afficher() const {
   cout << "nom : " << this->nom
        << "(" << this->x << ", " << this->y << ")" << endl;
}
