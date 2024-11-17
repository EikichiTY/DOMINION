#ifndef Deck_HPP
#define Deck_HPP

#include <iostream> 
#include <vector> 
#include <map>
#include "Carte.hpp"
#include "CarteTresors.hpp"
#include "CarteVictoire.hpp"


class Deck{ 
    private : 
        std::vector <Carte*> main; 
        std::vector <Carte*> pioche; 
        std::vector <Carte*> defausse; 

        int nbPoint; 
        int nbPiece; 

    public : 
        Deck(); 
        ~Deck();

        void piocherCarte();  
        void acheterCarte(Carte* c);
        void initMain(); 
        void ajouteDefausse(Carte* c); 
        void melangerPioche(); 
        void deckFinPartie(); //stocke toutes les cartes dans la defausse pour compter le nombre de points 

        int getNbPiece(); 
        int getNbPoint(); 
        std::vector<Carte*> getMain(); 
        std::vector<Carte*> getPioche(); 
        std::vector<Carte*> getDefausse(); 
        
}; 


#endif