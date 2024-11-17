#ifndef CarteRoyaume_HPP
#define CarteRoyaume_HPP
#include "Carte.hpp"
#include <iostream> 


class CarteRoyaume : public Carte {
    protected: 
        bool attaque; 
        bool reaction; 
        
    public : 
        
        static const std::vector<std::tuple<std::string,int,bool,bool>> listeCarteRoyaume; //permet de definir la structure de toutes les cartes utilisable dans la partie 
        CarteRoyaume(); 
        CarteRoyaume(std::string nom); 
        CarteRoyaume(const CarteRoyaume& c); 
        ~CarteRoyaume(); 
        
        int getValeur();  

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

};






// on peut faire toute les fonction ici pour les differentes classes, puis on appelle la fonction qui correspond au type de la carte royaume dans la methiode action
// On utilise un enum pour le type de roayaume (Voleur, Douve, ...)
//(donc on se debarasse de toutes les sous classes). Si t as pas compris je t expliquerais des que tu reviens. 
#endif