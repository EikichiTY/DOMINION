#include <iostream>
#include "Jeu.hpp"

void Jeu::commenceTour(Joueur j){
    std::cout<<"Choissez une carte a jouer : \n"; 

    std::vector<Carte*> main = j.getDeck().getMain(); 
    for (int i = 0; i < main.size(); i++){
        main.at(i)->afficheCarte(); 
    }

    std::string choix = j.choixAction();    
}

Joueur Jeu::prochainJoueur(Joueur j*){ 
    for (Joueur i in listeJoueurs){
        if (i == j){break;} 
    }
    Joueur prochain = listeJoueurs.at(i+1); 
    return prochain; 
}


