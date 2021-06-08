//
// Created by Elève on 25/05/2021.
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

int choixjoueur(int joueur1or2);

int jetonsdanslagrille(grid grille, char grillepuissanceN[50][50]);

void menu(int *NB_joueur, int *charger_partie);

int scan_valeur(int valeur);

#endif //PROJET_BASE_H