#include "Joueur.hpp"

Joueur::Joueur(){}

Joueur::Joueur(const std::string& nom) : nom(nom), score(0), nbAchat(0), nbAction(0) {
    deck = Deck(); 
    deck.initMain();
}

std::string Joueur::getNom() const {
    return nom;
}

int Joueur::getScore() const {
    return score;
}

int Joueur::getNbPiece() {
    return deck.getNbPiece();
}

void Joueur::setScore(int nvScore) {
    score = nvScore;
}

void Joueur::afficherMain(){
    std::vector<Carte*> mainJoueur = getDeck().getMain();
    int index = 0; 
    std::cout<<"Votre main : \n";
    for(auto carte : mainJoueur){
        std::cout<<index<<" | Carte : "<<carte->getNom()<<"\t| Type : "<<carte->TypetoString()<<"\n";
        index ++; 
    }
    std::cout<<"\n";
}



void Joueur::acheterCarte(Carte* c){
    this->deck.ajouteDefausse(c); 
}

void Joueur::nouvelleMain(){
    this->deck.initMain();
}

void Joueur::defausserMain(){
    this->deck.mainToDefausse(); 
}

Deck& Joueur::getDeck() {
    return deck;
}

void Joueur::initMainDeck(){
    this->deck.initMain(); 
}

 bool peutPiocher() {
        return deck.peutPiocher();
    }void Joueur::setNbAchat(int nb){
    this->nbAchat += nb;
}

int Joueur::getNbAchat(){
    return this->nbAchat; 
}

void Joueur::setNbAction(int nb){
    this->nbAction += nb; 
}

int Joueur::getNbAction(){
    return this-> nbAction; 
}