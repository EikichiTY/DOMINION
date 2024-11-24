#ifndef Carte_HPP
#define Carte_HPP

#include <iostream> 
#include <tuple> 
#include <vector>

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

        Carte();
        
        std::string typeToString(); 
        
        virtual ~Carte(); 

        int getPrix(); 
        std::string getNom(); 

        void setPrix(int prix); 
        void setNom(std::string nom);  

        TypeCarte getType();  
         
        void afficheCarte(); 
   
}; 

#endif