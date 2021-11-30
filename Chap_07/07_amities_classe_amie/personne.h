#ifndef Personne_H
#define Personne_H

#include <string>
#include "date.h"


class Personne {
   enum class Sexe {HOMME, FEMME};
   public:
      Personne (const std::string& nom,
                const Date&        date,
                const Sexe&        sexe);
      void afficher() const;
   
   private:
      std::string nom;
      Date        naissance;
      Sexe        sexe;
};

#endif
