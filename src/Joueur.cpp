#include "Joueur.hpp"

Joueur::Joueur(const std::string& nom) : nom(nom), score(0), nbAchat(0), nbActions(0) {}

std::string Joueur::getNom() const {
    return nom;
}

int Joueur::getScore() const {
    return score;
}

void Joueur::setScore(int nvScore) {
    score = nvScore;
}

int Joueur::calculerPoint() {
    
    return score;
}

void Joueur::jouerCarte() {

}

Deck Joueur::getDeck() {
    return deck;
}

std::string Joueur::choixAction() {
    return "Action choisie";
}