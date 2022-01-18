//---------------------------------------------------------
// Demo           : 07_constructor
// Fichier        : main.cpp
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer les bases des constructeurs
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <vector>       // classe vector

#include "Point.hpp"

using namespace std;

//---------------------------------------------------------------------
// classe simple pour default, explicite et delete
//---------------------------------------------------------------------
class A {
public:
            A() = default;             // créé par le compilateur
            A(char p) {c= p;  i=0;}
   explicit A(int  p) {c='a'; i=p;}    // => pas possible: A a = {1};
   void afficher() const;
private:
   char c;
   int  i;
};

void A::afficher() const {
   cout << "   c : " << c  << endl;
   cout << "   i : " << i  << endl;
}

//---------------------------------------------------------------------
int main() {
   {
      cout << "----------------------------" << endl;
      cout << "classe A "                    << endl;
      cout << "----------------------------" << endl;
      A a1;
      A a2('a');

   }

   {
      cout << "----------------------------" << endl;
      cout << "constructeur sans paramètre " << endl;
      cout << "----------------------------" << endl;
      Point point;
      point.afficher();
      cout << endl;

      //      constructeur sans paramètre ...
      //      nom : defaut(0, 0)
   }
   //      destructeur ...

   {
      cout << "----------------------------" << endl;
      cout << "constructeur avec paramètres"  << endl;
      cout << "----------------------------" << endl;
      Point point("point");
      point.afficher();
      cout << endl;

      //      constructeur avec paramètre ...
      //      nom : point(0, 0)
   }
   //      destructeur ...

   {
      cout << "----------------------------" << endl;
      cout << "constructeur de copie"        << endl;
      cout << "----------------------------" << endl;
      Point p1("p1", 2, 3);
      Point point(p1);
      point.afficher();
      cout << endl;

      //      constructeur avec paramètre ...
      //      constructeur de copie...
      //      nom : p1(2, 3)
   }
   //      destructeur ...
   //      destructeur ...

   {
      cout << "----------------------------" << endl;
      cout << "operateur d'affectation"     << endl;
      cout << "----------------------------" << endl;
      Point p1("p1", 2, 3);
      p1.afficher();
      
      Point p2 = p1;
      p2.afficher();

      Point point = Point();
      p1 = p1 = point;
      p1.afficher();
      cout << endl;

      //      constructeur avec paramètre ...
      //      nom : p1(2, 3)
      //      constructeur de copie...
      //      nom : p1(2, 3)
      //      constructeur sans paramètre ...
      //      operateur d'affectation ...
      //      operateur d'affectation ...
      //      nom : p1(0, 0)
   }
   //      destructeur ...
   //      destructeur ...
   //      destructeur ...

   {
      cout << "----------------------------" << endl;
      cout << "constructeur (init uniform)"  << endl;
      cout << "----------------------------" << endl;
      Point p1{"p1", 1, 3};
      p1.afficher();
      Point p2 = {"p2", 2, 4};
      p2.afficher();
      Point p3 (Point{"p3", 3, 5});
      p3.afficher();
      cout << endl;

      //      constructeur avec paramètre ...
      //      nom : p1(1, 3)
      //      constructeur avec paramètre ...
      //      nom : p2(2, 4)
      //      constructeur avec paramètre ...
      //      nom : p3(3, 5)
   }
   //      destructeur ...
   //      destructeur ...
   //      destructeur ...

   {
      cout << "----------------------------" << endl;
      cout << "vecteur de points"            << endl;
      cout << "----------------------------" << endl;
      vector<Point> v1(3);
      cout << endl;
      vector<Point> v2(3, Point("v", 2, 3));
      for (const Point& p : v2)
         p.afficher();
      //      constructeur sans paramètre ...
      //      constructeur sans paramètre ...
      //      constructeur sans paramètre ...
      //
      //      constructeur avec paramètre ...
      //      constructeur de copie...
      //      constructeur de copie...
      //      constructeur de copie...
      //      destructeur ...
      //      nom : v(2, 3)
      //      nom : v(2, 3)
      //      nom : v(2, 3)
   }
   cout << endl;
   cout << "combien de destructeurs appelés ??" << endl;
   cout << endl;

   //   destructeur ...
   //   destructeur ...
   //   destructeur ...
   //   destructeur ...
   //   destructeur ...
   //   destructeur ...
   //
   //   combien de destructeurs appelés ??

   return EXIT_SUCCESS;
}
