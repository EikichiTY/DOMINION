#ifndef CarteTresors_HPP
#define CarteTresors_HPP
#include "Carte.hpp"

class CarteTresors : public Carte {
    protected: 
        int valeur; 
    

    public : 
        static const std::vector<std::tuple<std::string,int,int>> listeCarteTresors;
        //permet de definir la structure de toutes les cartes utilisable dans la partie 
        //carteTresors = <nom,prix,valeur>

        CarteTresors();
        CarteTresors(const CarteTresors& c); 
        CarteTresors(std::string nom); 

        ~CarteTresors(); 
        int getValeur(); 
        void jouer(); 
        std::string obtenirType();  

};


#endif