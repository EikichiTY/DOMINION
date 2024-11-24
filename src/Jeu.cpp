#include <iostream>
#include "Jeu.hpp"


Jeu::Jeu(){
    finJeu = false; 
    plateau = Plateau(); 
    plateau.initialiser();
}

Jeu::~Jeu(){}
 

void Jeu::jouerPartie(){
    ajouterJoueur();

    while(!finJeu){
        toursJoueur(listeJoueurs.at(0)); 
        finPartie();
        if(finJeu){
            break;
        }
        toursJoueur(listeJoueurs.at(1)); 
        finPartie(); 
    }
    calculerPoints(listeJoueurs.at(0));
    calculerPoints(listeJoueurs.at(1));

    int pointJoueur1 = listeJoueurs.at(0).getScore();
    int pointJoueur2 = listeJoueurs.at(1).getScore();

    std::cout<<"\n---------------------------------------------------------------------------------------------------" ; 
    std::cout<<"\nFin de la partie ! \n\nVoici les scores :\n"; 
    std::cout<<"Score joueur "<<listeJoueurs.at(0).getNom()<<" : "<<pointJoueur1<<std::endl; 
    std::cout<<"Score joueur "<<listeJoueurs.at(1).getNom()<<" : "<<pointJoueur2<<std::endl; 

    if(pointJoueur1 == pointJoueur2){
        std::cout<<"Egalite !\nAucun vainqueur !\n"; 
    }
    else if (pointJoueur1 > pointJoueur2){
        std::cout<<"Vainqueur : " <<listeJoueurs.at(0).getNom()<< " !\n"; 
    }
    else if (pointJoueur1 < pointJoueur2){
        std::cout<<"Vainqueur : " <<listeJoueurs.at(1).getNom()<< " !\n"; 
    }

    std::cout<<"Bravo aux deux Joueurs !\nFin du jeu"; 
    std::cout<<"\n---------------------------------------------------------------------------------------------------" ; 
}


void Jeu::toursJoueur(Joueur& j){
    std::cout<<"\n\n------------------------------------------------------------------------------------";
    std::cout<<"\nTour du joueur : "<<j.getNom()<<"\n";
    std::vector<CarteRoyaume*> carteAction = {};
    std::vector<CarteTresors*> carteTresors = {}; 

    j.setNbAchat(1); 
    j.setNbAction(1); 

    //phase jeu
    while(j.getNbAction()>0){
        std::cout<<"\n################ Phase Jeu ################\n";
        j.afficherMain();
        for (auto carte : j.getDeck().getMain()){
            if (CarteRoyaume* cRoyaume = dynamic_cast<CarteRoyaume*>(carte)){
                carteAction.push_back(cRoyaume); 
            } 
        }

        if(carteAction.empty()){
            std::cout<<"Vous n'avez pas de cartes action dans votre main ! \n";
        }
        else{
            bool choixAction = false; 
            char a; 
            while (!choixAction){
                std::cout<<"Voulez vous jouer une carte ? \nEcrivez 1 pour oui / 0 pour non \n"; 
                std::cin>>a;

                if(a == '0' || a=='1'){
                    choixAction = true; 
                }
                else{
                    std::cout<<"Requete impossible ! \n";
                }
            }
            if(a == '1'){
                phaseJeu(j,carteAction);
                carteAction = {}; 
            }
            else{
                std::cout<<"Phase jeu terminee \n";
            }
        }
        j.setNbAction(-1); 
    }
    
    //phase achat : decision prise par le joueur d'acheter ou non  
    while(j.getNbAchat() > 0){
        std::cout<<"\n################ Phase Achat ################\n";
        j.afficherMain();
        j.getDeck().setNbPiece();
        
        for (auto carte : j.getDeck().getMain()){
            if(carte->getType() == TRESORS){
                carteTresors.push_back(dynamic_cast<CarteTresors*>(carte));
            }
        }
        bool choixAchat = false; 
        char c;
        while(!choixAchat){
            std::cout<<"Voulez vous effectuer un achat ? \nEcrivez 1 pour oui / 0 pour non \n"; 
            std::cin>>c; 

            if(c == '0' || c=='1'){
                choixAchat = true; 
            }
            else{
                std::cout<<"Requete impossible ! \n";
            }
        }
        if(c == '1'){
            phaseAchat(j,carteTresors);
            carteTresors = {};
        }
        else{
            std::cout<<"Phase achat terminee \n";
        }
        j.setNbAchat(-1); 
    }
    
    //phase ajustement
    phaseAjustement(j);

}



void Jeu::finPartie(){
    if(plateau.getCarteEpuise() == 3){
        this->finJeu = true;
        for (auto joueur : listeJoueurs){
            joueur.getDeck().allToDefausse(); 
        }
    }
    else if(plateau.getProvinceEpuise()){    
        this->finJeu = true; 
        for (auto joueur : listeJoueurs){
            joueur.getDeck().allToDefausse(); 
        }
    }
}


void Jeu::calculerPoints(Joueur& j){
    j.getDeck().allToDefausse();
    int point = 0; 
    int nbJardins = 0; 
    int pointJardin = 0; 
    for (auto carte : j.getDeck().getDefausse()){
        if(CarteVictoire* cVictoire = dynamic_cast<CarteVictoire*>(carte)){
            point += cVictoire->getPoint();
            if(cVictoire->getNom() == "Jardins") { 
                nbJardins += 1; 
            }
        }       
    }

    pointJardin = (j.getDeck().getDefausse().size() / 10) * nbJardins ; 

    j.setScore(point+pointJardin); 
}

void Jeu::ajouterJoueur(){
    for (int i = 1; i <= 2; ++i){
        std::string username;
        std::cout << "Entrez le nom du joueur " << i << ": ";
        std::cin >> username;
        
        listeJoueurs.push_back(Joueur(username));
        for (auto joueur : listeJoueurs){
            joueur.initMainDeck(); 
        }
    }

    std::cout << "\nLes usernames des 2 joueurs sont : "<<this->listeJoueurs.at(0).getNom()<<" et "<<this->listeJoueurs.at(1).getNom()<<"\n";
    std::cout<<"La partie peut commencer ! \n\n";
}

void Jeu::phaseJeu(Joueur& j, std::vector<CarteRoyaume*> carteJouer){
    //phase jeu carte 
    std::cout<<"\nCartes Royaumes dans votre Deck : \n";
    int index = 0; 
    for(auto c : carteJouer){
        std::cout<<index<<" | Carte : "<<c->getNom()<<"\n"; 
        index ++; 
    }

    size_t i;
    bool choixCarte = false; 
    while(!choixCarte){
        std::cout<<"\nQuelle carte voulez vous jouer ? Entrez l'index de la carte souhaitee : \n";
        std::cin>>i;   

        if (i < '0' && i > carteJouer.size()){
            std::cout<<"Index invalide ! \n"; 
        }  
        else {
            choixCarte = true; 
            std::cout<<"Vous avez joue la carte : "<<carteJouer.at(i)->getNom()<<"\n\n";
            carteJouer.at(i)->afficheCarte(); 
            std::cout<<"\n\n";

            carteJouer.at(i)->action(j, this->plateau,this->listeJoueurs);

            j.getDeck().uniqueMaintoDefausse(carteJouer.at(i));
            carteJouer.erase(carteJouer.begin()+i); 
        }
    }   
}


void Jeu::phaseAchat(Joueur& j,std::vector<CarteTresors*> carteAchat){
     //phase achat carte 
    if(!carteAchat.empty()){
        plateau.afficher(); 
        std::cout<<"\nVous avez "<<j.getNbPiece()<<" pieces dans votre main \n";
        bool choix = false; 
        int index;

        while(!choix){ 
            std::cout<<"Entrez l'index de la carte a acheter : \n";
            std::cin>> index;
            
            if (std::cin.fail()) {   
                std::cin.clear();    // Réinitialise le flag d'erreur
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vide le flux d'entrée
                std::cout << "Entree invalide ! Veuillez entrer un entier ! \n\n";
            } 
            
            else if(index < 0 || index >16){
                std::cout<<"Erreur ! Choisissez un index entre 0 et 16 !\n\n";
            }

            else if(plateau.getCartePlateau().at(index).second == 0){
                std::cout<<"Impossible carte epuisee !\n\n"; 
            }
            else if(plateau.getCartePlateau().at(index).first->getPrix() > j.getDeck().getNbPiece()){
                std::cout<<"Vous n'avez pas assez d'argent pour acheter cette carte !\n\n";
            }

            else{
                choix = true; 
            }
        }
        
        j.ajouteDefausse(plateau.getCartePlateau().at(index).first);
        this->plateau.retirerCarte(index);

        std::cout<<"Vous avez achete la carte : "<<plateau.getCartePlateau().at(index).first->getNom()<<"\n\n";
        plateau.getCartePlateau().at(index).first->afficheCarte(); 
        std::cout<<"\n\n";
        j.getDeck().addNbPiece(-plateau.getCartePlateau().at(index).first->getPrix());
    }
    else{ 
        std::cout<<"Vous ne pouvez pas effectuer d'achat dans ce tours !\n";
    }
}


void Jeu::phaseAjustement(Joueur& j){ 
    std::cout<<"Fin du tours\n"; 

    j.defausserMain();
    std::cout<<"Votre main a ete defaussee \n"; 

    j.nouvelleMain(); 
    std::cout<<"Generation d'une nouvelle main\n------------------------------------------------------------------------------------";
}


std::vector<Joueur> Jeu::getListeJoueurs() {
    return this->listeJoueurs; 
}

