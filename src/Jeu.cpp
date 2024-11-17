#include <iostream>
#include "Jeu.hpp"

Jeu::Jeu(){}

void Jeu::commenceTour(Joueur j){
    
    j.jouerCarte(); 
    j.acheterCarte(); 
    j.nouvelleMain(); 
    
    /*std::cout<<"Choissez une carte a jouer : \n"; 

    std::vector<Carte*> main = j.getDeck().getMain(); 
    for (size_t i = 0; i < main.size(); i++){
        main.at(i)->afficheCarte(); 
    }

    std::string choix = j.choixAction();    */
}

/*Joueur Jeu::prochainJoueur(Joueur j*){ 
    for (auto joueur : listeJoueurs){
        if (joueur j ){break;} 
    }
    Joueur prochain = listeJoueurs.at(i+1); 
    return prochain; 
}*/

void Jeu::ajouterJoueur(){
    for (int i = 1; i <= 2; ++i) {
        std::string username;
        std::cout << "Entrez le nom du joueur " << i << ": ";
        std::cin >> username;
        listeJoueurs.push_back(Joueur(username));
    }

    std::cout << "Les usernames des 2 joueurs sont : " << std::endl;
    for (const auto& joueur : listeJoueurs) {
        std::cout << joueur.getNom() << std::endl;
    }

}

