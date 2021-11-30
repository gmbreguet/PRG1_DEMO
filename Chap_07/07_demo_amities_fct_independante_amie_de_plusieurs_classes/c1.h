#ifndef C1_H
#define C1_H

class C2;

class C1 {
   friend void afficher(const C1& c1, const C2& c2);
public:
   C1(int n = 0);
private:
   int n;
};

#endif