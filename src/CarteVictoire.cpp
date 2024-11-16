#include "CarteVictoire.hpp"
#include <vector> 

CarteVictoire::CarteVictoire(){}

CarteVictoire::CarteVictoire(std::string nom){
    std::tuple<std::string,int,int> newCarte; 
    for(auto carte : cartePossiblesVictoire){
        if(std::get<0>(carte) == nom){
            newCarte = carte; 
        }
    }
    
    this->nom = std::get<0>(newCarte); 
    this->prix = std::get<1>(newCarte);
    this->point = std::get<2>(newCarte);
    this->typeCarte = TypeCarte::VICTOIRE; 
}