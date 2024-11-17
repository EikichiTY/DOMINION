#ifndef CarteVictoire_HPP
#define CarteVictoire_HPP
#include "Carte.hpp"


class CarteVictoire : public Carte {
    protected: 
        int point; 
         
    public : 
        static const std::vector<std::tuple<std::string,int,int>> listeCarteVictoire ;
        CarteVictoire();
        CarteVictoire(const CarteVictoire& c); 
        CarteVictoire(std::string nom); 

        ~CarteVictoire(); 
        int getPoint(); 
        void setPoint(); 

};


#endif