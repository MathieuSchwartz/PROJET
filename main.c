#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Fonctions.h"


int main() {


    grid grille;
    grille = def_grille(grille);
    char grillepuissanceN[grille.largeur][grille.hauteur];

    initialisation_grille(grille, grillepuissanceN);
    afficher_grille(grille, grillepuissanceN);

    int joueur1or2;
    srand(time(0));
    joueur1or2 = rand() % 2 + 1;    //si '1' est tiré alors le joueur jaune commence,
                                    //si '2' est tiré alors le joueur rouge commence

     //test pour voir si les fonctions marchent  (version pas finale)
    char symbolejoueurjaune = 'X';      //le joueur jaune sera le joueur 1
    char symbolejoueurrouge = 'O';      //le joueur rouge sera le joueur 2
    /*
     positionner_jeton(grille, grillepuissanceN, symbolejoueurjaune);
    afficher_grille(grille, grillepuissanceN);
    positionner_jeton(grille, grillepuissanceN, symbolejoueurrouge);
    afficher_grille(grille, grillepuissanceN);
    retirer_jeton(grille, grillepuissanceN, symbolejoueurjaune);
    afficher_grille(grille, grillepuissanceN);
    retirer_jeton(grille, grillepuissanceN, symbolejoueurrouge);
    afficher_grille(grille, grillepuissanceN);
    */

   tour(joueur1or2,grillepuissanceN, grille);

    return 0;
}