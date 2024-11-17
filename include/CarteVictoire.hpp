#ifndef CarteVictoire_HPP
#define CarteVictoire_HPP
#include "Carte.hpp"


class CarteVictoire : public Carte {
    protected: 
        int point; 
         
    public : 
        static const std::vector<std::tuple<std::string,int,int>> listeCarteVictoire ;
        //permet de definir la structure de toutes les cartes utilisable dans la partie 
        //carteVictoire = <nom,prix,point>

        CarteVictoire();
        CarteVictoire(const CarteVictoire& c); 
        CarteVictoire(std::string nom); 

        ~CarteVictoire(); 
        int getPoint(); 
        void setPoint(); 

};


#endif