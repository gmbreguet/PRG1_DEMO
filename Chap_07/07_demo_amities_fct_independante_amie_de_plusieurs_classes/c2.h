#ifndef C2_H
#define C2_H

class C1;

class C2 {
   friend void afficher(const C1& c1, const C2& c2);
public:
   C2(double x = 0.0);
private:
   double x;
};

#endif

