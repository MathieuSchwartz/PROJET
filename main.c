#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "base.h"


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
    tour(joueur1or2, grillepuissanceN, grille);


    return 0;
}
