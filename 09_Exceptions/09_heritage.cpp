//---------------------------------------------------------
// Demo           : 09_Heritage
// Fichier        : 09_Heritage.cpp
// Version        : 02 - 2022-01-25 / GMB
// Auteur(s)      : BREGUET Guy-Michel
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
   void afficher() const;
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
// méthode afficher
void Point::afficher() const {
   cout << "(" << x << ", " << y << ")";
}

//-------------------------------------------------
// class PointCouleur
//-------------------------------------------------
class PointCouleur : public Point {
public:
   PointCouleur(int x, int y, short c);
   void afficher() const;
private:
   short c;
};

//-------------------------------------------------
// constructeur utilisant le constructeur de Point
PointCouleur::PointCouleur(int x, int y, short c)
: Point(x, y) {               // construction d'un point
   this->c = c;               // ajout de la couleur
}

//-------------------------------------------------
// méthode afficher utilisant la méthode Point::afficher
void PointCouleur::afficher() const {
   
   // utilisation de Point::afficher
   // the "this->" n'est pas obligatoire
   this->Point::afficher();
   
   // afficher la propriété restante de PointCouleur
   cout << " c:" << c;
}

//-------------------------------------------------
int main () {

   // -------------------------
   // objet de la classe mère
   Point p(1, 2);
   p.afficher();
   cout << endl;

   // -------------------------
   // objet de la classe derrivée
   PointCouleur pc(1, 2, 3);
   pc.afficher();
   cout << endl;

   return EXIT_SUCCESS;
}

// |-----------|-----------------|-----------------|-----------------|
// | Classe    |  Classe dérivée |  Classe dérivée |  Classe dérivée |
// | de base   |  Mode public    |  Mode private   |  Mode protected |
// |-----------|-----------------|-----------------|-----------------|
// | Public    |   Public        |   Private       |   Protected     |
// |-----------|-----------------|-----------------|-----------------|
// | Protected |   Protected     |   Private       |   Protected     |
// |-----------|-----------------|-----------------|-----------------|
// | Private   |   Non hérité    |   Non hérité    |   Non hérité    |
// |-----------|-----------------|-----------------|-----------------|

// Résultat
//    (1, 2)
//    (1, 2) c:3

