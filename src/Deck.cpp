#include <iostream>
#include <algorithm>
#include "Deck.hpp"


Deck::Deck(){
    
    for (int i = 0; i<7 ; i++){
        this->pioche.push_back(new CarteTresors("Cuivre"));
    }
    for (int i = 0; i<3; i++){
        this->pioche.push_back(new CarteVictoire("Domaine"));
    }
    melangerPioche(); 
    
}

Deck::~Deck(){} 

void Deck::piocherCarte(){
    main.push_back(pioche.at(pioche.size()));
    pioche.pop_back(); 
}


void Deck::ajouteDefausse(Carte* c){
    this->defausse.push_back(c); 
}

void Deck::melangerPioche(){
    std::random_shuffle(this->pioche.begin(), this->pioche.end()); 
}

void Deck::initMain(){
    /*if(pioche.size() < 5){    // cas ou il reste moins de 5 cartes dans pioche a faire 
   
    }*/

    for (int i = 0; i < 5 && !pioche.empty(); i++) {
        Carte* carte = pioche.back();
        main.push_back(carte);
        pioche.pop_back();
    }
}

int Deck::getNbPiece(){
    int nbPieces = 0; 
    for (auto carte : main){ 
        if (CarteTresors* carteTresor = dynamic_cast<CarteTresors*>(carte)) {
            nbPiece += carteTresor->getValeur();
        }    
    }
    return nbPieces;
}

void Deck::deckFinPartie(){   
    for (int i = main.size()-1; i >= 0 ; i--){
        ajouteDefausse(main.at(i)); 
        main.pop_back();
    }

    for (int i = pioche.size()-1; i >= 0 ; i--){
        ajouteDefausse(pioche.at(i)); 
        pioche.pop_back();
    }
}


int Deck::getNbPoint(){
    nbPoint = 0 ;
    for (auto carte : defausse){ 
        if (CarteVictoire* carteTresor = dynamic_cast<CarteVictoire*>(carte)) {
            nbPiece += carteTresor->getPoint();
        }    
    }
    return nbPoint; 
}

std::vector<Carte*> Deck::getMain(){
    return this->main; 
}

std::vector<Carte*> Deck::getPioche(){
    return this->pioche;
}

std::vector<Carte*> Deck::getDefausse(){
    return this->defausse; 
}

