#include "Plateau.hpp"
#include <iostream> 


Plateau::Plateau(){}

Plateau::~Plateau(){}

void Plateau::initialiser(){
    cartePlateau.insert({new CarteTresors("Cuivre"),60}); 
    cartePlateau.insert({new CarteTresors("Argent"), 40}); 
    cartePlateau.insert({new CarteTresors("Or"), 30}); 
    cartePlateau.insert({new CarteVictoire("Domaine"), 24});
    cartePlateau.insert({new CarteVictoire("Duche"), 12}); 
    cartePlateau.insert({new CarteVictoire("Province"),8}); 
    cartePlateau.insert({new CarteVictoire("Malediction"),30}); 
    cartePlateau.insert({new CarteRoyaume("Atelier"),10}); 
    cartePlateau.insert({new CarteRoyaume("Bucheron"),10}); 
    cartePlateau.insert({new CarteRoyaume("Laboratoire"),10}); 
    cartePlateau.insert({new CarteRoyaume("Festin"),10}); 
    cartePlateau.insert({new CarteRoyaume("Sorciere"),10}); 
    cartePlateau.insert({new CarteRoyaume("Douve"),10}); 
    cartePlateau.insert({new CarteRoyaume("Voleur"),10}); 
    cartePlateau.insert({new CarteRoyaume("Village"),10}); 
    cartePlateau.insert({new CarteRoyaume("Jardins"),10}); 
    cartePlateau.insert({new CarteRoyaume("Chapelle"),10}); 
}

void Plateau::retirerCarte(Carte* c){
    for(auto carte : cartePlateau){
        if(carte.first == c){
            cartePlateau[c] -= 1 ; 
            if (carte.second == 0){
                setCarteEpuise(1); 
            }  
        }
    }
}

void Plateau::setCarteEpuise(int nb){
    this->nbCarteEpuise += nb; 
}

void Plateau::afficher(){
    std::cout<<"-------------------------------------------------\n"; 
    std::cout<<"Carte Disponibles a l'achat : \n";
    int index = 0; 
    for (auto carte : cartePlateau){
        std::cout<<index<<" | Carte : "<<carte.first->getNom()<<" | Prix : "<<carte.first->getPrix()<<" | Disponibilites : "<<carte.second<<"\n";
        index++; 
    }
    std::cout<<"-------------------------------------------------\n"; 
}

int Plateau::getCarteEpuise(){
    return this->nbCarteEpuise;
}

const std::map<Carte*, int>& Plateau::getCartePlateau() const {
    return cartePlateau;
}


