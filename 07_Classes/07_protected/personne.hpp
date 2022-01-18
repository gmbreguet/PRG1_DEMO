//---------------------------------------------------------
// Demo           : 07_protected
// Fichier        : personne.h
// Version        : 02 - 2020-09-18
// Auteur(s)      : BREGUET Guy-Michel
// But            : classe personne ...
//                  et utilisation de la clase date
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#ifndef Personne_H
#define Personne_H

#include <string>
#include "date.hpp"


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
