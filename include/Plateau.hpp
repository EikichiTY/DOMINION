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
        static std::vector<std::pair<Carte*, int>> cartePlateau; 
        static int nbCarteEpuise; 

        Plateau(); 
        ~Plateau(); 
        void initialiser(); 
        void ordonnerPlateau();
        void afficher(); 
        
        void setCarteEpuise(int nb);
        int getCarteEpuise();
        const std::vector<std::pair<Carte*, int>>& getCartePlateau() const;

        
        void retirerCarte(Carte* c);   

}; 

#endif