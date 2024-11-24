#ifndef CarteRoyaume_HPP
#define CarteRoyaume_HPP
#include "Carte.hpp"
#include <iostream> 
#include <limits>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Deck.hpp"


class Joueur; // pour eviter les les inclusion circulaire 
class Plateau; 
class CarteRoyaume : public Carte {
    protected: 
        bool attaque; 
        bool reaction; 
        
    public : 
        
        static const std::vector<std::tuple<std::string,int,bool,bool>> listeCarteRoyaume; 
        //permet de definir la structure de toutes les cartes royaume utilisable dans la partie 
        //carteRoyaume = <nom,prix,attaque,reaction>

        CarteRoyaume(); 
        CarteRoyaume(std::string nom); 
        CarteRoyaume(const CarteRoyaume& c); 
        ~CarteRoyaume(); 
        
        bool estAttaque(); 
        bool estReaction(); 
                    
        void action(Joueur& joueur, Plateau& plateau, std::vector<Joueur>& listeJoueurs); 

        void actionAtelier(Joueur& joueur, Plateau& plateau);
        void actionBucheron(Joueur& joueur); 
        void actionChapelle(Joueur& joueur); 
        void actionDouve(Joueur& joueurActuel); 
        void actionFestin(Plateau& plateau, Joueur& joueur); 
        void actionLaboratoire(Joueur& joueur); 
        void actionSorciere(Joueur& joueurActuel, std::vector<Joueur>& autresJoueurs, Plateau& plateau); 
        void actionVillage(Joueur& joueur); 
        void actionVoleur(Joueur& joueurActif, std::vector<Joueur>& listeJoueurs);
        bool douveDansMain(Joueur joueur);
};

#endif