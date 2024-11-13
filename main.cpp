#include <iostream> 
#include "Carte.hpp"

int main(){

    Carte c1 = Carte("voleur",3);
    std::cout<<"Hello \n";
    
    std::cout<<c1.getNom()<<std::endl ; 

    c1.afficheCarte(); 
    
    return 0; 
}