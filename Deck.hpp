#ifndef Deck_HPP
#define Deck_HPP

#include <iostream> 
#include <vector> 
#include <map>
#include "Carte.hpp"

class Deck{ 
    private : 
        std::vector <Carte*> main; 
        std::vector <Carte*> pioche; 
        std::vector <Carte*> defausse; 

        int nbPoint; 
        int nbPiece; 

    public : 
        void piocherCarte(); 
        void ajouteDefausse(Carte*); 
        void melangerDeck(); 
        int getNbPiece(); 
        int getNbPoint(); 


}; 


#endif