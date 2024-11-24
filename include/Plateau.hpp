#ifndef Plateau_HPP 
#define Plateau_HPP 
#include <iostream> 
#include <vector> 
#include <map>
#include <algorithm>

#include "Carte.hpp"
#include "CarteTresors.hpp"
#include "CarteRoyaume.hpp"
#include "CarteVictoire.hpp"


class Plateau {      
    public: 
        static std::vector<std::pair<Carte*, int>> cartePlateau;  //pair <carte, nb cartes restant> 
        static int nbCarteEpuise; //nb de piles de cartes épuisées

        Plateau(); 
        ~Plateau(); 
        void initialiser(); //initalise le plateau avec les differentes cartes et les differents nb de disponibilite
        void afficher(); //affiche le plateau 
        
        void setCarteEpuise(int nb); // incremente l'attribut nbCarteEpuise
        int getCarteEpuise(); //renvoie le nombre de piles de cartes épuisées
        bool getProvinceEpuise(); //renvoie vrai si les cartes provinces sont épuisées
        const std::vector<std::pair<Carte*, int>>& getCartePlateau() const; //renvoie le plateau 

        
        void retirerCarte(Carte* c);   //decremente le nb de carte disponible de la Carte c dans le plateau 
        void retirerCarte(int index);  //decremente le nb de carte disponible depuis l'index de position d'une carte dans le plateau
}; 

#endif