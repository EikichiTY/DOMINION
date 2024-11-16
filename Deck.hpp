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
        Deck(); 
        ~Deck();

        void piocherCarte(); 
        void ajouteDefausse(Carte* c); 
        void melangerDeck(); 
        int getNbPiece(); 
        int getNbPoint(); 
        std::vector<Carte*> getMain(); 
        std::vector<Carte*> getPioche(); 
        std::vector<Carte*> getDefausse(); 
        


}; 


#endif