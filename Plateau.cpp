#include "Plateau.hpp"
#include <iostream> 

Plateau::Plateau(){}

Plateau::~Plateau(){}

void Plateau::initialiser(){
    cartePlateau.insert({"cuivre",60}); 
    cartePlateau.insert({"argent", 40}); 
    cartePlateau.insert({"or", 30}); 
    cartePlateau.insert({"domaine", 24});
    cartePlateau.insert({"duche", 12}); 
    cartePlateau.insert({"province",8}); 
    cartePlateau.insert({"malediction",30}); 

    for (auto carte : getListeRoyaume()){
        cartePlateau.insert({carte.getNom(),10});
    }

}

void Plateau::retirerCarte(Carte c){
    for( auto carte : cartePlateau){
        if(carte.first == c.getNom()){
            cartePlateau[c.getNom()] -= 1 ;  
        }
    }
}

int Plateau::getNbCarteEpuise(){

}