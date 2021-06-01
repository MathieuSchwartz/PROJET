//
// Created by mathi on 31/05/2021.
//

#include "base.h"
#include "save.h"
#include <stdio.h>

void save(char joueur1or2, int colonne_bloquee, grid grille, char grillepuissanceN[50][50],char slot[30]){

    FILE* file= fopen(slot,"w");//Crée un fichier

    fprintf(file,"%d\n",grille.largeur);//Erengistre le nombre de case de la grille
    fprintf(file,"%c\n",joueur1or2);//Enrengistre le tour du joueur
    fprintf(file,"%d\n",colonne_bloquee);//Enrengistre la colonne interdite
    for (int i = 0; i < grille.largeur; ++i) {

        for (int j = 0; j < grille.largeur; ++j) {

            fprintf(file,"%c\n",grillepuissanceN[i][j]); //Enrengistre les valeurs de la grille

        }

    }

}

int load(char *joueur1or2,int * colonne_bloquee, grid * grille, char slot[30], char grillepuissanceN[50][50]){

    FILE* file= fopen(slot, "r");//Ouverture du fichier

    if (file==NULL){
        printf("Fichier inexistant\n"); //Vérifie que le fichier à bien été ouvert
    }else{

        char buffer_string[11];int buffer_int;//Memoire d'un string et d'un integrer

        fgets(buffer_string,5,file); //Recuperation de la taille de la grille
        sscanf((const char *) &buffer_string, "%d", &buffer_int);
       //---------------------------------------------------------------------------------
        initialisation_grille(*grille,grillepuissanceN);//Creation de la grille           //defectueux
       //---------------------------------------------------------------------------------

        fgets(joueur1or2,10,file);//Recuperation du tour de la personne qui doit jouer


        fgets(buffer_string,5,file);//Recuperation de la colonne interdite
        sscanf((const char *) &buffer_string, "%d", colonne_bloquee);

        for (int i = 0; i < (*grille).largeur; ++i) {

            for (int j = 0; j < (*grille).largeur; ++j) {

                fgets(&grillepuissanceN[i][j],10,file);//Récuperation des valeurs du tableau

            }

        }
    }

}