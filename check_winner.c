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
            //lancer fonction nouveau jeu avec initialisation etc..
        } else {
            exit( EXIT_SUCCESS );   //on quitte le programme le joueur a gagné
        }
    } else {
        return 0;
    }

}

int checkwinner_horizontale(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2])
{
    int jeton_aligne;
    int j;
    int position_x;
    int position_y = dernierjeton_xy[1];

    for (position_x = dernierjeton_xy[0] - grille.N ; position_x < dernierjeton_xy[0] + 1 ; position_x++ )
    {
        if (position_x > -1 && position_x < grille.largeur)
        {
            jeton_aligne = 0;
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
                    //lancer fonction nouveau jeu avec initialisation etc..
                } else {
                    exit( EXIT_SUCCESS );   //on quitte le programme le joueur a gagné
                }
            } else {
                return 0;
            }

        }
    }
}

int check_egalite(grid grille, char grillepuissanceN[50][50])
{
    int i = 0;
    int rejouer;

    while (grillepuissanceN[i][0] != '_' && i < grille.largeur - 1)
    {
        i = i + 1;
    }

    if (i == grille.largeur - 1)
    {
        printf("Egalite ! Voulez-vous rejouer une partie ? (OUI-->1, NON-->0)\n");
        scanf("%d", &rejouer);

        if(rejouer == 1){
            //lancer fonction nouveau jeu avec initialisation etc..
        } else {
            exit( EXIT_SUCCESS );   //on quitte le programme le joueur a gagné
        }
    } else {
        return 0;
    }
    return 0;
}

int checkwinner(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2])
{
    int vainqueur;  //si vainqueur == 0 -> le jeu continue, aucun vainqueur
    //si vainqueur == 1 -> le jeu s'arrête, vainqueur trouvé
    //si vainqueur == -1 -> égalité entre les deux joueurs, le jeu s'arrête

    vainqueur = check_egalite(grille, grillepuissanceN);
    vainqueur = checkwinner_verticale(grille, grillepuissanceN, symbole, dernierjeton_xy);
    vainqueur = checkwinner_horizontale(grille, grillepuissanceN, symbole, dernierjeton_xy);

    return vainqueur;

}