#include <iostream> 
#include "Carte.hpp"

Carte::Carte(){}
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

std::string Carte::typeToString() {
    switch (typeCarte) {
        case ROYAUME: return "Royaume";
        case TRESORS: return "Tresors";
        case VICTOIRE: return "Victoire";
        default: return "Inconnu";
    }
}

void Carte::afficheCarte(){
    std::cout<<"+-------------+\n"; 
    std::cout<<"|  Nom Carte  |\n";
    std::cout<<"     "<<this->getNom()<<"  \n";
    std::cout<<"+-------------+\n";
    std::cout<<"|    Type     |\n";
    std::cout<<"    "<<typeToString()<<" \n";
    std::cout<<"|             |\n";
    std::cout<<"|  Prix :  "<<this->getPrix()<<"  |\n";
    std::cout<<"+-------------+\n\n";

}

