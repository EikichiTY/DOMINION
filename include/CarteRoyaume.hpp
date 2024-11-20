#ifndef CarteRoyaume_HPP
#define CarteRoyaume_HPP
#include "Carte.hpp"
#include <iostream> 
#include "Joueur.hpp"
#include "Plateau.hpp"


class Joueur; // pour eviter les les inclusion circulaire 
class Plateau; 
class CarteRoyaume : public Carte {
    protected: 
        bool attaque; 
        bool reaction; 
        
    public : 
        
        static const std::vector<std::tuple<std::string,int,bool,bool>> listeCarteRoyaume; 
        //permet de definir la structure de toutes les cartes utilisable dans la partie 
        //carteRoyaume = <nom,prix,attaque,reaction>

        CarteRoyaume(); 
        CarteRoyaume(std::string nom); 
        CarteRoyaume(const CarteRoyaume& c); 
        ~CarteRoyaume(); 
        
        int getValeur();  

        bool estAttaque(); 
        bool estReaction(); 
                    
        void action(); 
        void actionAtelier(Joueur& joueur, Plateau& plateau);

        void actionBucheron(); 
        void actionChapelle(Deck& deck); 
        void actionDouve(); 
        void actionFestin(Plateau& plateau , Deck& deck); 
        void actionLaboratoire(); 
        void actionSorciere(); 
        void actionVillage(); 
        void actionVoleur();
        void actionJardin();
        

};






// on peut faire toute les fonction ici pour les differentes classes, puis on appelle la fonction qui correspond au type de la carte royaume dans la methiode action
// On utilise un enum pour le type de roayaume (Voleur, Douve, ...)
//(donc on se debarasse de toutes les sous classes). Si t as pas compris je t expliquerais des que tu reviens. 
#endif