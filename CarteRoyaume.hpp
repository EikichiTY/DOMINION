#ifndef CarteRoyaume_HPP
#define CarteRoyaume_HPP
#include "Carte.hpp"
#include <iostream> 

class CarteRoyaume : public Carte {
    protected: 
        bool attaque; 
        bool reaction; 
    
    public : 
        int getValeur(); 
        void jouer(); 
        bool estAttaque(); 
        bool estReaction(); 
        std::string obtenirType();  

};


#endif