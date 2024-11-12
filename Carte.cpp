#include <iostream> 
#include "Carte.hpp"

Carte::Carte(std::string nom, int prix){
    this->nom = nom; 
    this->prix = prix; 
}

Carte::~Carte(){}

void Carte::setPrix(int prix){
    this->prix = prix ; 
}

void Carte::setNom(std::string nom){
    this->nom = nom; 
}

int Carte::getPrix(){
    return this->prix; 
}

std::string Carte::getNom(){
    return this->nom; 
}