#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Fonctions.h"


int main() {

    grid grille;
    grille = def_grille(grille);
    char grillepuissanceN[50][50];
    initialisation_grille(grille, grillepuissanceN);
    afficher_grille(grille, grillepuissanceN);

    int joueur1or2;
    srand(time(0));
    joueur1or2 = rand()% 2 + 1;    //si '1' est tiré alors le joueur jaune commence,
    //si '2' est tiré alors le joueur rouge commence

    int colonne_bloquee; //la colonne bloquee n'as aucun impacte sur la grille de jeu
    colonne_bloquee = grille.largeur+1;

    //test pour voir si les fonctions marchent  (version pas finale)
    char symbolejoueurjaune = 'X';
    char symbolejoueurrouge = 'O';

    tour(joueur1or2,grillepuissanceN, grille, &colonne_bloquee);
    tour(joueur1or2,grillepuissanceN, grille, &colonne_bloquee);
    tour(joueur1or2,grillepuissanceN, grille, &colonne_bloquee);
    /*
    positionner_jeton(grille, grillepuissanceN, symbolejoueurjaune, &colonne_bloquee);
    afficher_grille(grille, grillepuissanceN);
    positionner_jeton(grille, grillepuissanceN, symbolejoueurrouge, &colonne_bloquee);
    afficher_grille(grille, grillepuissanceN);
    retirer_jeton(grille, grillepuissanceN, symbolejoueurjaune, &colonne_bloquee);
    afficher_grille(grille, grillepuissanceN);
    retirer_jeton(grille, grillepuissanceN, symbolejoueurrouge, &colonne_bloquee);
    afficher_grille(grille, grillepuissanceN);
    positionner_jeton(grille, grillepuissanceN, symbolejoueurjaune, &colonne_bloquee);
    afficher_grille(grille, grillepuissanceN);
     */

    return 0;
}