#include "CarteTresors.hpp"
#include <vector>


const std::vector<std::tuple<std::string, int, int>> CarteTresors::listeCarteTresors = {
    {"Cuivre", 0, 1},
    {"Argent",3,2},
    {"Or", 6, 3}
};

CarteTresors::CarteTresors() : Carte(), valeur(0) {}

CarteTresors::CarteTresors(std::string nom){
    std::tuple<std::string,int,int> newCarte; 
    for(auto carte : listeCarteTresors){
        if(std::get<0>(carte) == nom){
            newCarte = carte; 
            break; 
        }
    }
    
    this->nom = std::get<0>(newCarte); 
    this->prix = std::get<1>(newCarte);
    this->valeur = std::get<2>(newCarte); 
    this->typeCarte = TypeCarte::TRESORS; 
}

CarteTresors::CarteTresors(const CarteTresors& c){
    this->nom = c.nom; 
    this->prix = prix; 
    this->valeur = c.valeur; 
    this->typeCarte = TypeCarte::TRESORS;
}

CarteTresors::~CarteTresors(){}

int CarteTresors::getValeur(){
    return this->valeur; 
}