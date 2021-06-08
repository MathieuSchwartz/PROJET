//
// Created by mathi on 08/06/2021.
//
#include "actions.h"

int positionner_jeton(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee, int dernierjeton_xy[2])
{
    int positionjeton;
    int action_poser;   //si action_poser == 1 alors l'action peut se faire
    //si action_poser == 0 alors l'action ne peut se faire donc on redemande à l'utilisateur
    int i;

    do {
        printf("Dans quelle colonne voulez vous deposer votre jeton ?\n");
        positionjeton = scan_valeur(positionjeton);   //remplace scanf pour pouvoir empêcher la saisie de caractère
        //scanf("%d", &positionjeton);
    } while (positionjeton < 0 || positionjeton > grille.largeur);

    i = grille.hauteur - 1;   //on part du bas du tableau puis on remonte au fur et à mesure que la case ne soit pas remplie
    action_poser = 1;
    while (grillepuissanceN[positionjeton - 1][i] != '_' && i > -1) //positionjeton - 1 pour suivre la logique de l'utilisateur
    {
        i = i - 1;
    }

    if (grillepuissanceN[positionjeton - 1][0] != '_' || positionjeton - 1 == *colonne_bloquee){  //Si un jeton est tout en haut de la colonne
        action_poser = 0;                                                                        // OU que la colonne est bloquée, alors...
        printf("Vous ne pouvez pas placer un jeton dans cette colonne. Erreur colonne : %d\n", positionjeton);
    } else {
        grillepuissanceN[positionjeton - 1][i] = symbole;
        *colonne_bloquee = grille.largeur+1;        // On sort la colonne bloquée de la grille
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
        positionjeton = scan_valeur(positionjeton);   //remplace scanf pour pouvoir empêcher la saisie de caractère
        //scanf("%d", &positionjeton);
    } while (positionjeton < 0 || positionjeton > grille.largeur); //Vérification de la valeur donnée par l'utilisateur


    while (grillepuissanceN[positionjeton - 1][i] != 'X' && grillepuissanceN[positionjeton - 1][i] != 'O'  //On parcourt la grille de haut en bas dans la colonne choisie
           && i < grille.hauteur-1) {                                         //On vérifie si chaque ligne est vide ou non et on passa à la prochaine tant qu'elle est vide
        i = i + 1;                                                              //i correspond donc à la première ligne non vide de la colonne
    }

    if (grillepuissanceN[positionjeton - 1][i] == 'X' || grillepuissanceN[positionjeton - 1][i] == 'O') {
        grillepuissanceN[positionjeton - 1][i] = '_';    // On remplace le signe présent dans la case de ligne "i" par une case vide
        *colonne_bloquee = positionjeton - 1;
    } else if (grillepuissanceN[positionjeton - 1][i] == '_'){ //Si la colonne est complètement vide, on indique que l'action est impossible
        action_retirer = 0;                                    // et on donne la valeur 0 à "action_retirer"
        printf("Vous ne pouvez pas retirer un jeton dans cette colonne. Erreur colonne : %d\n", positionjeton);
    }

    return action_retirer;
}

int positionner_jetonordi(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee, int dernierjeton_xy[2])
{
    int positionjeton;
    int action_poser;   //si action_poser == 1 alors l'action peut se faire
    //si action_poser == 0 alors l'action ne peut se faire donc on redemande à l'utilisateur
    int i;

    positionjeton = rand()%grille.largeur + 1; //pour pas sortir de la grille
    i = grille.hauteur - 1;   //on part du bas du tableau puis on remonte au fur et à mesure que la case ne soit pas remplie
    action_poser = 1;
    while (grillepuissanceN[positionjeton - 1][i] != '_' && i > -1) //positionjeton - 1 pour suivre la logique de l'utilisateur
    {
        i = i - 1;
    }

    if (grillepuissanceN[positionjeton - 1][0] != '_' || positionjeton - 1 == *colonne_bloquee){
        action_poser = 0;
    } else {
        grillepuissanceN[positionjeton - 1][i] = symbole;
        *colonne_bloquee = grille.largeur+1;
        dernierjeton_xy[0] = positionjeton - 1;     //prend la valeur de x
        dernierjeton_xy[1] = i;                     //prend la valeur de y
        printf("L'ordinateur a pose un jeton en postion : %d\n", positionjeton);
    }

    return action_poser;
}

int retirer_jetonordi(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee)
{
    int positionjeton;
    int action_retirer;   //si action_retirer == 0 alors on ne peux pas retirer le jeton
    //si action_retirer == 1 alors le retirage est effectué
    int i = 0;

    action_retirer = 1;
    positionjeton = rand()%grille.largeur;
    while (grillepuissanceN[positionjeton - 1][i] != 'X' && grillepuissanceN[positionjeton - 1][i] != 'O'
           && i < grille.hauteur-1) {
        i = i + 1;
    }

    if (grillepuissanceN[positionjeton - 1][i] == 'X' || grillepuissanceN[positionjeton - 1][i] == 'O') {
        grillepuissanceN[positionjeton - 1][i] = '_';
        *colonne_bloquee = positionjeton - 1;
        printf("L'ordinateur a retire un jeton en colonne : %d\n", positionjeton);
    } else if (grillepuissanceN[positionjeton - 1][i] == '_'){
        action_retirer = 0;
    }

    return action_retirer;
}