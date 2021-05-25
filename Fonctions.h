//
// Created by mathi on 25/05/2021.
//

#ifndef PROJET_FONCTIONS_H
#define PROJET_FONCTIONS_H


typedef struct {

    int hauteur;
    int largeur;
    int N;

} grid;

/*
Demande aux joueurs le nombre de jetons à aligner afin de déterminer les dim. de la grille
 */
grid def_grille(grid grille);       //section 1

void initialisation_grille(grid grille, char grillepuissanceN[50][50]);  //section1  (1 section
// correspond à une bibliothèque)
/*
 * affiche la grille de jeu en cours
 */
void afficher_grille(grid grille, char grillepuissanceN[50][50]);        //section 1

/*
 * Permet de positionner le jeton en prenant en paramètre le symbole du joueur
 */
int positionner_jeton(grid grille, char grillepuissanceN[50][50], char symbole);  //section2

/*
 * Permet de retirer le jeton en prenant en paramètre le symbole du joueur
 */
int retirer_jeton(grid grille, char grillepuissanceN[50][50], char symbole);     //section2

/*
 * Joue un tour classique, les deux joueurs jouent une fois
 */
int tour(int joueur1or2, char grillepuissanceN[50][50], grid grille);

int tour_joueur1(grid grille, char grillepuissanceN[50][50]);

int tour_joueur2(grid grille, char grillepuissanceN[50][50]);

#endif //PROJET_FONCTIONS_H
