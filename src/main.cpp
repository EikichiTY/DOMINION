#include <iostream> 
#include "Carte.hpp"
#include "CarteTresors.hpp"
#include "CarteRoyaume.hpp"
#include "CarteVictoire.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp" 


#include <vector> 

int main(){

    /*    
    CarteTresors c1 = CarteTresors("Or"); 
    CarteVictoire c2 = CarteVictoire("Domaine"); 
    
    c1.afficheCarte();
    c2.afficheCarte();  
    */
    Plateau plateau; 
    plateau.initialiser(); 
    plateau.afficher(); 

    

    Jeu jeu;
    jeu.ajouterJoueur();
 
    jeu.commenceTour(jeu.getListeJoueurs().at(0));

    return 0; 
}