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
        bool peutPiocher(); 
        void piocherCarte();  
        void initMain(); 
        void ajouteDefausse(Carte* c); 
        void melangerPioche(); 
        
        void defausseToPioche();
        void mainToDefausse();
        void allToDefausse(); //stocke toutes les cartes dans la defausse pour compter le nombre de points 

        void retirerCarteJeu(Carte* c); //retire une carte de la main et la supprime 

        //getters 
        int getNbPiece(); 
        int getNbPoint(); 
        std::vector<Carte*>& getMain(); 
        std::vector<Carte*>& getPioche(); 
        std::vector<Carte*>& getDefausse();

        void setNbPiece();
        void addNbPiece(int nb);
        void afficheEtatDeck(); //renvoie le nb d elements dans chaque vecteurs 
         
}; 


#endif