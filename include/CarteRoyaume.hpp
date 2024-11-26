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
        
        bool estAttaque(); //renvoie attribut attaque
        bool estReaction(); //renvoie attribut reaction

        //appelle l'une des methodes ci dessous en fonction du nom de la carte            
        void action(Joueur& joueur, Plateau& plateau, std::vector<Joueur>& listeJoueurs); 

        //methode decrivant l'action de chaque carte royaume
        void actionAtelier(Joueur& joueur, Plateau& plateau); //Permet au joueur de gagner une carte coûtant jusqu'à 4 pièces et de l'ajouter directement à sa défausse.
        void actionBucheron(Joueur& joueur); //Permet au joueur de gagner 2 pièces et 1 achat supplémentaire pour ce tour.
        void actionChapelle(Joueur& joueur); //Permet au joueur de supprimer jusqu'à 4 cartes de sa main et pioche 4 carte 
        void actionDouve(Joueur& joueurActuel); //Permet au joueur de piocher 2 cartes lorsqu'elle est jouée. En plus, elle agit comme une carte de réaction 
        void actionFestin(Plateau& plateau, Joueur& joueur); //Permet au joueur de gagner une carte coûtant jusqu'à 5 pièces et de l'ajouter à sa défausse. La carte Festin est ensuite supprimée du jeu .
        void actionLaboratoire(Joueur& joueur); //Permet au joueur de piocher 2 cartes et de gagner 1 action supplémentaire.
        void actionSorciere(Joueur& joueurActuel, std::vector<Joueur>& autresJoueurs, Plateau& plateau); //Permet au joueur de piocher 2 cartes et oblige chaque autre joueur à prendre une carte Malédiction.
        void actionVillage(Joueur& joueur); //Permet au joueur de piocher 1 carte et de gagner 2 actions supplémentaires.
        void actionVoleur(Joueur& joueurActif, std::vector<Joueur>& listeJoueurs); // Permet au joueur de regarder les 2 premières cartes de la main de chaque adversaire. Si ce sont des cartes Trésor, il peut choisir d'en gagner une et éliminer l'autre.
        bool douveDansMain(Joueur joueur);
};

#endif