#include "CarteRoyaume.hpp"
#include <iostream> 
#include <vector> 

CarteRoyaume::CarteRoyaume(){}

CarteRoyaume::CarteRoyaume(std::string nom){
    std::tuple<std::string,int,bool,bool> newCarte; 
    for(auto carte : cartePossiblesRoyaume){
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