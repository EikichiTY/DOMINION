#include "Plateau.hpp"
#include <iostream> 


Plateau::Plateau(){}

Plateau::~Plateau(){}

std::vector<std::pair<Carte*, int>> Plateau::cartePlateau = {}; 
int Plateau::nbCarteEpuise = 0; 

void Plateau::initialiser(){
    cartePlateau.push_back({new CarteTresors("Cuivre"),60}); 
    cartePlateau.push_back({new CarteTresors("Argent"), 40}); 
    cartePlateau.push_back({new CarteTresors("Or\t"), 30}); 
    cartePlateau.push_back({new CarteVictoire("Domaine"), 24});
    cartePlateau.push_back({new CarteVictoire("Duche"), 12}); 
    cartePlateau.push_back({new CarteVictoire("Province"),8}); 
    cartePlateau.push_back({new CarteVictoire("Malediction"),30}); 
    cartePlateau.push_back({new CarteRoyaume("Atelier"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Bucheron"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Laboratoire"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Festin"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Sorciere"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Douve"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Voleur"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Village"),10}); 
    cartePlateau.push_back({new CarteVictoire("Jardins"),10}); 
    cartePlateau.push_back({new CarteRoyaume("Chapelle"),10}); 

    std::sort(cartePlateau.begin(), cartePlateau.end(),
        [](const std::pair<Carte*, int>& a, const std::pair<Carte*, int>& b) {
            return a.first->getPrix() < b.first->getPrix();
    });

    
}


void Plateau::retirerCarte(Carte* c){
    for(auto carte : cartePlateau){
        if(carte.first == c){
           carte.second -= 1 ; 
            if (carte.second == 0){
                setCarteEpuise(1); 
            }  
        }
    }
}

void Plateau::retirerCarte(int index){
    cartePlateau.at(index).second -= 1; 
    if (cartePlateau.at(index).second == 0){ 
        setCarteEpuise(1); 
        std::cout<<"La pile de cartes : "<<cartePlateau.at(index).first->getNom()<<" est epuisee !";
    }
}

void Plateau::setCarteEpuise(int nb){
    this->nbCarteEpuise += nb; 
}

void Plateau::afficher() {
    std::cout << "----------------------------------------\n";
    std::cout << "Carte Disponibles a l'achat : \n";
    
    int index = 0;
    for (auto carte : cartePlateau) {
        std::cout << index << "\t| Carte : " << carte.first->getNom() 
                 << " \t| Prix : " << carte.first->getPrix() 
                 << " \t| Disponibilites : " << carte.second << "\n";
        index++;
    }
    
    std::cout << "----------------------------------------\n";
}

int Plateau::getCarteEpuise(){
    return nbCarteEpuise;
}

bool Plateau::getProvinceEpuise(){
    for( auto carte : cartePlateau ){
        if (carte.first->getNom() == "Province"){
            if(carte.second == 0){
                return true; 
            }
        break;
        }
    }
    return false;
}

const std::vector<std::pair<Carte*, int>>& Plateau::getCartePlateau() const {
    return cartePlateau;
}


