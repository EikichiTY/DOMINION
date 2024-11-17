#include <iostream>
#include "Jeu.hpp"


Jeu::Jeu(){}

void Jeu::commenceTour(Joueur j){
    
    std::cout<<"Tour du joueur : "<<j.getNom()<<"\n";
    j.afficherMain();
    std::vector<CarteRoyaume*> carteJouer = {}; 

    for (auto carte : j.getDeck().getMain()){
        if (CarteRoyaume* carteRoyaume = dynamic_cast<CarteRoyaume*>(carte)){
            carteJouer.push_back(carteRoyaume);  
        }
    }

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


    /*
    if(j.getDeck().getNbPiece() > 0) { 
        j.acheterCarte(); 
    }
    else{
        std::cout<<"Vous ne pouvez pas effectuer d'achat pour ce tours ! \n"; 
    }
    j.nouvelleMain(); */
}

/*Joueur Jeu::prochainJoueur(Joueur j*){ 
    for (auto joueur : listeJoueurs){
        if (joueur j ){break;} 
    }
    Joueur prochain = listeJoueurs.at(i+1); 
    return prochain; 
}*/

void Jeu::ajouterJoueur(){
    for (int i = 1; i <= 2; ++i) {
        std::string username;
        std::cout << "Entrez le nom du joueur " << i << ": ";
        std::cin >> username;
        listeJoueurs.push_back(Joueur(username));
    }

    std::cout << "\nLes usernames des 2 joueurs sont : "<<this->listeJoueurs.at(0).getNom()<<" et "<<this->listeJoueurs.at(1).getNom()<<"\n";
    std::cout<<"La partie peut commencer ! \n\n";

}


std::vector<Joueur> Jeu::getListeJoueurs() {
    return this->listeJoueurs; 
}

