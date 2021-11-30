#ifndef CLASSE
#define CLASSE

//---------------------------------------------------------------------
class Classe {
public:
   
   Classe(int valeur);
   ~Classe();
   
   void afficherObj() const;     // méthode
   static void afficherStat();   // méthode statique

private:
   const int         NO_OBJ;
         int         valeur;

   static const int  CONST_STAT;
   static       int  total;
   static       int  next;
};

#endif
