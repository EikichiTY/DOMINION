#include "CarteRoyaume.hpp"
#include <iostream> 
#include <vector> 
#include <tuple> 

const std::vector<std::tuple<std::string,int,bool,bool>> CarteRoyaume::listeCarteRoyaume = {
    {"Atelier",3,false,false},
    {"Bucheron",3,false,false},
    {"Chapelle",2,false,false},
    {"Douve",2,false,true},
    {"Festin",4,false,false},
    {"Laboratoire",5,false,false},
    {"Sorciere",5,true,false},
    {"Village",3,false,false},
    {"Voleur",4,true,false},
    {"Jardins",4,false,false}
};


CarteRoyaume::CarteRoyaume() : Carte(), attaque(false), reaction(false){}

CarteRoyaume::CarteRoyaume(std::string nom){
    std::tuple<std::string,int,bool,bool> newCarte; 
    for(auto carte : listeCarteRoyaume){
        if(std::get<0>(carte) == nom){
            newCarte = carte; 
        }
    }
    
    this->nom = std::get<0>(newCarte); 
    this->prix = std::get<1>(newCarte);
    this->attaque = std::get<2>(newCarte); 
    this->reaction = std::get<3>(newCarte); 
    this->typeCarte = TypeCarte::ROYAUME;
}


CarteRoyaume::CarteRoyaume(const CarteRoyaume& c){
    this->nom = c.nom; 
    this->prix = c.prix; 
    this->attaque = c.attaque; 
    this->reaction = c.reaction; 
    this->typeCarte = TypeCarte::ROYAUME;
}

CarteRoyaume::~CarteRoyaume(){}


bool CarteRoyaume::estAttaque(){
    return this->attaque; 
} 

bool CarteRoyaume::estReaction(){
    return this->reaction; 
}


void CarteRoyaume::actionAtelier(){
    //
}

void CarteRoyaume::actionBucheron(){
    //+2 pieces +1 achat 
}

void CarteRoyaume::actionChapelle(){
    //
}

void CarteRoyaume::actionDouve(){
    //pioche 2 cartes supplementaires + protege carte jouee par un adversere
}

void CarteRoyaume::actionFestin(){

}

void CarteRoyaume::actionLaboratoire(){

}

void CarteRoyaume::actionSorciere(){

}

void CarteRoyaume::actionVillage(){
    //"Piochez une carte et obtenez 2 actions supplémentaires."
}

void CarteRoyaume::actionVoleur(){
    
}