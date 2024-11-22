#include <iostream> 
#include "Carte.hpp"
#include "CarteTresors.hpp"
#include "CarteRoyaume.hpp"
#include "CarteVictoire.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp" 
#include "Deck.hpp"

#include <vector> 

int main(){

    /*    
    CarteTresors c1 = CarteTresors("Or"); 
    CarteVictoire c2 = CarteVictoire("Domaine"); 
    
    c1.afficheCarte();
    c2.afficheCarte();  
    
    Plateau plateau; 
    plateau.initialiser(); 

    plateau.afficher(); 
    
    
    Deck deck;
    
    deck.afficheEtatDeck();
    deck.initMain();
    deck.afficheEtatDeck();
    deck.mainToDefausse();
    deck.afficheEtatDeck();

    deck.ajouteDefausse(new CarteRoyaume("Voleur"));
    deck.afficheEtatDeck();

    deck.initMain();
    deck.afficheEtatDeck();

    deck.mainToDefausse();
    deck.afficheEtatDeck();

    deck.initMain();
    deck.afficheEtatDeck();

    deck.mainToDefausse();
    deck.afficheEtatDeck();

    deck.initMain();
    deck.afficheEtatDeck();

    deck.mainToDefausse();
    deck.afficheEtatDeck();

    deck.initMain();
    deck.afficheEtatDeck();

    */
    

    Jeu jeu;
    jeu.ajouterJoueur(); 
    jeu.toursJoueur(jeu.getListeJoueurs().at(0)); 
    jeu.toursJoueur(jeu.getListeJoueurs().at(0));
    //jeu.jouerPartie();


    return 0; 
}