#ifndef CarteVictoire_HPP
#define CarteVictoire_HPP
#include "Carte.hpp"


class CarteVictoire : public Carte {
    protected: 
        int point; 
        static const std::vector<std::tuple<std::string,int,int>> cartePossiblesVictoire ;  
    public : 
        CarteVictoire(); 
        ~CarteVictoire(); 
        int getPoint(); 
        void setPoint(); 


    std::vector<std::tuple<std::string, int, int>> CarteVictoire::cartePossiblesVictoire = {
    {"Domaine", 2, 1},
    {"Duchesse",5,3},
    {"Province", 8, 6},
    {"Malediction", 0, -1}
    };

};


#endif