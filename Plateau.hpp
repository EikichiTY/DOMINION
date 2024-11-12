#ifndef Plateau_HPP 
#define Plateau_HPP 
#include <iostream> 
#include <vector> 
#include <map> 
#include "Carte.hpp"


class Plateau {
    private: 
        std::map<Carte, int> nbCarteRestant;
        int nbCarteEpuise; 
    
    public: 
        void initialiser(); 
        void afficher(); 
        void retirerCarte(Carte*); 
        int getNbCarteEpuise(); 

}; 

#endif