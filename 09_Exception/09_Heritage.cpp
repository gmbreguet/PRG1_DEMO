//---------------------------------------------------------
// Demo           : 09_Heritage
// Fichier        : 09_Heritage.cpp
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2021-12-13
// But            : démontrer un cas simple d'héritage
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

//-------------------------------------------------
// class Point
//-------------------------------------------------
class Point {
public:
   Point(int x, int y);
   void affiche() const;
private:
   int x;
   int y;
};

//-------------------------------------------------
// constructeur
Point::Point(int x, int y) {
   this->x = x;
   this->y = y;
}

//-------------------------------------------------
// méthode affiche
void Point::affiche() const {
   cout << "(" << x << ", " << y << ")";
}

//-------------------------------------------------
// class PointCouleur
//-------------------------------------------------
class PointCouleur : public Point {
public:
   PointCouleur(int x, int y, short c);
   void affiche() const;
private:
   short c;
};

//-------------------------------------------------
// constructeur utilisant le constructeur de Point
PointCouleur::PointCouleur(int x, int y, short c)
: Point(x, y)                 // construction d'un point
{
   this->c = c;               // ajout de la couleur
}

//-------------------------------------------------
// méthode affiche utilisant la méthode Point::affiche
void PointCouleur::affiche() const {
   
   // utilisation de Point::affiche
   // the "this->" n'est pas obligatoire
   this->Point::affiche();
   
   // afficher la propriété restante de PointCouleur
   cout << " c:" << c;
}

//-------------------------------------------------
int main () {

   // -------------------------
   // objet de la classe mère
   Point p(1, 2);
   p.affiche();
   cout << endl;

   // -------------------------
   // objet de la classe derrivée
   PointCouleur pc(1, 2, 3);
   pc.affiche();
   cout << endl;

   return EXIT_SUCCESS;
}
