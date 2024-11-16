#ifndef CarteRoyaume_HPP
#define CarteRoyaume_HPP
#include "Carte.hpp"
#include <iostream> 


class CarteRoyaume : public Carte {
    protected: 
        bool attaque; 
        bool reaction; 
        static std::vector<std::tuple<std::string,int,bool,bool>> cartePossiblesRoyaume; //permet de definir la structure de toutes les cartes utilisable dans la partie 
    
    public : 
        
        CarteRoyaume(); 
        CarteRoyaume(std::string nom); 
        CarteRoyaume(const CarteRoyaume& c); 
        ~CarteRoyaume(); 
        
        int getValeur(); 
        std::string getTypeRoyaume(); 

        bool estAttaque(); 
        bool estReaction(); 
         
        void action(); 
        void actionAtelier(); 
        void actionBucheron(); 
        void actionChapelle(); 
        void actionDouve(); 
        void actionFestin(); 
        void actionLaboratoire(); 
        void actionSorciere(); 
        void actionVillage(); 
        void actionVoleur();
    

    std::vector<std::tuple<std::string, int, bool, bool>> CarteRoyaume::cartesPossiblesRoyaume = {
    {"Atelier",3,false,false},
    {"Bucheron",3,false,false},
    {"Chapelle",2,false,false},
    {"Douve",2,false,true},
    {"Festin",4,false,false},
    {"Laboratoire",5,false,false},
    {"Sorciere",5,true,false},
    {"Village",3,false,false},
    {"Voleur",4,true,false},
    {"Jardins",4,false,false}
    
    }; 


};






// on peut faire toute les fonction ici pour les differentes classes, puis on appelle la fonction qui correspond au type de la carte royaume dans la methiode action
// On utilise un enum pour le type de roayaume (Voleur, Douve, ...)
//(donc on se debarasse de toutes les sous classes). Si t as pas compris je t expliquerais des que tu reviens. 
#endif