#ifndef Joueur_HPP
#define Joueur_HPP 
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
        int nbAction; 
        Deck deck;

    public :
    Joueur(); 
    Joueur(const std::string& nom ); //on doit ajouter l initialisation du deck + initialisation de la main dans le deck
        
    std::string getNom() const;
    int getScore() const;
    void setScore(int nvScore);
    void afficherMain(); 

    void acheterCarte(Carte* c); 
    void nouvelleMain(); 
    void defausserMain();

    int getNbPiece(); 

    int getNbAchat(); 
    void setNbAchat(int nb); 

    int getNbAction(); 
    void setNbAction(int nb); 

    Deck& getDeck(); 
    void initMainDeck(); 
    bool peutPiocher();
    void piocherCarte();
    void ajouteDefausse(Carte* c);
    
}; 

#endif 