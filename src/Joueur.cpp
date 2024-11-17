#include "Joueur.hpp"

Joueur::Joueur(const std::string& nom) : nom(nom), score(0), nbAchat(0), nbActions(0) {

}

std::string Joueur::getNom() const {
    return nom;
}

int Joueur::getScore() const {
    return score;
}

void Joueur::setScore(int nvScore) {
    score = nvScore;
}

void Joueur::afficherMain(){
    std::vector<Carte*> mainJoueur = this->getDeck().getMain();
    int index = 0; 
    std::cout<<"Votre main : \n\n";
    for(auto carte : mainJoueur){
        std::cout<<index<<" | Carte : "<<carte->getNom()<<" | Type : "<<carte->TypetoString()<<"\n";
        index ++; 
    }
    std::cout<<"\n";
}


void Joueur::jouerCarte(CarteRoyaume* c) {
    //c->action(); 
}

void Joueur::acheterCarte(Carte* c){
    this->deck.ajouteDefausse(c); 
}

void Joueur::nouvelleMain(){

}

Deck Joueur::getDeck() {
    return deck;
}



/* 
    std::vector<Carte*> main = j.getDeck().getMain(); 
    for (size_t i = 0; i < main.size(); i++){
        main.at(i)->afficheCarte(); 
    }

    std::string choix = j.choixAction(); */