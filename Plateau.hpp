#ifndef Plateau_HPP 
#define Plateau_HPP 
#include <iostream> 
#include <vector> 
#include <map> 
#include "Carte.hpp"


class Plateau {
    private: 
        std::vector<Carte> listeRoyaume;
        std::vector<Carte> listeTresors;
        std::vector<Carte> listeVictoire;

        std::map<std::string, int> cartePlateau; 
        int nbCarteEpuise; 
    
    public: 
        void initialiser(); 
        void afficher(); 
        
        
        void setCarteEpuise(int nb);
        int getCarteEpuise();
        
        std::vector<Carte> getListeRoyaume();  
        std::vector<Carte> getListeVictoire();  
        std::vector<Carte> getListeTresors();

        
        void retirerCarte(Carte c);   

}; 

#endif