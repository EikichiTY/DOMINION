#ifndef Carte_HPP
#define Carte_HPP

#include <iostream> 

enum TypeCarte {
  ROYAUME, 
  TRESORS,
  VICTOIRE
};

class Carte {
    protected : 
        std::string nom ; 
        TypeCarte typeCarte; 
        int prix; 

    public : 

        Carte(std::string nom , int prix); 
        virtual ~Carte(); 

        virtual int getPrix(); 
        std::string getNom(); 

        void setPrix(int prix); 
        void setNom(std::string nom);  

        TypeCarte getType();  
        void afficheCarte(); 
        void action(); 

}; 



#endif