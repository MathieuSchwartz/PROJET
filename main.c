#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "base.h"
#include "save.h"
#include "check_winner.h"
#include "game.h"
#include "actions.h"


int main() {

    int NB_joueur = 2;
    int charger_partie;
    printf("====== Bienvenue dans le jeu puissance N ! ======\n");

    grid grille;
    char grillepuissanceN[50][50];

    menu(&NB_joueur, &charger_partie);

    if (NB_joueur == 2) {
        tour(grillepuissanceN, grille, charger_partie, NB_joueur);
    } else if (NB_joueur == 1){
        tour_avecia(grillepuissanceN, grille, charger_partie, NB_joueur);//tour avec ordi
    }

    return 0;
}
