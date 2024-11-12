#ifndef Carte_HPP
#define Carte_HPP

#include <iostream> 


class Carte {
    protected : 
        std::string nom ; 
        std::string type; 
        int prix; 

    public : 

        Carte(std::string nom , int prix); 
        ~Carte(); 

        int getPrix(); 
        std::string getNom(); 

        void setPrix(int prix); 
        void setNom(std::string nom);  

        std::string obtenirType();  
        void action(); 

}; 



#endif