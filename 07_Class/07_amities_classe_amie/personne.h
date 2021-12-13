//---------------------------------------------------------
// Demo           : 07_amities_classe_amie
// Fichier        : personne.h
// Auteur(s)      : BREGUET Guy-Michel
// Date           : 2020-11-30
// But            : classe personne ...
//                  et utilisation de la clase date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef Personne_H
#define Personne_H

#include <string>
#include "date.h"


class Personne {
   public:
      enum class Sexe {HOMME, FEMME};
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
