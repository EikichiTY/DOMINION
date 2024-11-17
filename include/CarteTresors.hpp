#ifndef CarteTresors_HPP
#define CarteTresors_HPP
#include "Carte.hpp"

class CarteTresors : public Carte {
    protected: 
        int valeur; 
    

    public : 
        static std::vector<std::tuple<std::string,int,int>> listeCarteTresors;
        CarteTresors();
        CarteTresors(const CarteTresors& c); 

        CarteTresors(std::string nom); 
        ~CarteTresors(); 
        int getValeur(); 
        void jouer(); 
        std::string obtenirType();  

};


#endif