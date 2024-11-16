#include <iostream> 
#include "Carte.hpp"

Carte::Carte(std::string nom, int prix){
    this->nom = nom; 
    this->prix = prix; 
}

Carte::Carte(const Carte& c){
    this->nom = c.nom; 
    this->prix = c.prix; 
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

TypeCarte Carte::getType(){
    return this->typeCarte; 
}

void Carte::afficheCarte(){
    std::cout<<"+-----------+\n"; 
    std::cout<<"|   Carte   |\n";
    std::cout<<"    "<<this->getNom()<<"  \n";
    std::cout<<"+-----------+\n";
    std::cout<<"|   Type    |\n";
    std::cout<<"   "<<this->getType()<<"  \n";
    std::cout<<"|  Prix : "<<this->getPrix()<<" |\n";
    std::cout<<"|           |\n";
    std::cout<<"+-----------+\n";
}

