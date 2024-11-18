#ifndef Plateau_HPP 
#define Plateau_HPP 
#include <iostream> 
#include <vector> 
#include <map> 
#include "Carte.hpp"
#include "CarteTresors.hpp"
#include "CarteRoyaume.hpp"
#include "CarteVictoire.hpp"


class Plateau {
    private: 
        std::map<Carte*, int> cartePlateau; 
        int nbCarteEpuise; 
      
    public: 
        Plateau(); 
        ~Plateau(); 
        void initialiser(); 
        void afficher(); 
        
        void setCarteEpuise(int nb);
        int getCarteEpuise();
        const std::map<Carte*, int>& getCartePlateau() const;

        
        void retirerCarte(Carte* c);   

}; 

#endif