#ifndef Joueur_HPP
#define Joeuur_HPP 
#include "Deck.hpp"


class Joueur {
    private : 
        std::string nom;
        int score; 
        int nbAchat; 
        int nbActions; 
        Deck deck;

    public :
    // Constructeur 
     Joueur(const std::string& nom );
    // Methode
    std::string getNom() const;
    int getScore() const;
    void setScore(int nvScore);
    int calculerPoint(); 
    void jouerCarte();

}; 

#endif 