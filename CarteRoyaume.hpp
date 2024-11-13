#ifndef CarteRoyaume_HPP
#define CarteRoyaume_HPP
#include "Carte.hpp"
#include <iostream> 

class CarteRoyaume : public Carte {
    protected: 
        bool attaque; 
        bool reaction; 
    
    public : 
        int getValeur(); 
        void jouer(); 
        bool estAttaque(); 
        bool estReaction(); 
        std::string obtenirType();  

};

// on peut faire toute les fonction ici pour les differentes classes, puis on appelle la fonction qui correspond au type de la carte royaume dans la methiode action
// On utilise un enum pour le type de roayaume (Voleur, Douve, ...)
//(donc on se debarasse de toutes les sous classes). Si t as pas compris je t expliquerais des que tu reviens. 
#endif