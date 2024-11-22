#ifndef Jeu_HPP
#define Jeu_HPP

#include <iostream> 
#include <vector> 
#include <map>
#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Carte.hpp"
#include "CarteRoyaume.hpp"
#include "CarteVictoire.hpp"
#include "CarteTresors.hpp"

class Jeu {
    private: 
        bool finJeu; 
        Plateau plateau; 
        std::vector<Joueur> listeJoueurs; 

    public : 
        Jeu();  
        ~Jeu();
        
        void jouerPartie(); 
        void toursJoueur(Joueur j); //tours d'un seul joueur
        void finPartie(); //verifie si la partie est fini grace aux deux conditions donnees 
        
        void ajouterJoueur(); //ajoute les 2 joueurs a la partie
        std::vector<Joueur> getListeJoueurs(); //retourne la liste des joueurs

        //3 phases du tours 
        void phaseJeu(Joueur& j, std::vector<CarteRoyaume*> carteJouer); 
        void phaseAchat(Joueur& j, std::vector<CarteTresors*> carteAchat);
        void phaseAjustement(Joueur& j);

};

#endif