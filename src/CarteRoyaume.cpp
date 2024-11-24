#include "CarteRoyaume.hpp"
#include <iostream> 
#include <vector> 
#include <tuple> 

const std::vector<std::tuple<std::string,int,bool,bool>> CarteRoyaume::listeCarteRoyaume = {
    {"Atelier",3,false,false},//3
    {"Bucheron",3,false,false},//3
    {"Chapelle",2,false,false},//2
    {"Douve",2,false,true},//2
    {"Festin",4,false,false},//4
    {"Laboratoire",5,false,false},//5
    {"Sorciere",5,true,false},//5
    {"Village",3,false,false},//3
    {"Voleur",4,true,false}//4
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

void CarteRoyaume::action(Joueur& joueur, Plateau& plateau, std::vector<Joueur>& listeJoueurs) {

    std::string nomCarte = this->getNom();

    if (nomCarte == "Atelier") {
        actionAtelier(joueur, plateau);
    } else if (nomCarte == "Bucheron") {
        actionBucheron(joueur);
    } else if (nomCarte == "Chapelle") {
        actionChapelle(joueur);
    } else if (nomCarte == "Douve") {
        actionDouve(joueur);
    } else if (nomCarte == "Festin") {
        actionFestin(plateau, joueur);
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
    std::vector<Carte*> cartesEligibles;

    for (auto& carteQuantite : plateau.getCartePlateau()) {
        if (carteQuantite.second > 0 && carteQuantite.first->getPrix() <= 4) {
            cartesEligibles.push_back(carteQuantite.first);
        }
    }

    if (cartesEligibles.empty()) {
        std::cout << "Aucune carte eligible disponible." << std::endl;
        return;
    }
    
    std::cout<<"Veuillez choisir une carte coutant 4 pieces ou moins a ajouter a votre deck : \n ";
    for(size_t i= 0; i <cartesEligibles.size() ; i++ ){
        std::cout<<i<<"\t| Carte : "<<cartesEligibles[i]->getNom()<<" \t| Prix : "<<cartesEligibles[i]->getPrix()<<std::endl;
    }


    std::cout<<"\nEntrez l'index de la carte souhaitee \n ";    
    int choix;
    bool choixCarte = false;
    
    while (!choixCarte) {
        std::cin >> choix;
        if (std::cin.fail()) {   // Vérifie si l'entrée est invalide
            std::cin.clear();    // Réinitialise le flag d'erreur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vide le flux d'entrée
            std::cout << "Entree invalide. Veuillez entrer un entier : \n";
        } 

        else if (choix < 0 || choix >= static_cast<int>(cartesEligibles.size())) {
            std::cout << "Choix invalide. Reessayez : \n";
        } else {
            choixCarte = true; 
        }
    }

    Carte* carteChoisie = cartesEligibles[choix];
    joueur.getDeck().ajouteDefausse(carteChoisie);
    
    for (size_t ind = 0; ind < plateau.cartePlateau.size();ind++){
        if(plateau.cartePlateau.at(ind).first->getNom() == carteChoisie->getNom()){
            plateau.retirerCarte(ind);
        }
    }
    std::cout<<"\n";
    std::cout << "Vous avez ajoute " << carteChoisie->getNom() << " a votre defausse." << std::endl;
}

void CarteRoyaume::actionChapelle(Joueur& j){
    std::vector<Carte*> mainJoueur =j.getDeck().getMain();
    j.afficherMain();
    int valInterdit; 
    
    for (size_t i = 0; i< mainJoueur.size(); i++){   //on choisit pas la carte chapelle qu on vient de jouer dans le deck 
        if(mainJoueur.at(i)->getNom() == "Chapelle"){
            valInterdit = i; 
            break; 
        }    
    }

    int carteDefausses = 0;
    std::vector<Carte*> listeCartesChoisies;
    std::vector<int> indexChoisis;

    int choix ;
    bool choixCartes = false;
    std::cout<<"Choisissez des cartes a defausser\n";

    while (!choixCartes){
        std::cout<<"Entrez l'index de la carte a defausser sinon entrez -1 \n";
        std::cin >> choix; 

        if (std::cin.fail()) {   // Vérifie si l'entrée est invalide
            std::cin.clear();    // Réinitialise le flag d'erreur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vide le flux d'entrée
            std::cout << "Choix invalide. Veuillez entrer un entier : \n";
        } 

        else if(choix == -1){
            choixCartes = true;
        }

        else if( choix < -1 || choix > static_cast<int>(mainJoueur.size()-1)){
            std::cout<<"Choix invalide. Veuillez entrer un entier valide."<<std::endl;
        }

        else if(std::find(indexChoisis.begin(),indexChoisis.end(), choix)!=indexChoisis.end()){
            std::cout<<"Vous avez deja choisi cette carte."<<std::endl;
        }

        else if(choix == valInterdit){
            std::cout<<"Vous ne pouvez pas choisir la carte Chapelle que vous venez de jouer \n";
        }

        else {
            listeCartesChoisies.push_back(j.getDeck().getMain().at(choix));
            indexChoisis.push_back(choix);
            carteDefausses++;
            std::cout << "Vous avez defausse " << j.getDeck().getMain().at(choix)->getNom() << std::endl;
            if(carteDefausses == 4){break;}   //si on defausse 4 cartes alors on sort de la boucle
        }
    }

    for(auto carte : listeCartesChoisies){
        j.getDeck().uniqueMaintoDefausse(carte);
    }
    std::cout << "Vous avez defausse " << carteDefausses << " carte(s)" << std::endl;
    
    for (int i = 0; i< carteDefausses ; i++){
        j.piocherCarte(); 
    }
}

void CarteRoyaume::actionFestin(Plateau& plateau, Joueur& joueur){
    std::vector<std::pair<Carte*, int>> cartePlateau=plateau.getCartePlateau();
    std::vector<Carte*> carteAcces;
    for(size_t i=0 ;i<cartePlateau.size();++i){
        if(cartePlateau[i].first->getPrix() <= 5){
            carteAcces.push_back(cartePlateau[i].first);
            
        }
    }
    std::cout<<"Veuillez choisir une carte coutant 5 pieces ou moins a ajouter a votre deck : \n ";
    for (size_t i =0 ; i<carteAcces.size() ; ++i){
        std::cout<<i<<"\t| Carte : "<<carteAcces[i]->getNom()<<" \t| Prix : "<<carteAcces[i]->getPrix()<<std::endl;
    } 

    std::cout<<"\nEntrez l'index de la carte souhaitee \n ";
    int choix;
    bool choixCarte = false;
    
    while (!choixCarte) {
        std::cin >> choix;
        if (std::cin.fail()) {   // Vérifie si l'entrée est invalide
            std::cin.clear();    // Réinitialise le flag d'erreur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vide le flux d'entrée
            std::cout << "Entree invalide. Veuillez entrer un entier : \n";
        } 

        else if (choix < 0 || choix >= static_cast<int>(carteAcces.size())) {
            std::cout << "Choix invalide. Reessayez : \n";
        } else {
            choixCarte = true; 
        }
    }

    Carte* carteChoisie = carteAcces[choix];
    joueur.getDeck().ajouteDefausse(carteChoisie);
    
    for (size_t ind = 0; ind < plateau.cartePlateau.size();ind++){
        if(plateau.cartePlateau.at(ind).first->getNom() == carteChoisie->getNom()){
            plateau.retirerCarte(ind);
        }
    }
    
    std::cout << "\nLa carte " << carteChoisie->getNom() << " a ete ajoutee a votre defausse." << std::endl;
    joueur.getDeck().retirerCarteJeu(this);
    std::cout << "La carte Festin a ete utilisee et retiree de votre deck.\n";
}

void CarteRoyaume::actionLaboratoire(Joueur& joueur){
    for (int i = 0; i < 2; ++i) 
    {
        joueur.piocherCarte();
    }
    joueur.setNbAction(1);
    std::cout << "Vous avez pioche 2 carte et gagne 1 action supplementaire." << std::endl;
    joueur.getDeck().uniqueMaintoDefausse(new CarteRoyaume ("Laboratoire"));
}

void CarteRoyaume::actionVillage(Joueur& joueur){
    if (joueur.peutPiocher()) {
        joueur.piocherCarte();
        std::cout << "Le joueur a pioche une carte." << std::endl;
    } 
    else{
        std::cout << "Pas assez de cartes dans la pioche et la defausse pour piocher." << std::endl;
    }

    joueur.setNbAction(2);
    joueur.addNbPiece(1); 
    std::cout << "Le joueur gagne 2 actions supplementaires et 1 piece virtuelle." << std::endl;
}

void CarteRoyaume::actionDouve(Joueur& joueurActuel){
   for (int i = 0; i < 2; ++i) 
    {
        if (joueurActuel.peutPiocher()) {
           joueurActuel.piocherCarte();
        } 
        else
        {
           std::cout << "Pas assez de cartes dans la pioche et la defausse pour piocher." << std::endl;
         }
    }
   
    std::cout <<"Le joueur : " <<joueurActuel.getNom() << " a pioche 2 cartes.\n";
}

void CarteRoyaume::actionSorciere(Joueur& joueurActuel, std::vector<Joueur>& autresJoueurs, Plateau& plateau) {
    //Le joueur pioche 2 cartes 
    for (int i = 0; i < 2; ++i) {
        if (joueurActuel.peutPiocher()) {
           joueurActuel.piocherCarte();
        } 
        else
        {
           std::cout << "Pas assez de cartes dans la pioche et la defausse pour piocher." << std::endl;
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
            
            for (size_t ind = 0; ind < plateau.cartePlateau.size();ind++){
                if(plateau.cartePlateau.at(ind).first->getNom() == "Malediction"){
                    plateau.retirerCarte(ind);
                }
            }
            std::cout<<"Le joueur : "<< joueur.getNom() << " a recu une carte Malediction dans sa defausse.\n";            
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
    std::cout << "+2 pieces et +1 achat ajoute.\n";
    std::cout << "Pieces : " << joueur.getNbPiece() << ", Achats : " << joueur.getNbAchat() << std::endl<<std::endl;
}

void CarteRoyaume::actionVoleur(Joueur& joueurActif, std::vector<Joueur>& listeJoueurs){    
    // Parcourir tous les joueurs adverses
    for (Joueur& joueur : listeJoueurs) {
        if (&joueur == &joueurActif) {
            //sauter le tours du joueur actif qui joue la carte voleur
        }
        else{
            std::vector<Carte*> cartesTresorEcartees; //Cartes Trésor écartées (contiendra uniquement la carte ecarte du joueur attaque a chaque fois (size() = 1))
            std::vector<Carte*> cartesRevelees; //contient les deux cartes revellee du joueur attaqué

            //On effectue l'action de la carte si le joueur attaqué n as pas de douves dans sa main
            bool presenceDouve = douveDansMain(joueur);                 
            if (!presenceDouve){

                std::cout << joueur.getNom() << " revele les 2 premieres cartes de son deck." << std::endl;
                cartesRevelees.push_back(joueur.getDeck().getMain().at(joueur.getDeck().getMain().size()-1)); 
                joueur.getDeck().getMain().pop_back(); 

                cartesRevelees.push_back(joueur.getDeck().getMain().at(joueur.getDeck().getMain().size()-1)); 
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
                        std::cout<<"Joueur : "<<joueurActif.getNom()<<" | Quelle carte souhaitez vous ecarter \n";
                        std::cout<<"Entrez 0 pour ecarter la 1ere carte / Entrez 1 pour ecarter la 2e carte \n";
                        std::cin>> index ; 

                        if(index == '0' || index=='1'){
                            choixVoleur = true; 
                        }
                        else{
                            std::cout<<"Requete impossible ! \n";
                        }
                    }
                    if(index == '1'){
                        std::cout<<"Le joueur "<<joueurActif.getNom()<<" a ecarte la carte : "<<cartesRevelees.at(1)->getNom()<<" du joueur "<<joueur.getNom()<<" !"<<std::endl; 
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
                    std::cout<<"Aucune carte tresors n'as ete trouvee !\nLes deux cartes devoilees sont defaussees";
                    joueur.ajouteDefausse(cartesRevelees.at(0));
                    joueur.ajouteDefausse(cartesRevelees.at(1));
                }

                //phase 2 : decision du joueur de garder ou non la carte ecartee
                if (!cartesTresorEcartees.empty()) {
                    std::cout <<"Joueur "<< joueurActif.getNom() << " | Voulez vous prendre la carte "<<cartesTresorEcartees.at(0)->getNom()<<" ?" << std::endl;
                    bool choixCartePrendre = false; 
                    char decision ; 
                    while(!choixCartePrendre){
                        std::cout<<"Entrez 1 pour oui / Entrez 0 pour non\n";
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
                        std::cout<<"La carte "<<cartesTresorEcartees.at(0)->getNom()<<" a ete ecartee !"<<std::endl;
                        cartesTresorEcartees.pop_back();
                    }
                }
            }
        }
    }
    std::cout<<"\n";
}

bool CarteRoyaume::douveDansMain(Joueur joueur){
    for (auto carte : joueur.getDeck().getMain()) {
            if(carte->getNom() == "Douve"){
                std::cout<<"Le joueur "<<joueur.getNom()<<" a une carte Douve dans sa main ! \n";
                std::cout<<"Il est protege contre cette carte attaque !\n";
                return true;  
            }
    }
    return false;  
}

