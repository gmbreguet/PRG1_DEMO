// --------------------------------------------------------------
// But      : demontrer les differents cas des exceptions en C++
// Auteur   : GM Breguet
// Date     : 28 avril 2014
// --------------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

//-------------------------------------------------
void bizare () throw (char) {
   try {
      throw 3;
   }
   catch (...) {
      cout << "à moi ...";
   }
}

//-------------------------------------------------
void onExit1() {
   //   // pas possible car n'a pas de bloc catch associe directement
   //   try
   //   {
   //   }
   cout << "appel de exit no 1" << endl;
}

//-------------------------------------------------
void onExit2() {
   cout << "appel de exit no 2" << endl;
}
      
//-------------------------------------------------
void onTerminate() {
   cout << "appel de terminate";
   //   // pas possible car ne depend pas directement d'un try precedent
   //   catch (...)
   //   {
   //   }
}

//-------------------------------------------------
void onUnexpected () {
   cout << "appel de unexpected" << endl;
}

//-------------------------------------------------
// une fonction dont l'exception est specifiee dans le prototype
void uneFonction (const int& valeur) throw (int, char) {
   if (valeur > 0)
      throw valeur;
   
   try {
      // réservation ...
   }
   catch (bad_alloc& ba) {
      // traitement local du probleme
      throw "ERREUR_MEMOIRE";
   }
   
   throw 'a';     // /!\ cette exception n'etant pas prevue dans la spec
   //     elle ne sera pas traitee => unexpected !!! :(
   //     => ne pas mettre les exceptions dans les spec
}

//-------------------------------------------------
int saisie (const string& message,
            const string& erreur) {
   int valeur;
   do {
      cout << message;
      if (cin >> valeur)
         break;
      // gestion des erreurs
      else {
         // lecture d'une valeur
         cin.clear();               // gere les bit d'erreurs
         while (cin.get() != '\n'); // vider le buffer
         cout << erreur << endl;
      }
   } while (true);
   
   // vider le buffer
   while (getchar()!='\n');
   
   return valeur;
}

//-------------------------------------------------
int main () {
   //--------------------------
   // branchement des handlers
   //--------------------------
   // procedure appelee apres une sortie "exit"
   atexit(onExit1);                 // utilisation de onExit
   atexit(onExit2);                 // utilisation de onExit

   // procedure appelee lorsqu'une exception n'est pas traitee
   // et remonte jusqu'a l'OS
   set_terminate(onTerminate);      // utilisation de onTerminate

   // gestion des exceptions non prevues (spec de fonction avec "throw")
   set_unexpected (onUnexpected);

   // cette variable doit etre declaree en dessus des blocs try-catch
   // pour le cas ou le ptr sur valeur est leve en exception
   int valeur;

   
   //-------------------------------------------------
   try {
      int* myarray= new int[100]; //90000000000000 pour lever un bad_alloc
   }

   catch (bad_alloc& ba) {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
   }
   
   //-------------------------------------------------
   while (true) {
      //----------
      // BLOC TRY
      //----------
      try {
         // traitement des cas
         valeur = saisie("votre choix : ", "/!\\ erreur de saisie");
         switch (valeur) {
            // gestion des differents cas
            case 0: throw valeur;             // valeur entiere
            case 1: throw &valeur;            // ptr sur entier
            case 2: throw 'a';                // caractere
            case 3: throw "chaine";           // chaine de caracteres
            case 4: throw string("string");   // string
            case 5: throw true;               // boolean
            case 6: uneFonction(-1);          // exception non-prevue
            case 7: throw invalid_argument(string("line : ") + to_string(__LINE__) + "\n" +
                                           string("file : ") + __FILE__);
            default: return EXIT_SUCCESS;
         }
      } // try
      
      //------------
      // BLOC CATCH
      //------------

      //----------------------------------
      // traite exception avec des entiers
      // /!\ ne fonctionne qu'avec des "int", unsigned int est different !!!
      //     const n'a pas d'influence car utile pour la copie (parametre)
      catch (int valeur) {
         cout << "constante entiere : " << valeur << endl;
      }
      
      //----------------------------------
      // traite exception avec un ptr sur entier
      // /!\ un ptr sur un float est different !!!
      catch (const int* valeur) {
         cout << "ptr sur entier : " << *valeur << endl;
      }
      
      //----------------------------------
      // traite exception avec des caracteres
      // /!\ pas de conversion implicite avec des entiers
      catch (char car) {
         cout << "caractere : " << car << endl;
         try{
            throw 1.2;
         }
         catch(double v) {
            cout << "dans le catch car : " << v << endl;
         }
      }
      
      //----------------------------------
      // un traite exception avec les memes types peut aparaitre
      // mais seul le premier sera utilise
      catch (char car) {
         cout << "inutile : " << car << endl;
      }
      
      //----------------------------------
      // traite exception avec des chaines de caracteres
      // /!\ le "const" est IMPORTANT !!!!
      //     different d'un string
      catch (const char* chaine) {
         cout << "chaine1 : " << chaine << endl;
         //-----------------------------------------------
         // lever une exception dans un traite-exception
         try {
            try {
               throw;      // lever cette meme exception
            }
            catch(int val) {
               // ne rien faire
            }
         }

         //-----------------------------------------------
         catch (const char* chaine) {
            cout << "chaine2 : " << chaine << endl;
         }
      }

      //----------------------------------
      // traite exception avec des string
      catch (const string& chaine) {
         cout << "string : " << chaine << endl;
      }

      //----------------------------------
      // exception logic_error
      catch (const logic_error& e) {
         cout << "Exception received" <<endl
              << e.what() << endl;
      }


      // traite TOUTES les exceptions (restantes)
      // /!\ doit etre obligatoirement en DERNIERE position (heureusemenet!)
      // /!\ impossible de recuperer l'objet ici :(
      catch (...) {
         cout << "je prends tout ..." << endl;
      }
   }

   // fin de programme
   cout << "presser ENTER pour quitter";
   getchar();
   return EXIT_SUCCESS;
}
