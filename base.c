//
// Created by mathi on 30/05/2021.
//

#include "base.h"
#include "save.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "check_winner.h"




grid def_grille(grid grille)
{
    do {
        printf("Combien de jetons voulez-vous aligner pour gagner ? \n");
        scanf("%d", &grille.N);
    } while ( grille.N < 3 || grille.N > 47); //car limite tableau = 50 donc 50-2 = 48
    grille.hauteur = grille.N + 2;
    grille.largeur = grille.N + 2;
    return grille;
}

void initialisation_grille(grid grille, char grillepuissanceN[50][50])
{
    int i;
    int j;
    for (i = 0 ; i < grille.hauteur ; i++)
    {
        for (j = 0 ; j < grille.largeur ; j++)
        {
            grillepuissanceN[j][i] = '_';
        }
    }
}

void afficher_grille(grid grille, char grillepuissanceN[50][50])
{
    int i;
    int j;
    for (i = 0 ; i < grille.hauteur ; i++)
    {
        printf("|");
        for (j = 0 ; j < grille.largeur ; j++)
        {
            printf("  %c  |", grillepuissanceN[j][i]);
        }
        printf("\n");
    }
}

int positionner_jeton(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee, int dernierjeton_xy[2])
{
    int positionjeton;
    int action_poser;   //si action_poser == 1 alors l'action peut se faire
    //si action_poser == 0 alors l'action ne peut se faire donc on redemande à l'utilisateur
    int i;

    do {
        printf("Dans quelle colonne voulez vous deposer votre jeton ?\n");
        scanf("%d", &positionjeton);
    } while (positionjeton < 0 || positionjeton > grille.largeur);

    i = grille.hauteur - 1;   //on part du bas du tableau puis on remonte au fur et à mesure que la case ne soit pas remplie
    action_poser = 1;
    while (grillepuissanceN[positionjeton - 1][i] != '_' && i > -1) //positionjeton - 1 pour suivre la logique de l'utilisateur
    {
        i = i - 1;
    }

    if (grillepuissanceN[positionjeton - 1][0] != '_' || positionjeton - 1 == *colonne_bloquee){
        action_poser = 0;
        printf("Vous ne pouvez pas placer un jeton dans cette colonne. Erreur colonne : %d\n", positionjeton);
    } else {
        grillepuissanceN[positionjeton - 1][i] = symbole;
        *colonne_bloquee = grille.largeur+1;
        dernierjeton_xy[0] = positionjeton - 1;     //prend la valeur de x
        dernierjeton_xy[1] = i;                     //prend la valeur de y
    }

    return action_poser;
}

int retirer_jeton(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee)
{
    int positionjeton;
    int action_retirer;   //si action_retirer == 0 alors on ne peux pas retirer le jeton
    //si action_retirer == 1 alors le retirage est effectué
    int i = 0;

    do {
        action_retirer = 1;
        printf("Dans quelle colonne voulez vous retirer votre jeton ?\n");
        scanf("%d", &positionjeton);
    } while (positionjeton < 0 || positionjeton > grille.largeur);


    while (grillepuissanceN[positionjeton - 1][i] != 'X' && grillepuissanceN[positionjeton - 1][i] != 'O'
           && i < grille.hauteur-1) {
        i = i + 1;
    }

    if (grillepuissanceN[positionjeton - 1][i] == 'X' || grillepuissanceN[positionjeton - 1][i] == 'O') {
        grillepuissanceN[positionjeton - 1][i] = '_';
        *colonne_bloquee = positionjeton - 1;
    } else if (grillepuissanceN[positionjeton - 1][i] == '_'){
        action_retirer = 0;
        printf("Vous ne pouvez pas retirer un jeton dans cette colonne. Erreur colonne : %d\n", positionjeton);
    }

    return action_retirer;
}

void tour(int joueur1or2, char grillepuissanceN[50][50], grid grille) {

    int colonne_bloquee = grille.largeur + 1; //la colonne bloquee n'as aucun impacte sur la grille de jeu
    int vainqueur = 0;
    int dernierjeton_xy[2];                   //tableau avec la position du dernier jeton posé, ex {1,5}
    // donc le jeton est posé en x=1 et y=5 dans le tableau

    if (joueur1or2 == 1) {

        do {
            printf("Le joueur 1 commence...\n");
            vainqueur = tour_joueur1(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy);
            printf("C'est au tour du joueur 2...\n");
            tour_joueur2(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy);
        } while (vainqueur == 0);
    } else if (joueur1or2 == 2) {
        do {
            printf("Le joueur 2 commence...\n");
            vainqueur = tour_joueur2(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy);
            printf("C'est au tour du joueur 1...\n");
            tour_joueur1(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy);
        } while (vainqueur == 0);

    }
}

int tour_joueur1(grid grille, char grillepuissanceN[50][50], int *colonne_bloquee, int dernierjeton_xy[2]) {

    char symbole = 'X';
    int vainqueur = 0;
    int action_effectuer = 1;   //action_effectuer = 1 --> la boucle ne se répète pas
    //action_effectuer = 0 --> la boucle se répète
    int choix = 0;   //choix = 1 --> positionner jeton
    //choix = 2 --> retirer jeton
    //choix = 3 --> sauvegarder et quitter la partie

    do {
        printf("\n Rentrer 1 si vous voulez positionner un jeton,"
               "\n Rentrer 2 si vous voulez retirer un jeton"
               "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
        scanf("%d", &choix);

        if (choix == 1) {
            action_effectuer = positionner_jeton(grille, grillepuissanceN, symbole, colonne_bloquee, dernierjeton_xy);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 2) {
            action_effectuer = retirer_jeton(grille, grillepuissanceN, symbole, colonne_bloquee);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 3) {
            save(1, colonne_bloquee, grille, grillepuissanceN)
            //sauvegarder et quitter la partie (fonction)
        }
    } while (action_effectuer == 0);

    vainqueur = checkwinner(grille, grillepuissanceN, symbole, dernierjeton_xy);
    return vainqueur;
}

int tour_joueur2(grid grille, char grillepuissanceN[50][50], int *colonne_bloquee, int dernierjeton_xy[2]) {

    char symbole = 'O';
    int vainqueur = 0;
    int action_effectuer = 1;   //action_effectuer = 1 --> la boucle ne se répète pas
    // action_effectuer = 2 --> la boucle se répète
    int choix = 0;   //choix = 1 --> positionner jeton
    //choix = 2 --> retirer jeton
    //choix = 3 --> sauvegarder et quitter la partie

    do {
        printf("\n Rentrer 1 si vous voulez positionner un jeton,"
               "\n Rentrer 2 si vous voulez retirer un jeton"
               "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
        scanf("%d", &choix);

        if (choix == 1) {
            action_effectuer = positionner_jeton(grille, grillepuissanceN, symbole, colonne_bloquee, dernierjeton_xy);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 2) {
            action_effectuer = retirer_jeton(grille, grillepuissanceN, symbole, colonne_bloquee);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 3) {
            //sauvegarder et quitter la partie (fonction)
        }
    } while (action_effectuer == 0);

    vainqueur = checkwinner(grille, grillepuissanceN, symbole, dernierjeton_xy);
    return vainqueur;
}