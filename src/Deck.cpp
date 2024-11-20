#include <iostream>
#include <algorithm> // pour std::shuffle
#include <random>    // pour std::default_random_engine et std::random_device
#include <ctime> 
#include "Deck.hpp"


Deck::Deck(){
    this->pioche = {}; 
    this->defausse = {}; 
    this->main = {};
    for (int i = 0; i<7 ; i++){
        this->pioche.push_back(new CarteTresors("Cuivre"));
    }
    for (int i = 0; i<3; i++){
        this->pioche.push_back(new CarteVictoire("Domaine"));
    }
    this ->nbPiece = 0; 
    this ->nbPoint = 0;
    
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
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr))); // Graine basée sur le temps
    std::uniform_int_distribution<> dist(0, pioche.size() - 1); // Distribution uniforme

    // Mélange manuel
    for (std::size_t i = 0; i < pioche.size(); ++i) {
        int randomIndex = dist(gen); // Génère un index aléatoire
        std::swap(pioche[i], pioche[randomIndex]); // Échange les éléments
    }
}

void Deck::initMain(){
    if(pioche.size() < 5){    // cas ou il reste moins de 5 cartes dans pioche a faire 
        int cpt = 0; 
        for (int i = 0; i < pioche.size(); i++) {
            Carte* carte = pioche.back();
            main.push_back(carte);
            pioche.pop_back();
            cpt ++; 
        }  

        defausseToPioche();
        int nbCarte = 5 - cpt; 
        melangerPioche();
        for (int i = 0; i < nbCarte; i++) {
            Carte* carte = pioche.back();
            main.push_back(carte);
            pioche.pop_back(); 
        }  
    }

    else{

        melangerPioche();
        for (int i = 0; i < 5 && !pioche.empty(); i++) {
            Carte* carte = pioche.back();
            main.push_back(carte);
            pioche.pop_back();
        }
    }
    setNbPiece();
    
}

void Deck::defausseToPioche(){
    for (int i = defausse.size()-1 ; i >= 0; i--){
        pioche.push_back(defausse.at(i));
        defausse.pop_back(); 
    }
}

void Deck::mainToDefausse(){
    for(int i = main.size()-1 ; i >= 0; i--){
        defausse.push_back(main.at(i)); 
        main.pop_back(); 
    }
}


void Deck::allToDefausse(){   
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
    int nbPoint = 0 ;
    for (auto carte : defausse){ 
        if (CarteVictoire* carteVictoire = dynamic_cast<CarteVictoire*>(carte)) {
            nbPoint += carteVictoire->getPoint();
        }    
    }
    return nbPoint; 
}

int Deck::getNbPiece(){
    return this->nbPiece;
}


void Deck::setNbPiece(){
    this->nbPiece = 0; 
    for (auto carte : main){ 
        if (CarteTresors* carteTresor = dynamic_cast<CarteTresors*>(carte)) {
            nbPiece += carteTresor->getValeur();
        }    
    }
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

void Deck::afficheEtatDeck(){
    std::cout<<"Pioche : "<<pioche.size()<<" elements \n";
    std::cout<<"Main : "<<main.size()<<" elements \n";
    std::cout<<"Defausse : "<<defausse.size()<<" elements \n\n";
}

