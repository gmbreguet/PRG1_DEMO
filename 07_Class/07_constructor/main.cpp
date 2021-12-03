#include <cstdlib>
#include <iostream>
#include <vector>       // classe vector

#include "Point.h"

using namespace std;

//---------------------------------------------------------------------
int main() {
   {
      cout << "----------------------------" << endl;
      cout << "constructeur sans paramètre " << endl;
      cout << "----------------------------" << endl;
      Point point;
      point.afficher();
   }

   {
      cout << "----------------------------" << endl;
      cout << "constructeur avec paramètres"  << endl;
      cout << "----------------------------" << endl;
      Point point("point");
      point.afficher();
   }
   
   {
      cout << "----------------------------" << endl;
      cout << "constructeur de copie"        << endl;
      cout << "----------------------------" << endl;
      Point p1("p1", 2, 3);
      Point point(p1);
      point.afficher();
   }
   
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
   }
   
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
   }

   {
      cout << "----------------------------" << endl;
      cout << "vecteur de points"            << endl;
      cout << "----------------------------" << endl;
      vector<Point> v1(3);
      cout << endl;
      vector<Point> v2(3, Point("v", 2, 3));
      for (const Point& p : v2)
         p.afficher();
   }
   cout << "combien de destructeurs appelés ??" << endl;

   return EXIT_SUCCESS;
}
