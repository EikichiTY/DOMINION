#include <iostream>
#include <algorithm>
#include "Deck.hpp"

Deck::Deck(){}
Deck::~Deck(){} 

void Deck::piocherCarte(){
    getMain().push_back(pioche.at(0));
}


void Deck::ajouteDefausse(Carte* c){
    this->defausse.push_back(c); 
}

void Deck::melangerDeck(){
    std::random_shuffle(this->pioche.begin(), this->pioche.end()); 
}

/*int Deck::getNbPiece(){
    
}*/

/*int Deck::getNbPoint(){
    nbPoint = 0 ;
    for (CarteTresors carte : main){
        if (carte.getType() == "Tresors"){ 
            nbPoint += carte.getValeur(); 
        }
    }
    return nbPoint; 
}*/

std::vector<Carte*> Deck::getMain(){
    return this->main; 
}

std::vector<Carte*> Deck::getPioche(){
    return this->pioche;
}

std::vector<Carte*> Deck::getDefausse(){
    return this->defausse; 
}

