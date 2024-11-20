#include <iostream>
#include "Jeu.hpp"


Jeu::Jeu(){
    plateau = Plateau(); 
    plateau.initialiser();
}
 
void Jeu::commenceTour(Joueur j){
    
    std::cout<<"Tour du joueur : "<<j.getNom()<<"\n";
    j.afficherMain();
    std::vector<CarteRoyaume*> carteAction = {};
    std::vector<CarteTresors*> carteTresors = {}; 

    for (auto carte : j.getDeck().getMain()){
        if (CarteRoyaume* cRoyaume = dynamic_cast<CarteRoyaume*>(carte)){
            carteAction.push_back(cRoyaume);  
        }
        else if(carte->getType() == TRESORS){
            carteTresors.push_back(dynamic_cast<CarteTresors*>(carte));
        }
    }

    phaseJeu(j,carteAction); 
    
    //phase achat : decision prise par le joueur d acheter ou non 
    bool choixAchat; 
    int c; 
    while(!choixAchat){
        std::cout<<"Voulez vous effectuer un achat ? \nEcrivez 1 pour oui / 0 pour non \n"; 
        std::cin>>c; 

        if(c == 0 || c==1){
            choixAchat = true; 
        }
        else{
            std::cout<<"Requete impossible ! \n";
        }
    }

    if(c == 1){
        phaseAchat(j,carteTresors);
    }
     
    phaseAjustement(j);

}



void Jeu::finPartie(){

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

void Jeu::phaseJeu(Joueur j, std::vector<CarteRoyaume*> carteJouer){
    //phase jeu carte 
    if (!carteJouer.empty()){
        std::cout<<"Cartes Royaumes dans votre Deck : \n";
        int index = 0; 
        for(auto c : carteJouer){
            std::cout<<index<<"Carte : "<<c->getNom()<<"\n"; 
            index ++; 
        }

        std::cout<<"Quelle carte voulez vous jouer ? Entrez l'index de la carte souhaitee : \n";
        int i;
        std::cin>>i; 

        j.jouerCarte(carteJouer.at(i));    
    }

    else {
        std::cout<<"Vous n'avez pas de cartes action dans votre main ! \n";
    }
}


void Jeu::phaseAchat(Joueur j,std::vector<CarteTresors*> carteAchat){
     //phase achat carte 
    if(!carteAchat.empty()){
        plateau.afficher(); 
        std::cout<<"Vous avez "<<j.getNbPiece()<<" pieces dans votre main \n";
        bool choix = false; 
        int index;

        while(!choix){ 
            std::cout<<"Entrez l'index de la carte a acheter : \n";
            std::cin>> index;

            if(plateau.getCartePlateau().at(index).second == 0){
                std::cout<<"Impossible carte epuisee !\n"; 
            }
            else if(plateau.getCartePlateau().at(index).first->getPrix() > j.getDeck().getNbPiece()){
                std::cout<<"Vous n'avez pas assez d'argent pour acheter cette carte !\n";
            }

            else{
                choix = true; 
            }
        }
        
        j.acheterCarte(plateau.getCartePlateau().at(index).first);
        this->plateau.retirerCarte(index);

        std::cout<<"Vous avez achete la carte : "<<plateau.getCartePlateau().at(index).first->getNom();
    }

    else{ 
        std::cout<<"Vous ne pouvez pas effectuer d'achat dans ce tours !";
    }
}

void Jeu::phaseAjustement(Joueur j){ 
    j.defausserMain();
    j.nouvelleMain(); 
}


std::vector<Joueur> Jeu::getListeJoueurs() {
    return this->listeJoueurs; 
}

