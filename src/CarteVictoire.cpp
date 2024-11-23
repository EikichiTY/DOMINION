#include "CarteVictoire.hpp"
#include <vector> 


const std::vector<std::tuple<std::string, int, int>> CarteVictoire::listeCarteVictoire = {
    {"Domaine", 2, 1},
    {"Duche",5,3},
    {"Province", 8, 6},
    {"Malediction", 0, -1},
    {"Jardins",4,0}
};

CarteVictoire::CarteVictoire() : Carte(), point(0){}

CarteVictoire::~CarteVictoire(){}

CarteVictoire::CarteVictoire(std::string nom){
    std::tuple<std::string,int,int> newCarte; 
    for(auto carte : listeCarteVictoire){
        if(std::get<0>(carte) == nom){
            newCarte = carte; 
        }
    }
    
    this->nom = std::get<0>(newCarte); 
    this->prix = std::get<1>(newCarte);
    this->point = std::get<2>(newCarte);
    this->typeCarte = TypeCarte::VICTOIRE; 
}

int CarteVictoire::getPoint(){
    return this->point;
}
