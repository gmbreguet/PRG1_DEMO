//---------------------------------------------------------
// Demo           : 07_constructor
// Fichier        : Point.h
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer les bases des constructeurs
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <string>

//---------------------------------------------------------------------
class Point {
public:
   
   //----------------------------------------------------
   // constructeurs
   //----------------------------------------------------
   Point();
   Point(const std::string& nom, int x=0, int y=0);
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
   const std::string nom;
   int x = 0;
   int y = 0;
};
