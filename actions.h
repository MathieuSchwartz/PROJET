//
// Created by mathi on 08/06/2021.
//
#ifndef PROJET_ACTIONS_H
#define PROJET_ACTIONS_H

#include "base.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Permet de positionner le jeton en prenant en paramètre le symbole du joueur
 */
int positionner_jeton(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee, int dernierjeton_xy[2]);  //section2

/*
 * Permet de retirer le jeton en prenant en paramètre le symbole du joueur
 */
int retirer_jeton(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee);     //section2


int positionner_jetonordi(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee, int dernierjeton_xy[2]);

int retirer_jetonordi(grid grille, char grillepuissanceN[50][50], char symbole, int * colonne_bloquee);

#endif //PROJET_ACTIONS_H