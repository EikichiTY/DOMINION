#include "CarteTresors.hpp"
#include <vector>

CarteTresors::CarteTresors(std::string nom){
    std::tuple<std::string,int,int> newCarte; 
    for(auto carte : cartePossiblesTresors){
        if(std::get<0>(carte) == nom){
            newCarte = carte; 
        }
    }
    
    this->nom = std::get<0>(newCarte); 
    this->prix = std::get<1>(newCarte);
    this->valeur = std::get<2>(newCarte); 
}

CarteTresors::CarteTresors(const CarteTresors& c){
    this->nom = c.nom; 
    this->prix = prix; 
    this->valeur = c.valeur; 
}