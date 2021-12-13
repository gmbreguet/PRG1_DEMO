#include <iostream>
#include <cstdlib>
#include "c1.h"
#include "c2.h"
using namespace std;

//--------------------------------------------------------
void afficher(const C1& c1, const C2& c2) {
   cout << "(" << c1.n << ", " << c2.x << ")\n";
}
 
//--------------------------------------------------------
int main() {
   C1 c1;
   C2 c2(1.0);
   afficher(c1, c2); // affichera (0, 1)

   return EXIT_SUCCESS;
}
