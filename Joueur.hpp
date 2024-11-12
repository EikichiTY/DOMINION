#ifndef Joueur_HPP
#define Joeuur_HPP 
#include "Deck.hpp"


class Joueur {
    private : 
        Deck deck; 
        int nbAchat; 
        int nbActions; 


    public : 
        int calculerPoint(); 
        void jouerCarte();

}; 

#endif 