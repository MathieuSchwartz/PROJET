//
// Created by mathi on 30/05/2021.
//

#ifndef PROJET_BASE_H
#define PROJET_BASE_H


typedef struct {

    int hauteur;
    int largeur;
    int N;

} grid;

/*
 * Demande aux joueurs le nombre de jetons à aligner afin de déterminer les dim. de la grille
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
int positionner_jeton(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee, int dernierjeton_xy[2]);  //section2

/*
 * Permet de retirer le jeton en prenant en paramètre le symbole du joueur
 */
int retirer_jeton(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee);     //section2


int tour_joueur2(grid grille, char grillepuissanceN[50][50],int * colonne_bloquee, int dernierjeton_xy[2]);

int tour_joueur1(grid grille, char grillepuissanceN[50][50], int * colonne_bloquee, int dernierjeton_xy[2]);

int tour_ordi(grid grille, char grillepuissanceN[50][50], int * colonne_bloquee, int dernierjeton_xy[2]);

void tour(int joueur1or2, char grillepuissanceN[50][50], grid grille);

int menu();

#endif //PROJET_BASE_H