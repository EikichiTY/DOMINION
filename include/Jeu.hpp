#ifndef Jeu_HPP
#define Jeu_HPP

#include <iostream> 
#include <vector> 
#include <map>
#include "Plateau.hpp"
#include "Joueur.hpp"

class Jeu {
    private: 
        int tourJoueur; 
        bool finJeu; 
        Plateau plateau; 
        std::vector<Joueur> listeJoueurs; 

    public : 
        Jeu();  
        void commenceTour(Joueur j); 
        void termineTour(); 
        Joueur prochainJoueur(Joueur j); 
        void ajouterJoueur(); 
        std::vector<Joueur> getListeJoueurs(); 

};

#endif