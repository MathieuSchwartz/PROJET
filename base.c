//
// Created by Elève on 25/05/2021.
//

#include "base.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "check_winner.h"
#include "save.h"
#include "actions.h"


grid def_grille(grid grille)
{
    do {
        printf("Combien de jetons voulez-vous aligner pour gagner ? \n");
        grille.N = scan_valeur(grille.N);
        //scanf("%d", &grille.N);
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

int choixjoueur(int joueur1or2)
{
    srand(time(0));
    joueur1or2 = rand()% 2 + 1;    //si '1' est tiré alors le joueur jaune commence,
    //si '2' est tiré alors le joueur rouge commence

    if (joueur1or2 == 1)
    {
        printf("Le joueur 1 commence.\n");
    } else if (joueur1or2 == 2)
    {
        printf("Le joueur 2 commence.\n");
    }

    return joueur1or2;
}

/**
 * Permet de savoir si il y a des jetons dans la grille pour permettre l'affichage des différents choix
 * @param grille
 * @param grillepuissanceN
 * @return 1 si il y a déjà des jetons ou 0 si il n'y a pas encore de jetons
 */
int jetonsdanslagrille(grid grille, char grillepuissanceN[50][50])
{
    int i = 0;

    while (grillepuissanceN[i][grille.hauteur-1] == '_' && i < grille.largeur)
    {
        i = i + 1;
    }

    if (i == grille.largeur)
    {
        return 0; //si pas de jetons dans la grille, on retourne 0
    } else {
        return 1; // si jetons dans la grille, on retourne 1
    }
}

void menu(int *NB_joueur, int *charger_partie)
{
    int partiesauvegarder_existe; // ==1 --> on propose de charger une partie car elle existe
    // == 2 --> on ne propose pas car aucune partie sauvegardée
    partiesauvegarder_existe = verif_partiesauvegarde("projet.txt", &NB_joueur);

    if (partiesauvegarder_existe == 1) {
        do {
            printf("Demarrer une nouvelle partie (0)\n"
                   "Charger une partie (1)\n"
                   "Quitter (2)\n");
            fflush(stdin);
            scanf("%d", &*charger_partie);
        } while (*charger_partie != 0 && *charger_partie != 1 && *charger_partie != 2);
    } else {
        do {
            printf("Demarrer une nouvelle partie (0)\n"
                   "Quitter (2)\n");
            fflush(stdin);
            scanf("%d", &*charger_partie);
        } while (*charger_partie != 0 && *charger_partie != 2);
    }
    if(*charger_partie == 0) {
        do {
            printf("Voulez-vous jouer seul ou a deux ?\n");
            *NB_joueur = scan_valeur(*NB_joueur);   //remplace scanf pour pouvoir empêcher la saisie de caractère
            //scanf("%d", &*NB_joueur);
        }  while (*NB_joueur != 1 && *NB_joueur != 2);
    } else if (*charger_partie == 2)
    {
        *NB_joueur = 0;
    }
}

int scan_valeur(int valeur)
{
    char chaine[100];

    fflush(stdin);
    gets(chaine);
    valeur = atoi(chaine);

    if (valeur == 0)
    {
        printf("Merci de saisir une saisie valable.\n");
    }
    return valeur;
}