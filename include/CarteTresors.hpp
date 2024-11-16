#ifndef CarteTresors_HPP
#define CarteTresors_HPP
#include "Carte.hpp"

class CarteTresors : public Carte {
    protected: 
        int valeur; 
    
    public : 
        CarteTresors(); 
        ~CarteTresors(); 
        int getValeur(); 
        void jouer(); 
        std::string obtenirType();  

};


#endif