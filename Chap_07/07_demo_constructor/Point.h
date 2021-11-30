#include <iostream>  // cout et cin
#include <string>
#include <vector>

using namespace std;

//---------------------------------------------------------------------
class Point {
public:
   
   //----------------------------------------------------
   // constructeurs
   //----------------------------------------------------
   Point();
   Point(const string& nom, int x=0, int y=0);
   Point(const Point& point);

   //----------------------------------------------------
   // operateur d'affectation
   //----------------------------------------------------
   Point& operator=(const Point& point);
   
   //----------------------------------------------------
   // destructeur
   //----------------------------------------------------
   ~Point ();
   
   //----------------------------------------------------
   // methode afficher
   //----------------------------------------------------
   void afficher() const;

private:
   const string nom;
   int x = 0;
   int y = 0;
};
