#include <cstdlib>
#include <iostream>

using namespace std;

//-------------------------------------------------------------------
enum class Chiffre {ZERO, UN,  DEUX, TROIS, QUATRE,
                    CINQ, SIX, SEPT, HUIT,  NEUF};

const string CHIFFRE[] = {"ZERO", "UN",  "DEUX", "TROIS", "QUATRE",
                          "CINQ", "SIX", "SEPT", "HUIT",  "NEUF"};

//-------------------------------------------------------------------
ostream& operator<<(ostream& os, const Chiffre& c);
Chiffre& operator++ (Chiffre& c);

//-------------------------------------------------------------------
int main() {
   for (Chiffre i=Chiffre::ZERO; i<=Chiffre::NEUF; ++i)
      cout << i << endl;
}

//-------------------------------------------------------------------
ostream& operator<<(ostream& os, const Chiffre& c) {
   os << CHIFFRE[size_t(c)];
   return os;
}

//-------------------------------------------------------------------
Chiffre& operator++ (Chiffre& c) {
   c = Chiffre( int(c) + 1 );
   return c;
}
