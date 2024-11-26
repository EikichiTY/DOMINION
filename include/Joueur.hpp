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
        Joueur(const std::string& nom ); 
            
        std::string getNom() const;
        int getScore() const;
        
        void setScore(int nvScore);
        void afficherMain(); //afficher la main d un joueur

        int getNbPiece(); //renvoie le nb de pieces du deck (main)
        int getNbAchat(); //renvoie attribut nbAchat
        int getNbAction(); //renvoie attribut nbAction

        void setNbAchat(int nb); //incremente l'attribut nbAchat
        void addNbPiece(int nb); //ajoute pieces virtuelles 
        void setNbAction(int nb); //incremente nbAction

        Deck& getDeck(); //renvoie le deck du joueur
        
        //appel methode dans deck
        void initMainDeck(); 
        bool peutPiocher(); 
        void piocherCarte();
        void ajouteDefausse(Carte* c);
        void nouvelleMain(); 
        void defausserMain();     
}; 

#endif 