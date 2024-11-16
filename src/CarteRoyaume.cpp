#include "CarteRoyaume.hpp"
#include <iostream> 
#include <vector> 


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