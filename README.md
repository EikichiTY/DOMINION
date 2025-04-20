# DOMINION
Bienvenue dans le dépôt Git pour le projet **Dominion** ! Ce projet consiste à développer une version console du célèbre jeu de société Dominion, en C++.
Projet effectue par Yacine FARHI et Hajar IZANDAZ. 

## Objectif
L'objectif est de recréer une version fonctionnelle du jeu Dominion en suivant les règles de base, avec les 10 cartes du jeu de base spécifiées dans le projet : **atelier, bûcheron, chapelle, douve, festin, jardins, laboratoire, sorcière, village, voleur**.

Le jeu inclut également les **cartes trésors** (cuivre, argent, or), les **cartes victoires** (domaine, duché, province) et les **cartes malédiction**.

## Description du jeu
Règles du jeu : http://www.cyberfab.fr/dominion.php

### Règles principales
1. Chaque joueur construit un deck représentant son royaume en achetant des cartes Trésor, Royaume, et Victoire.
2. Chaque tour est composé de 3 phases :
   - **Phase Action** : Jouez une ou plusieurs cartes Action.
   - **Phase Achat** : Achetez une ou plusieurs cartes de la réserve.
   - **Phase Ajustement** : Défaussez les cartes utilisées et piochez 5 nouvelles cartes.
3. La partie se termine lorsque :
   - La pile des **cartes Province** est vide.
   - OU 3 piles de cartes de la réserve sont vides.
4. Le joueur avec le plus de **points de victoire** remporte la partie.

### Configuration initiale
- Chaque joueur commence avec un deck de :
  - **7 cartes de cuivre** (valant 1 d'achat).
  - **3 cartes de domaine** (rapportant 1 point de victoire chacune).
- Les cartes disponibles dans la réserve incluent :
  - **9 cartes Royaume** (atelier, bûcheron, laboratoire, chapelle, festin, douves, sorcière, voleur, village).
  - **Cartes Trésor** : cuivre, argent, or.
  - **Cartes Victoire** : domaine, duché, province, jardin. 
  - **Cartes Malédiction** : 30 cartes.

## Fonctionnalités implémentées
- Jeu pour **2 joueurs** en console.
- Mélange automatique des decks avant la partie.
- Gestion des **3 phases de jeu** (Action, Achat, Ajustement).
- Affichage du jeu en console.
- Détection automatique de la **fin de partie** et calcul du score.

