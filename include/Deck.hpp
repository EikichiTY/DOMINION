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
        bool peutPiocher(); //verifie s'il reste assez de cartes pour piocher 
        void piocherCarte(); //piocher une carte 
        void initMain(); //initialise la main (5 fois piocher)
        void ajouteDefausse(Carte* c); //ajoute une carte dans la defausse (ex:achat)
        void melangerPioche(); 
        
        void uniqueMaintoDefausse(Carte* c); //retire la carte c de la main et la met dans la defausse
        void defausseToPioche(); //deplace toute la defausse dans la pioche
        void mainToDefausse(); //defausse la main 
        void allToDefausse(); //stocke toutes les cartes dans la defausse pour compter le nombre de points 

        void retirerCarteJeu(Carte* c); //retire une carte de la main et la supprime 

        //getters 
        int getNbPiece(); //renvoie le nb de pieces dans une main
        int getNbPoint(); //renvoie le nb de points dans un deck
        std::vector<Carte*>& getMain(); 
        std::vector<Carte*>& getPioche(); 
        std::vector<Carte*>& getDefausse();

        void setNbPiece(); //modifie l'attribut nbPieces en fonction de la main 
        void addNbPiece(int nb); //ajoute / retire des pieces virtuelles 
        void afficheEtatDeck(); //renvoie le nb d'elements dans chaque vecteurs 
}; 


#endif