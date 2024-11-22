#include "CarteRoyaume.hpp"
#include <iostream> 
#include <vector> 
#include <tuple> 

const std::vector<std::tuple<std::string,int,bool,bool>> CarteRoyaume::listeCarteRoyaume = {
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


CarteRoyaume::CarteRoyaume() : Carte(), attaque(false), reaction(false){}

CarteRoyaume::CarteRoyaume(std::string nom){
    std::tuple<std::string,int,bool,bool> newCarte; 
    for(auto carte : listeCarteRoyaume){
        if(std::get<0>(carte) == nom){
            newCarte = carte; 
        }
    }
    
    this->nom = std::get<0>(newCarte); 
    this->prix = std::get<1>(newCarte);
    this->attaque = std::get<2>(newCarte); 
    this->reaction = std::get<3>(newCarte); 
    this->typeCarte = TypeCarte::ROYAUME;
}


CarteRoyaume::CarteRoyaume(const CarteRoyaume& c){
    this->nom = c.nom; 
    this->prix = c.prix; 
    this->attaque = c.attaque; 
    this->reaction = c.reaction; 
    this->typeCarte = TypeCarte::ROYAUME;
}

CarteRoyaume::~CarteRoyaume(){}

bool CarteRoyaume::estAttaque(){
    return this->attaque; 
} 

bool CarteRoyaume::estReaction(){
    return this->reaction;
    //test 
}

void CarteRoyaume::actionAtelier(Joueur& joueur, Plateau& plateau) {
    std::cout << "Cartes disponibles coûtant 4 pièces ou moins : " << std::endl;
    std::vector<Carte*> cartesEligibles;
    int index = 0;

    for (auto& carteQuantite : plateau.getCartePlateau()) {
        if (carteQuantite.second > 0 && carteQuantite.first->getPrix() <= 4) {
            cartesEligibles.push_back(carteQuantite.first);
            std::cout << index << ". " << carteQuantite.first->getNom() << " (Prix : " << carteQuantite.first->getPrix() << ")\n";
            index++;
        }
    }

    if (cartesEligibles.empty()) {
        std::cout << "Aucune carte éligible disponible." << std::endl;
        return;
    }

    int choix;
    std::cout << "Choisissez une carte en entrant son numéro : ";
    std::cin >> choix;

    while (choix < 0 || choix >= cartesEligibles.size()) {
        std::cout << "Choix invalide. Réessayez : ";
        std::cin >> choix;
    }

    Carte* carteChoisie = cartesEligibles[choix];
    joueur.getDeck().ajouteDefausse(carteChoisie);
    plateau.retirerCarte(carteChoisie);

    std::cout << "Vous avez ajouté " << carteChoisie->getNom() << " à votre défausse." << std::endl;
}

void CarteRoyaume::actionChapelle(Deck& deck ){
    std::vector<Carte*> mainJoueur =deck.getMain();
    std::cout<<"Voici votre main : "<<std::endl;
    for (size_t i =0 ; i<mainJoueur.size() ; ++i){
        std::cout<< i+1 <<"->"<<mainJoueur[i]->getNom()<< std::endl;
    } 
    int nbreMaxCartesDefausser=4;
    int carteDefausses=0;
    std::vector<int> cartesChoisies;

    while (carteDefausses<nbreMaxCartesDefausser){
        std::cout<<"choisissez une carte à defausser sinon entrez 0 si vous voulez rien mettre ";
        std::cout<<"choisissez une carte à defausser sinon entrez 0 si vous voulez rien mettre ";
        size_t choix ;
        std::cin >> choix;

        if(choix==0){
            break;
        }

        if( choix < 1 || choix>mainJoueur.size()){
 
           std::cout<<"Choix invalide. Veuillez entrer un numéro valide."<<std::endl;
          continue;
        }

        if(std::find(cartesChoisies.begin(),cartesChoisies.end(), choix - 1)!=cartesChoisies.end()){
          std::cout<<"Vous avez déjà choisi cette carte."<<std::endl;
          continue;
       }
       cartesChoisies.push_back(choix - 1);
       carteDefausses++;

        Carte* carteChoisie = mainJoueur[choix -1];
        deck.ajouteDefausse(carteChoisie);
        mainJoueur.erase(mainJoueur.begin() + choix -1);
        std::cout << "Vous avez défaussé " << carteChoisie->getNom() << std::endl;
    }
      
    std::cout << "Vous avez défaussé " << carteDefausses << " carte" << std::endl;
      
}


void CarteRoyaume::actionDouve(){
    //pioche 2 cartes supplementaires + protege carte jouee par un adversere
}

void CarteRoyaume::actionFestin(Plateau& plateau, Deck& deck){
    std::vector<std::pair<Carte*, int>> cartePlateau=plateau.getCartePlateau();
    std::vector<Carte*> carteAcces;
    for(size_t i=0 ;i<cartePlateau.size();++i){
        if(cartePlateau[i].first->getPrix() <= 5){
            carteAcces.push_back(cartePlateau[i].first);
            
        }
    }
    std::cout<<"L'affichage des cartes eligibles ";
    for (size_t i =0 ; i<carteAcces.size() ; ++i){
        std::cout<< i+1 <<"->"<<carteAcces[i]->getNom()<< std::endl;
    } 

    std::cout<<"Veuillez entrer l'index de la carte avec un cout au plus 5 ";
    int choix;
    std::cin>>choix;
    while (choix < 0 || choix >= carteAcces.size()) {
      std::cout << "Choix invalide. Réessayez : ";
      std::cin >> choix;
    }
    Carte* carteChoisie = carteAcces[choix-1];
    deck.ajouteDefausse(carteChoisie);

}

void CarteRoyaume::actionLaboratoire(Joueur& joueur){
    for (int i = 0; i < 2; ++i) 
    {
        if (joueur.peutPiocher()) { 
            joueur.piocherCarte(); 
        } 
        else
        { 
          std::cout << "Pas assez de cartes dans le pioche et la defausse." << std::endl;
          break;
        }
    }
    joueur.setNbAction(1);
    std::cout << "Le joueur a gagne 1 action supplémentaire." << std::endl;

}

void CarteRoyaume::actionVillage(Joueur& joueur){
    if (joueur.peutPiocher()) {
        joueur.piocherCarte();
        std::cout << "Le joueur a pioché une carte." << std::endl;
    } 
    else
    {
        std::cout << "Pas assez de cartes dans la pioche et la défausse pour piocher." << std::endl;
    }

    joueur.setNbAction(2);
    std::cout << "Le joueur gagne 2 actions supplémentaires." << std::endl;

}

void CarteRoyaume::actionSorciere(){
    //Autres Joueurs prennent 1 malediction + 
}



void CarteRoyaume::actionVoleur(){
    //autre joueur révèle les 2 premières cartes. Si elles révèlent des cartes Trésor, ils les défaussent ou les écartent
    //Vous pouvez gagner l'une de ces cartes Trésor écartées et la placer dans votre défausse.
}

void CarteRoyaume::actionJardin(){
    //+1 point pour chaque 10 carte dans le deck a la fin de la partie
}