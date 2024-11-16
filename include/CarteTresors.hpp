#ifndef CarteTresors_HPP
#define CarteTresors_HPP
#include "Carte.hpp"

class CarteTresors : public Carte {
    protected: 
        int valeur; 
        static std::vector<std::tuple<std::string,int,int>> cartePossiblesTresors; 

    public : 
        CarteTresors();
        CarteTresors(std::string nom); 
        ~CarteTresors(); 
        int getValeur(); 
        void jouer(); 
        std::string obtenirType();  

    std::vector<std::tuple<std::string, int, int>> CarteTresors::cartePossiblesTresors = {
    {"Cuivre", 0, 1},
    {"Argent",3,2},
    {"Or", 6, 3},
    };

};


#endif