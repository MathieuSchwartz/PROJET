//
// Created by mathi on 31/05/2021.
//

#ifndef PROJET_SAVE_H
#define PROJET_SAVE_H

#include "base.h"
#include "check_winner.h"

void save(int joueur1or2, int colonne_bloquee, grid grille, char grillepuissanceN[50][50],char slot[30]);

int load(int *joueur1or2,int * colonne_bloquee, grid * grille, char slot[30], char grillepuissanceN[50][50]);

#endif //PROJET_SAVE_H
