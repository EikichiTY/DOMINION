#include "CarteRoyaume.hpp"
#include <iostream> 


bool CarteRoyaume::estAttaque(){
    if (this->typeCarteRoyaume == VOLEUR || this->typeCarteRoyaume == SORCIERE|| this->typeCarteRoyaume == SORCIERE){
        return true;
    }
    return false; 
} 

bool CarteRoyaume::estReaction(){
    if (this->typeCarteRoyaume != DOUVE){
        return false; 
    }
    return true; 
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

}

void CarteRoyaume::actionVoleur(){
    
}