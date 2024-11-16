#ifndef Carte_HPP
#define Carte_HPP

#include <iostream> 
#include <tuple> 

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

        Carte(){}
        Carte(std::string nom , int prix); 
        Carte(const Carte& c); 
        
        virtual ~Carte(); 

        virtual int getPrix(); 
        virtual std::string getNom(); 

        virtual void setPrix(int prix); 
        virtual void setNom(std::string nom);  

        virtual TypeCarte getType();  
        virtual void afficheCarte(); 
   

}; 



#endif