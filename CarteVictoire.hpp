#ifndef CarteVictoire_HPP
#define CarteVictoire_HPP
#include "Carte.hpp"

class CarteVictoire : public Carte {
    protected: 
        int point; 
    
    public : 
        int getPoint(); 
        void setPoint(); 

        

};


#endif