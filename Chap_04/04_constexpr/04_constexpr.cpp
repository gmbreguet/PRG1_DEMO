#include <cstdlib>
#include <iostream>
using namespace std;

          int f1(int valeur) { return valeur; }
constexpr int f2(int valeur) { return valeur; }

int main() {
             int var       = 2;
       const int CSTE      = 3;

   constexpr int CSTEX01   = 4;
// constexpr int CSTEX02   = var;
   constexpr int CSTEX03   = CSTE;
   constexpr int CSTEX04   = CSTEX01;

// constexpr int CSTEX11   = f1(2);
// constexpr int CSTEX12   = f1(var);
// constexpr int CSTEX13   = f1(CSTE);
// constexpr int CSTEX14   = f1(CSTEX01);

   constexpr int CSTEX21   = f2(2);
// constexpr int CSTEX22   = f2(var);
   constexpr int CSTEX23   = f2(CSTE);
   constexpr int CSTEX24   = f2(CSTEX01);

   cout << endl;
   return EXIT_SUCCESS;
}
