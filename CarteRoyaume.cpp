#include "CarteRoyaume.hpp"

bool CarteRoyaume::estAttaque(){
    if (this->type != DOUVE){
        return true;
    }
    return false; 
} 

bool CarteRoyaume::estReaction(){
    if (this->type != DOUVE){
        return false; 
    }
    return true; 
}


void CarteRoyaume::actionAtelier(){
    
}

void CarteRoyaume::actionBucheron(){}

void CarteRoyaume::actionChapelle(){}

void CarteRoyaume::actionDouve(){}

void CarteRoyaume::actionFestin(){}

void CarteRoyaume::actionLaboratoire(){}

void CarteRoyaume::actionSorciere(){}

void CarteRoyaume::actionVillage(){}

void CarteRoyaume::actionVoleur(){}