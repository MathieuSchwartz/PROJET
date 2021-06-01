//
// Created by mathi on 30/05/2021.
//

#include "check_winner.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "base.h"

int checkwinner_verticale(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2])
{
    int jeton_aligne = 0;
    int vainqueur;
    int position_x = dernierjeton_xy[0];
    int position_y = dernierjeton_xy[1];

    while(grillepuissanceN[position_x][position_y] == symbole && position_y < grille.hauteur)
    {
        jeton_aligne = jeton_aligne + 1;
        position_y = position_y + 1;

    }

    if (jeton_aligne >= grille.N)
    {
        int rejouer;
        printf("Le joueur %c a gagne ! \n", symbole);
        printf("Voulez-vous rejouer ? OUI-->1 NON-->0 \n");
        scanf("%d", &rejouer);

        if(rejouer == 1){
            vainqueur = 1;//lancer fonction nouveau jeu avec initialisation etc..
        } else {
            vainqueur = -1;
            //exit(EXIT_SUCCESS);   //on quitte le programme le joueur a gagné
        }
    } else {
        vainqueur = 0;
    }
    return vainqueur;
}

int checkwinner_horizontale(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2])
{
    int jeton_aligne;
    int j;
    int position_x;
    int position_y = dernierjeton_xy[1];

    for (position_x = dernierjeton_xy[0] - grille.N ; position_x < dernierjeton_xy[0] + 1 ; position_x = position_x + 1)
    {
        jeton_aligne = 0;
        if (position_x > -1 && position_x < grille.largeur)
        {
            j = position_x;
            while(grillepuissanceN[j][position_y] == symbole && j < grille.largeur)
            {
                jeton_aligne = jeton_aligne + 1;
                j = j + 1;
            }

            if (jeton_aligne >= grille.N)
            {
                int rejouer;
                position_x = dernierjeton_xy[0];   //pour sortir de la boucle au cas oû
                printf("Le joueur %c a gagne ! \n", symbole);
                printf("Voulez-vous rejouer ? OUI-->1 NON-->0 \n");
                scanf("%d", &rejouer);

                if(rejouer == 1){
                    return 1;//lancer fonction nouveau jeu avec initialisation etc..
                } else {
                    return 3;
                    //exit(EXIT_SUCCESS);   //on quitte le programme le joueur a gagné   //on quitte le programme le joueur a gagné
                }
            }
        }
    }
    return 0;
}

int check_egalite(grid grille, char grillepuissanceN[50][50])
{
    int i = 0;
    int rejouer;

    while (grillepuissanceN[i][0] != '_' && i < grille.largeur)
    {
        i = i + 1;
    }

    if (i == grille.largeur)
    {
        printf("Egalite ! Voulez-vous rejouer une partie ? (OUI-->1, NON-->0)\n");
        scanf("%d", &rejouer);

        if(rejouer == 1){
            return 1;//lancer fonction nouveau jeu avec initialisation etc..
        } else {
            return 3;
            //exit(EXIT_SUCCESS);   //on quitte le programme le joueur a gagné
        }
    } else {
        return 0;
    }
}

int checkwinner_diagdroite(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2])
{
    int jeton_aligne;
    int vainqueur;
    int j;
    int i;
    int position_x = dernierjeton_xy[0] - grille.N + 1;
    int position_y = dernierjeton_xy[1] + grille.N - 1;

    while(position_x < dernierjeton_xy[0] + 1 && position_y > dernierjeton_xy[1] - 1 )
    {
        jeton_aligne = 0;
        if (position_x > -1 && position_x < grille.largeur && position_y > -1 && position_y < grille.largeur) {
            j = position_x;
            i = position_y;
            while (grillepuissanceN[j][i] == symbole && j < grille.largeur && i < grille.largeur) {
                jeton_aligne = jeton_aligne + 1;
                j = j + 1;   //j = position en x
                i = i - 1;   //i = position en y puis on monte en diagonale droite
            }

            if (jeton_aligne >= grille.N) {
                int rejouer;
                position_x = dernierjeton_xy[0]; //pour sortir de la boucle au cas oû
                position_y = dernierjeton_xy[1];
                printf("Le joueur %c a gagne ! \n", symbole);
                printf("Voulez-vous rejouer ? OUI-->1 NON-->0 \n");
                scanf("%d", &rejouer);

                if (rejouer == 1) {
                    vainqueur = 1;//lancer fonction nouveau jeu avec initialisation etc..
                } else {
                    vainqueur = 3;
                    //exit(EXIT_SUCCESS);   //on quitte le programme le joueur a gagné
                }
            } else if (jeton_aligne < grille.N){
                vainqueur = 0;
            }
        }
        position_x = position_x + 1;
        position_y = position_y - 1;
    }
    return vainqueur;
}

int checkwinner_diaggauche(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2])
{
    int jeton_aligne;
    int j;
    int i;
    int position_x = dernierjeton_xy[0] + grille.N - 1;
    int position_y = dernierjeton_xy[1] + grille.N - 1;

    while(position_x > dernierjeton_xy[0] - 1 && position_y > dernierjeton_xy[1] - 1 )
    {
        jeton_aligne = 0;
        if (position_x > -1 && position_x < grille.largeur && position_y > -1 && position_y < grille.largeur) {
            j = position_x;
            i = position_y;
            while (grillepuissanceN[j][i] == symbole && j < grille.largeur && i < grille.largeur) {
                jeton_aligne = jeton_aligne + 1;
                j = j - 1;   //j = position en x
                i = i - 1;   //i = position en y puis on monte en diagonale gauche
            }

            if (jeton_aligne >= grille.N) {
                int rejouer;
                position_x = dernierjeton_xy[0]; //pour sortir de la boucle au cas oû
                position_y = dernierjeton_xy[1];
                printf("Le joueur %c a gagne ! \n", symbole);
                printf("Voulez-vous rejouer ? OUI-->1 NON-->0 \n");
                scanf("%d", &rejouer);

                if (rejouer == 1) {
                    return 1;//lancer fonction nouveau jeu avec initialisation etc..
                } else {
                    return 3;
                    //exit(EXIT_SUCCESS);   //on quitte le programme le joueur a gagné
                }
            }
        }
        position_x = position_x - 1;
        position_y = position_y - 1;
    }
    return 0;
}

int checkwinner(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2])
{
    int vainqueur;  //si vainqueur == 0 -> le jeu continue, aucun vainqueur
    //si vainqueur == 1 -> le jeu s'arrête, vainqueur trouvé
    //si vainqueur == -1 -> égalité entre les deux joueurs, le jeu s'arrête


    vainqueur = checkwinner_verticale(grille, grillepuissanceN, symbole, dernierjeton_xy);
    if (vainqueur == 0) { //on vérifie
        vainqueur = checkwinner_horizontale(grille, grillepuissanceN, symbole, dernierjeton_xy);
        if (vainqueur == 0) {
            vainqueur = checkwinner_diagdroite(grille, grillepuissanceN, symbole, dernierjeton_xy);
            if (vainqueur == 0) {
                vainqueur = checkwinner_diaggauche(grille, grillepuissanceN, symbole, dernierjeton_xy);
                if (vainqueur == 0) {
                    vainqueur = check_egalite(grille, grillepuissanceN);
                }
            }
        }
    }
    printf("%d", vainqueur);
    return vainqueur;
}