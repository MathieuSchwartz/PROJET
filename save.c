//
// Created by mathi on 31/05/2021.
//

#include "base.h"
#include "save.h"
#include <stdio.h>
#include <stdlib.h>


int save(int joueur1or2, int colonne_bloquee, grid grille, char grillepuissanceN[50][50],char slot[30], int type_partie){

    FILE* file= fopen(slot,"w");//Crée un fichier

    if (file == NULL){
        printf("La partie n'as pas pu être sauvegardé\n");
        return 0;    //retourne 0 pour dire que la partie n'est pas sauvegardé et que l'utilisateur doit daire autre chose
    } else {

        fprintf(file, "1\n");
        fprintf(file, "%d\n", type_partie); //enregistre le NB de joueur , 1 si avec ordi, 2 si contre quelqu'un
        fprintf(file, "%d\n", grille.largeur);//Erengistre le nombre de case de la grille
        fprintf(file, "%d\n", joueur1or2);//Enrengistre le tour du joueur
        fprintf(file, "%d\n", colonne_bloquee);//Enrengistre la colonne interdite
        for (int i = 0; i < grille.hauteur; ++i) {

            for (int j = 0; j < grille.largeur; ++j) {

                fprintf(file, "%c", grillepuissanceN[j][i]); //Enrengistre les valeurs de la grille
                fprintf(file, "\n");
            }
            //fprintf(file,"\n");
        }
        fclose(file);
        return 1;  //pour dire que la partie a bien été sauvegardé
    }
}


int load(int *joueur1or2 ,int *colonne_bloquee, grid* grille, char slot[30], char grillepuissanceN[50][50]) {

    FILE *file = fopen(slot, "r");//Ouverture du fichier

    if (file == NULL) {
        printf("Fichier inexistant\n"); //Vérifie que le fichier à bien été ouvert
        return 1;  //le chargement a été mal effectué
    } else {

        char ligne[100];

        fgets(ligne, 5, file);   //sert juste à sauter une ligne car la première valeur ne nous intéresse pas
        fgets(ligne, 5, file);   //de même
        fgets(ligne, 5, file);
        grille->largeur = atoi(ligne);
        grille->hauteur = grille->largeur;
        grille->N = grille->largeur - 2;

        fgets(ligne, 5, file);
        *joueur1or2 = atoi(ligne);

        fgets(ligne, 5, file);
        *colonne_bloquee = atoi(ligne);

        for (int i = 0; i < grille->largeur; i++) {
            for (int j = 0; j < grille->largeur; j++) {
                fgets(&grillepuissanceN[j][i], 50, file);//Récuperation des valeurs du tableau
            }
        }
        fclose(file);
        return 0; //le chargement de la partie s'est bien effectué
    }
}

//faire fonction por écraser la partie lorque un joueur gagne ou égalité
//ne pas proposer de charger la partie lorsque la vérification du fichier vide est faite

int verif_partiesauvegarde(char slot[30], int **NB_joueur)
{
    int verification; //verifie si une partie est sauvegardé ou si aucune partie sauvegardé
    // si verification == 0 alors pas de partie sauvegardé donc on ne propose pas à l'utilisateur de charger une partie
    // si verification == 1 alors partie sauvegardé existante donc on peut proposer de suavegarder une partie

    FILE *file = fopen(slot, "r");//Ouverture du fichier

    if (file == NULL) {
        printf("Erreur programme !!\n"); //Vérifie que le fichier à bien été ouvert
        return 1;  //le chargement a été mal effectué
    } else {

        char ligne[100];

        fgets(ligne, 5, file);   //on reagarde si c'est 0 ou 1 pour savoir si il y a une partie sauvegardé
        verification = atoi(ligne);

        if (verification == 1) {
            fgets(ligne, 5, file);    //on récupère le nb de joeur pour savoir si c'est avec un ordi
            **NB_joueur = atoi(ligne);
        }

        fclose(file);

        if (verification == 1){
            return 1; //on peux proposer à l'utilisateur de charger une partie
        } else {
            return 0;  //l'utilisteur ne peux pas charger une partie
        }
    }
}

void ecraser_partie(char slot[30])
{
    FILE *file = fopen(slot, "w");//Ouverture du fichier

    if (file == NULL) {
        printf("Le partie n'as pas pu être écrase\n");
    } else {

        fprintf(file, "0\n");

        fclose(file);
    }
}