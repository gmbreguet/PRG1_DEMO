#ifndef VECTEURS_H
#define VECTEURS_H

#include <iostream>
using namespace std;

class Vecteur {
   friend ostream& operator <<(ostream& os, const Vecteur& v);
   friend istream& operator >>(istream& is, Vecteur& v);
   friend bool operator ==(const Vecteur& v1, const Vecteur& v2);
public:
   Vecteur(double x = 0., double y = 0.);
private:
   double x, y;
};

#endif