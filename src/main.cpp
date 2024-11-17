#include <iostream> 
#include "Carte.hpp"
#include "CarteTresors.hpp"
#include "CarteRoyaume.hpp"
#include "CarteVictoire.hpp"
#include "Jeu.hpp"

#include <vector> 

int main(){

    /*Carte c1 = Carte("voleur",3);
    std::cout<<"Hello \n";
    
    std::cout<<c1.getNom()<<std::endl ; 

    c1.afficheCarte(); */

    CarteTresors c1 = CarteTresors("Or"); 
    c1.afficheCarte(); 

    Jeu jeu;
    jeu.ajouterJoueur();
    return 0; 
}