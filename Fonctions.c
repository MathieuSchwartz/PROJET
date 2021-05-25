//
// Created by mathi on 25/05/2021.
//

#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

grid def_grille(grid grille)
{
    do {
        printf("Combien de jetons voulez-vous aligner pour gagner ? \n");
        scanf("%d", &grille.N);
    } while ( grille.N < 1 || grille.N > 48); //car limite tableau = 50 donc 50-2 = 48
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

int positionner_jeton(grid grille, char grillepuissanceN[50][50], char symbole)
{
    int positionjeton;
    int action_poser;   //si action_poser == 1 alors l'action peut se faire
    //si action_poser == 0 alors l'action ne peut se faire donc on redemande à l'utilisateur
    int i;

    do {
        printf("Dans quelle colonne voulez vous déposer votre jeton ?\n");
        scanf("%d", &positionjeton);
    } while (positionjeton < 0 || positionjeton > grille.largeur);

    i = grille.hauteur - 1;   //on part du bas du tableau puis on remonte au fur et à mesure que la case ne soit pas remplie
    action_poser = 1;
    while (grillepuissanceN[positionjeton - 1][i] != '_' && i > -1) //positionjeton - 1 pour suivre la logique de l'utilisateur
    {
        i = i - 1;
    }

    if (grillepuissanceN[positionjeton - 1][0] != '_'){
        action_poser = 0;
    }
    grillepuissanceN[positionjeton - 1][i] = symbole;

    return action_poser;
}

int retirer_jeton(grid grille, char grillepuissanceN[50][50], char symbole)
{
    int positionjeton;
    int action_retirer;   //si action_retirer == 0 alors on ne peux pas retirer le jeton et on redemande une autre position
    //si action_retirer == 1 alors le retirage est effectué
    int i = 0;

    do {
        action_retirer = 1;
        printf("Dans quelle colonne voulez vous retirer votre jeton ?\n");
        scanf("%d", &positionjeton);
    } while (positionjeton < 0 || positionjeton > grille.largeur);


    while (grillepuissanceN[positionjeton - 1][i] == '_' && i < grille.hauteur) {
        i = i + 1;
    }

    if (grillepuissanceN[positionjeton - 1][i] != '_') {
        grillepuissanceN[positionjeton - 1][i] = '_';
    } else {
        action_retirer = 0;
    }

    return action_retirer;
}

int tour(int joueur1or2, char grillepuissanceN[50][50], grid grille){

    int choix=0 ; //choix = 1 --> positionner jeton
                  //choix = 2 --> retirer jeton
                  //choix = 3 --> sauvegarder et quitter la partie


    if (joueur1or2 == 1){
        printf("Le joueur 1 commence...\n");
        char symbole = 'X' ;

        printf(  "\n Rentrer 1 si vous voulez positionner un jeton,"
                        "\n Rentrer 2 si vous voulez retirer un jeton"
                        "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
        scanf("%d", &choix);

        if (choix == 1){
            positionner_jeton(grille,grillepuissanceN, symbole);
        }else if(choix == 2){
            retirer_jeton(grille, grillepuissanceN, symbole);
        }else if (choix == 3){
            //sauvegarder et quitter la partie (fonction)
        }

        printf("C'est au tour du joueur 2...\n");
        symbole = 'O' ;

        printf(  "\n Rentrer 1 si vous voulez positionner un jeton,"
                 "\n Rentrer 2 si vous voulez retirer un jeton"
                 "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
        scanf("%d", &choix);

        if (choix == 1){
            positionner_jeton(grille,grillepuissanceN, symbole);
        }else if(choix == 2){
            retirer_jeton(grille, grillepuissanceN, symbole);
        }else if (choix == 3){
            //sauvegarder et quitter la partie (fonction)
        }

    }else if (joueur1or2 == 2){
        printf("Le joueur 2 commence...\n");
        char symbole = 'O' ;

        printf(  "\n Rentrer 1 si vous voulez positionner un jeton,"
                 "\n Rentrer 2 si vous voulez retirer un jeton"
                 "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
        scanf("%d", &choix);

        if (choix == 1){
            positionner_jeton(grille,grillepuissanceN, symbole);
        }else if(choix == 2){
            retirer_jeton(grille, grillepuissanceN, symbole);
        }else if (choix == 3){
            //sauvegarder et quitter la partie (fonction)
        }

        printf("C'est au tour du joueur 1...\n");
        symbole = 'X' ;

        printf(  "\n Rentrer 1 si vous voulez positionner un jeton,"
                 "\n Rentrer 2 si vous voulez retirer un jeton"
                 "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
        scanf("%d", &choix);

        if (choix == 1){
            positionner_jeton(grille,grillepuissanceN, symbole);
        }else if(choix == 2){
            retirer_jeton(grille, grillepuissanceN, symbole);
        }else if (choix == 3){
            //sauvegarder et quitter la partie (fonction)
        }

    }

}

