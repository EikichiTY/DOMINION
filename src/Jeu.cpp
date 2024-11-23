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
        toursJoueur(listeJoueurs.at(1)); 
        finPartie(); 
    }
}


void Jeu::toursJoueur(Joueur& j){
    std::cout<<"\n\n------------------------------------------------------------------------------------";
    std::cout<<"\nTour du joueur : "<<j.getNom()<<"\n";
    j.afficherMain();
    std::vector<CarteRoyaume*> carteAction = {};
    std::vector<CarteTresors*> carteTresors = {}; 

    j.setNbAchat(1); 
    j.setNbAction(1); 


    for (auto carte : j.getDeck().getMain()){
        if (CarteRoyaume* cRoyaume = dynamic_cast<CarteRoyaume*>(carte)){
            carteAction.push_back(cRoyaume);  
        }
        else if(carte->getType() == TRESORS){
            carteTresors.push_back(dynamic_cast<CarteTresors*>(carte));
        }
    }

    //phase jeu
    while(j.getNbAction()>0){
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
        }
        else{
            std::cout<<"Phase jeu terminee \n";
        }
        j.setNbAction(-1); 

    }
    
    //phase achat : decision prise par le joueur d'acheter ou non  
    while(j.getNbAchat() > 0){
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
    }
    else if(plateau.getProvinceEpuise()){    
        this->finJeu = true; 
    }
}


void Jeu::calculerPoints(Joueur& j){
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
    if (!carteJouer.empty()){
        std::cout<<"Cartes Royaumes dans votre Deck : \n";
        int index = 0; 
        for(auto c : carteJouer){
            std::cout<<index<<" | Carte : "<<c->getNom()<<"\n"; 
            index ++; 
        }
        std::cout<<"Quelle carte voulez vous jouer ? Entrez l'index de la carte souhaitee : \n";
        int i;
        std::cin>>i; 
        
        //carteJouer.at(i)->action(j, this->plateau, j.getDeck());    
    }

    else {
        std::cout<<"Vous n'avez pas de cartes action dans votre main ! \n";
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
            
            if(index < 0 || index >16){
                std::cout<<"Erreur !! Choisissez un index entre 0 et 16 !\n\n";
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
        
        j.acheterCarte(plateau.getCartePlateau().at(index).first);
        this->plateau.retirerCarte(index);

        std::cout<<"Vous avez achete la carte : "<<plateau.getCartePlateau().at(index).first->getNom()<<"\n";
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

