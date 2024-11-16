#ifndef CarteVictoire_HPP
#define CarteVictoire_HPP
#include "Carte.hpp"

class CarteVictoire : public Carte {
    protected: 
        int point; 
    
    public : 
        CarteVictoire(); 
        ~CarteVictoire(); 
        int getPoint(); 
        void setPoint(); 

        

};


#endif