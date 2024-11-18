#ifndef Joueur_HPP
#define Joeuur_HPP 
#include "Deck.hpp"
#include "Carte.hpp"
#include "CarteTresors.hpp"
#include "CarteRoyaume.hpp"
#include "CarteVictoire.hpp"

class Joueur {
    private : 
        std::string nom;
        int score; 
        int nbAchat; 
        int nbActions; 
        Deck deck;

    public :
     
    Joueur(const std::string& nom ); //on doit ajouter l initialisation du deck + initialisation de la main dans le deck
    
    std::string getNom() const;
    int getScore() const;
    void setScore(int nvScore);
    void afficherMain(); 

    void jouerCarte(CarteRoyaume* c);
    void acheterCarte(Carte* c); 
    void nouvelleMain(); 

    Deck getDeck(); 

}; 

#endif 