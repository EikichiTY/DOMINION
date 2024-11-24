#include "CarteRoyaume.hpp"
#include <iostream> 
#include <vector> 
#include <tuple> 

const std::vector<std::tuple<std::string,int,bool,bool>> CarteRoyaume::listeCarteRoyaume = {
    {"Atelier",1,false,false},//3
    {"Bucheron",3,false,false},//3
    {"Chapelle",2,false,false},//2
    {"Douve",2,false,true},//2
    {"Festin",1,false,false},//4
    {"Laboratoire",1,false,false},//5
    {"Sorciere",1,true,false},//5
    {"Village",1,false,false},//3
    {"Voleur",1,true,false}//4
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
}

void CarteRoyaume::action(Joueur& joueur, Plateau& plateau, Deck& deck, std::vector<Joueur>& listeJoueurs) {

    std::string nomCarte = this->getNom();

    if (nomCarte == "Atelier") {
        actionAtelier(joueur, plateau);
    } else if (nomCarte == "Bucheron") {
        actionBucheron(joueur);
    } else if (nomCarte == "Chapelle") {
        actionChapelle(deck);
    } else if (nomCarte == "Douve") {
        actionDouve(joueur);
    } else if (nomCarte == "Festin") {
        actionFestin(plateau, deck);
    } else if (nomCarte == "Laboratoire") {
        actionLaboratoire(joueur);
    } else if (nomCarte == "Sorciere") {
        actionSorciere(joueur, listeJoueurs, plateau);
    } else if (nomCarte == "Village") {
        actionVillage(joueur);
    } else if (nomCarte == "Voleur") {
        actionVoleur(joueur, listeJoueurs);
    } else {
        std::cerr << "Action inconnue pour la carte : " << nomCarte << std::endl;
    }
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
        std::cout<<"choisissez une carte a defausser sinon entrez 0 si vous voulez rien mettre \n";
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
        std::cout << "Vous avez defausse " << carteChoisie->getNom() << std::endl;
    }
      
    std::cout << "Vous avez defausse " << carteDefausses << " carte" << std::endl;
    
    
    auto nouvelleMain = deck.getMain(); 

    int index = 0; 
    std::cout<<"Votre main : \n";
    for(auto carte : nouvelleMain){
        std::cout<<index<<" | Carte : "<<carte->getNom()<<"\t| Type : "<<carte->TypetoString()<<"\n";
        index ++; 
    }
    std::cout<<"\n";
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
    plateau.retirerCarte(carteChoisie);
    std::cout << "La carte " << carteChoisie->getNom() << " a été ajoutée à votre défausse." << std::endl;
    deck.retirerCarteJeu(this);
    std::cout << "La carte Festin a été utilisée et retirée de votre deck.\n";
}

void CarteRoyaume::actionLaboratoire(Joueur& joueur){
    for (int i = 0; i < 2; ++i) 
    {
        joueur.piocherCarte();
    }
    joueur.setNbAction(1);
    std::cout << "Le joueur a gagne 1 action supplementaire." << std::endl;
    joueur.getDeck().uniqueMaintoDefausse(new CarteRoyaume ("Laboratoire"));


}

void CarteRoyaume::actionVillage(Joueur& joueur){
    if (joueur.peutPiocher()) {
        joueur.piocherCarte();
        std::cout << "Le joueur a pioché une carte." << std::endl;
    } 
    else{
        std::cout << "Pas assez de cartes dans la pioche et la defausse pour piocher." << std::endl;
    }

    joueur.setNbAction(2);
    joueur.addNbPiece(1); 
    std::cout << "Le joueur gagne 2 actions supplementaires." << std::endl;
}

void CarteRoyaume::actionDouve(Joueur& joueurActuel){
   for (int i = 0; i < 2; ++i) 
    {
        if (joueurActuel.peutPiocher()) {
           joueurActuel.piocherCarte();
           std::cout << "Le joueur a pioche une carte." << std::endl;
        } 
        else
        {
           std::cout << "Pas assez de cartes dans la pioche et la défausse pour piocher." << std::endl;
         }
    }
   
    std::cout << joueurActuel.getNom() << " a pioche 2 cartes.\n";
}

void CarteRoyaume::actionSorciere(Joueur& joueurActuel, std::vector<Joueur>& autresJoueurs, Plateau& plateau) {
    //Le joueur pioche 2 cartes 
    for (int i = 0; i < 2; ++i) {
        if (joueurActuel.peutPiocher()) {
           joueurActuel.piocherCarte();
        } 
        else
        {
           std::cout << "Pas assez de cartes dans la pioche et la défausse pour piocher." << std::endl;
         }
    }
    std::cout << joueurActuel.getNom() << " a pioche 2 cartes.\n\n";

    // Chercher la carte "Malediction" sur le plateau
    Carte* carteMalediction = nullptr;
    for (auto& paire : plateau.cartePlateau) {
        if (paire.first->getNom() == "Malediction" && paire.second > 0) {
            carteMalediction = paire.first;
            break; 
        }
    }


    for (auto& joueur : autresJoueurs) {
        if (carteMalediction == nullptr) {
            std::cout << "Aucune carte 'Malediction' n'est disponible sur le plateau.\n";
            break; 
        }

        if (&joueur == &joueurActuel ) {
        } 
        else if (!douveDansMain(joueur)) {
            joueur.ajouteDefausse(carteMalediction);
            plateau.retirerCarte(carteMalediction);
            std::cout<< joueur.getNom() << " a reçu une carte Malediction dans sa defausse.\n";            
        }
        else {
            std::cout<< "Le joueur " << joueur.getNom() << " est protege par une carte Douve dans sa main !\n";
        }
    }
}

void CarteRoyaume::actionBucheron(Joueur& joueur){
    std::cout << "Nombre Pieces Initial : " << joueur.getNbPiece() << ", Nombre Achats Initial: " << joueur.getNbAchat() << std::endl;
    joueur.setNbAchat(1);
    joueur.addNbPiece(2);
    std::cout << "Action Bucheron jouee !\n";
    std::cout << "+2 pieces et +1 achat ajouté.\n";
    std::cout << "Pieces : " << joueur.getNbPiece() << ", Achats : " << joueur.getNbAchat() << std::endl<<std::endl;
}

void CarteRoyaume::actionVoleur(Joueur& joueurActif, std::vector<Joueur>& listeJoueurs){    
    // Parcourir tous les joueurs adverses
    for (Joueur& joueur : listeJoueurs) {
        if (&joueur == &joueurActif) {
            continue; // Sauter le joueur actif
        }

        std::vector<Carte*> cartesTresorEcartees; //Cartes Trésor écartées (contiendra uniquement la carte ecarte du joueur attaque a chaque fois (size() = 1))
        std::vector<Carte*> cartesRevelees; //contient les deux cartes revellee du joueur attaqué

        std::cout << joueur.getNom() << " révèle les 2 premières cartes de son deck." << std::endl;

        //On effectue l'action de la carte si le joueur attaqué n as pas de douves dans sa main
        bool presenceDouve = douveDansMain(joueur);                 
        if (!presenceDouve){

            cartesRevelees.push_back(joueur.getDeck().getMain().at(4)); 
            joueur.getDeck().getMain().pop_back(); 

            cartesRevelees.push_back(joueur.getDeck().getMain().at(4)); 
            joueur.getDeck().getMain().pop_back(); 

            std::cout<<"Cartes revelees : \n";
            for (auto carte : cartesRevelees){
                carte->afficheCarte();
            }

            // phase 1 : Traiter les cartes Trésor a ecarter 
            if (cartesRevelees.at(0)->getType() == TypeCarte::TRESORS && cartesRevelees.at(1)->getType() == TypeCarte::TRESORS) { // Vérifie si la carte est une carte Trésor
                bool choixVoleur = false; 
                char index ; 
                while(!choixVoleur){
                    std::cout<<"Joueur : "<<joueurActif.getNom()<<"Quelle carte souhaitez vous ecarter \n";
                    std::cout<<"Entrez 0 pour écarter la 1ere carte / Entrez 1 pour ecarter la 2e carte";
                    std::cin>> index ; 

                    if(index == '0' || index=='1'){
                        choixVoleur = true; 
                    }
                    else{
                        std::cout<<"Requete impossible ! \n";
                    }
                }
                if(index == '1'){
                    std::cout<<"Le joueur "<<joueurActif.getNom()<<" a ecarte la carte : "<<cartesRevelees.at(1)->getNom()<<"de "<<joueur.getNom()<<std::endl; 
                    cartesTresorEcartees.push_back(cartesRevelees.at(1));
                    joueur.ajouteDefausse(cartesRevelees.at(0));
                }
                else if (index == '0'){
                    std::cout<<"Le joueur "<<joueurActif.getNom()<<" a ecarte la carte : "<<cartesRevelees.at(0)->getNom()<<"de "<<joueur.getNom()<<std::endl;
                    cartesTresorEcartees.push_back(cartesRevelees.at(0));
                    joueur.ajouteDefausse(cartesRevelees.at(1));
                }
            }

            else if(cartesRevelees.at(0)->getType() == TypeCarte::TRESORS && cartesRevelees.at(1)->getType() != TypeCarte::TRESORS){
                std::cout<<"La carte "<<cartesRevelees.at(0)->getNom()<<" a ete ecartee \n";
                cartesTresorEcartees.push_back(cartesRevelees.at(0));
                joueur.ajouteDefausse(cartesRevelees.at(1));
            }
            else if(cartesRevelees.at(0)->getType() != TypeCarte::TRESORS && cartesRevelees.at(1)->getType() == TypeCarte::TRESORS){
                std::cout<<"La carte "<<cartesRevelees.at(1)->getNom()<<" a ete ecartee \n";
                cartesTresorEcartees.push_back(cartesRevelees.at(1));
                joueur.ajouteDefausse(cartesRevelees.at(0));
            }

            else {  
                std::cout<<"Aucune carte tresors n'as ete ecartee !";
                joueur.ajouteDefausse(cartesRevelees.at(0));
                joueur.ajouteDefausse(cartesRevelees.at(1));
            }

            //phase 2 : decision du joueur de garder ou non la carte ecartee
            if (!cartesTresorEcartees.empty()) {
                std::cout << joueurActif.getNom() << " : voulez vous prendre cette carte ?" << std::endl;
                bool choixCartePrendre = false; 
                char decision ; 
                while(!choixCartePrendre){
                    std::cout<<"Entrez 1 pour oui / Entrez 0 pour non";
                    std::cin>> decision ; 

                    if(decision == '0' || decision=='1'){
                        choixCartePrendre = true; 
                    }
                    else{
                        std::cout<<"Requete impossible ! \n";
                    }
                }
                if(decision == '1'){
                    joueurActif.ajouteDefausse(cartesTresorEcartees.at(0));
                    std::cout<<"Le joueur "<<joueurActif.getNom()<<" a recu la carte : "<<cartesTresorEcartees.at(0)->getNom()<<std::endl; 
                    cartesTresorEcartees.pop_back();
                }
                else if (decision == '0'){
                    std::cout<<"La carte "<<cartesTresorEcartees.at(0)->getNom()<<"a ete ecartee !"<<std::endl;
                    cartesTresorEcartees.pop_back();
                }
            }
        }
        else {
            std::cout<<"Le joueur "<<joueur.getNom()<<" est protege par la carte douve dans sa main !";
        }
    }
    std::cout<<"################## Fin de l'action de la carte voleur ##################";
}

bool CarteRoyaume::douveDansMain(Joueur joueur){
    for (auto carte : joueur.getDeck().getMain()) {
            if(carte->getNom() == "Douve"){
                std::cout<<"Le joueur "<<joueur.getNom()<<" a une carte Douves dans sa main ! \n";
                std::cout<<"Il est protege contre cette carte attaque !\n";
                return true;  
            }
    }
    return false;  
}

