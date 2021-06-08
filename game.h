//
// Created by Elève on 08/06/2021.
//

#ifndef PROJET_GAME_H
#define PROJET_GAME_H

#include "base.h"
#include "actions.h"
#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tour_joueur2(grid grille, char grillepuissanceN[50][50],int * colonne_bloquee, int dernierjeton_xy[2], int NB_joueur);

int tour_joueur1(grid grille, char grillepuissanceN[50][50], int * colonne_bloquee, int dernierjeton_xy[2], int NB_joueur);

int tour_ordi(grid grille, char grillepuissanceN[50][50], int * colonne_bloquee, int dernierjeton_xy[2]);

void tour(char grillepuissanceN[50][50], grid grille, int charger_partie, int NB_joueur);

void tour_avecia(char grillepuissanceN[50][50], grid grille, int charger_partie, int NB_joueur);

#endif //PROJET_GAME_H