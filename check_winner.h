//
// Created by mathi on 30/05/2021.
//

#ifndef PROJET_CHECK_WINNER_H
#define PROJET_CHECK_WINNER_H

#include "base.h"

int checkwinner_horizontale(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2]);

int checkwinner_verticale(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2]);

int checkwinner_diagdroite(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2]);

int checkwinner_diaggauche(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2]);

int check_egalite(grid grille, char grillepuissanceN[50][50]);

int checkwinner(grid grille, char grillepuissanceN[50][50], char symbole, int dernierjeton_xy[2]); //fonction principale


#endif //PROJET_CHECK_WINNER_H
