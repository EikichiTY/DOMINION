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
        void commenceTour(); 
        void termineTour(); 
        void prochainJoueur(); 

};

#endif