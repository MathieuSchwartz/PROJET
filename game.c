//
// Created by Elève on 08/06/2021.
//

#include "game.h"


void tour(char grillepuissanceN[50][50], grid grille, int charger_partie, int NB_joueur) {

    int colonne_bloquee = grille.largeur + 1; //la colonne bloquee n'as aucun impacte sur la grille de jeu
    int vainqueur = 0;
    int dernierjeton_xy[2];                   //tableau avec la position du dernier jeton posé, ex {1,5}
    // donc le jeton est posé en x=1 et y=5 dans le tableau
    int erreur_chargement = 0;    //si erreur_chargement == 0, le jeu se démarre
    // sinon si erreur_chargement == le jeu ne démarre pas
    int nouvelle_partie = 1;
    do {
        int joueur1or2 = 0;
        if (charger_partie == 0) {
            grille = def_grille(grille);  //taille de la grille
            initialisation_grille(grille, grillepuissanceN);
            joueur1or2 = choixjoueur(joueur1or2);
        } else if(charger_partie == 1){
            charger_partie = 0;
            erreur_chargement = load(&joueur1or2, &colonne_bloquee, &grille, "projet.txt", grillepuissanceN);
        }

        if (joueur1or2 == 1 && erreur_chargement == 0) {
            afficher_grille(grille, grillepuissanceN);
            do {
                printf("C'est au tour du joueur 1...\n");
                vainqueur = tour_joueur1(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy, NB_joueur);
                if (vainqueur == 0) {
                    printf("C'est au tour du joueur 2...\n");
                    vainqueur = tour_joueur2(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy, NB_joueur);
                }
            } while (vainqueur == 0);
        } else if (joueur1or2 == 2 && erreur_chargement == 0) {
            afficher_grille(grille, grillepuissanceN);
            do {
                printf("C'est au tour du joueur 2...\n");
                vainqueur = tour_joueur2(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy, NB_joueur);
                if (vainqueur == 0) {
                    printf("C'est au tour du joueur 1...\n");
                    vainqueur = tour_joueur1(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy, NB_joueur);
                }
            } while (vainqueur == 0);
        }
        nouvelle_partie = vainqueur;
    } while (nouvelle_partie ==1);  //si vainqueur == 1 alors on recommence une partie
    // si vainqueur == 3 alors fin du programme
}

int tour_joueur1(grid grille, char grillepuissanceN[50][50], int *colonne_bloquee, int dernierjeton_xy[2], int NB_joueur) {

    int joueur1or2 = 1;
    char symbole = 'X';
    int vainqueur = 0;
    int presence_jeton; //si 0 --> pas de jetons dans la grille donc on ne peut pas retirer un jeton
    //si 1 --> jetons dans la grille donc on peut retirer un jeton
    int action_effectuer = 1;   //action_effectuer = 1 --> la boucle ne se répète pas
    //action_effectuer = 0 --> la boucle se répète
    int choix = 0;   //choix = 1 --> positionner jeton
    //choix = 2 --> retirer jeton
    //choix = 3 --> sauvegarder et quitter la partie

    do {
        presence_jeton = jetonsdanslagrille(grille, grillepuissanceN);
        if (presence_jeton == 0){    //si il n'y  a pas encore de jetons
            do {
                printf("\n Rentrer 1 si vous voulez positionner un jeton,"
                       "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
                choix = scan_valeur(choix);   //remplace scanf pour pouvoir empêcher la saisie de caractère
                //scanf("%d", &choix);
            } while(choix < 1 || choix > 3 || choix == 2);

        } else if (presence_jeton == 1) {  //si déjà des jetons
            do {
                printf("\n Rentrer 1 si vous voulez positionner un jeton,"
                       "\n Rentrer 2 si vous voulez retirer un jeton"
                       "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
                choix = scan_valeur(choix);   //remplace scanf pour pouvoir empêcher la saisie de caractère
                //scanf("%d", &choix);
            } while (choix < 1 || choix > 3);
        }

        if (choix == 1) {
            action_effectuer = positionner_jeton(grille, grillepuissanceN, symbole, colonne_bloquee, dernierjeton_xy);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 2) {
            action_effectuer = retirer_jeton(grille, grillepuissanceN, symbole, colonne_bloquee);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 3) {
            //action_effectuer = 1;  //pour sotir de la boucle
            action_effectuer = save(joueur1or2, *colonne_bloquee, grille, grillepuissanceN, "projet.txt", NB_joueur);
            printf("Partie sauvegardee");
            return 3;//sauvegarder et quitter la partie (fonction) et on quitten le programme avec 3
        }
    } while (action_effectuer == 0);

    vainqueur = checkwinner(grille, grillepuissanceN, symbole, dernierjeton_xy);
    return vainqueur;
}

int tour_joueur2(grid grille, char grillepuissanceN[50][50], int *colonne_bloquee, int dernierjeton_xy[2], int NB_joueur) {

    int joueur1or2 = 2;
    char symbole = 'O';
    int vainqueur = 0;
    int presence_jeton; //si 0 --> pas de jetons dans la grille donc on ne peut pas retirer un jeton
    //si 1 --> jetons dans la grille donc on peut retirer un jeton
    int action_effectuer = 1;   //action_effectuer = 1 --> la boucle ne se répète pas
    // action_effectuer = 2 --> la boucle se répète
    int choix = 0;   //choix = 1 --> positionner jeton
    //choix = 2 --> retirer jeton
    //choix = 3 --> sauvegarder et quitter la partie

    do {
        presence_jeton = jetonsdanslagrille(grille, grillepuissanceN);
        if (presence_jeton == 0){    //si il n'y  a pas encore de jetons
            do {
                printf("\n Rentrer 1 si vous voulez positionner un jeton,"
                       "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
                choix = scan_valeur(choix);   //remplace scanf pour pouvoir empêcher la saisie de caractère
                //scanf("%d", &choix);
            } while(choix < 1 || choix > 3 || choix == 2);

        } else if (presence_jeton == 1) {  //si déjà des jetons
            do {
                printf("\n Rentrer 1 si vous voulez positionner un jeton,"
                       "\n Rentrer 2 si vous voulez retirer un jeton"
                       "\n Rentrer 3 si vous voulez sauvegarder la partie et la quitter\n");
                choix = scan_valeur(choix);   //remplace scanf pour pouvoir empêcher la saisie de caractère
                //scanf("%d", &choix);
            } while (choix < 1 || choix > 3);
        }
        if (choix == 1) {
            action_effectuer = positionner_jeton(grille, grillepuissanceN, symbole, colonne_bloquee, dernierjeton_xy);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 2) {
            action_effectuer = retirer_jeton(grille, grillepuissanceN, symbole, colonne_bloquee);
            afficher_grille(grille, grillepuissanceN);
        } else if (choix == 3) {
            //action_effectuer = 1;
            action_effectuer = save(joueur1or2, *colonne_bloquee, grille, grillepuissanceN, "projet.txt", NB_joueur);
            printf("Partie sauvegardee");
            return 3;//sauvegarder et quitter la partie (fonction)
        }
    } while (action_effectuer == 0);

    vainqueur = checkwinner(grille, grillepuissanceN, symbole, dernierjeton_xy);
    return vainqueur;     //retourne 0 si pas de gagnants
    // 1 si gagnant
    //-1 si égalité
}

int tour_ordi(grid grille, char grillepuissanceN[50][50], int *colonne_bloquee, int dernierjeton_xy[2]) {

    char symbole = 'O';
    int vainqueur = 0;
    int action_effectuer = 1;   //action_effectuer = 1 --> la boucle ne se répète pas
    //action_effectuer = 0 --> la boucle se répète
    int presence_jeton; //si 0 --> pas de jetons dans la grille donc on ne peut pas retirer un jeton
    //si 1 --> jetons dans la grille donc on peut retirer un jeton
    int choix = 0;   //choix = 1 --> positionner jeton
    //choix = 2 --> retirer jeton
    //choix = 3 --> sauvegarder et quitter la partie

    presence_jeton = jetonsdanslagrille(grille, grillepuissanceN);
    if (presence_jeton == 1) {
        do {
            choix = rand() % 5;
            if (choix >= 0 && choix <= 3) {
                action_effectuer = positionner_jetonordi(grille, grillepuissanceN, symbole, colonne_bloquee,
                                                         dernierjeton_xy);
            } else if (choix >= 4) {
                action_effectuer = retirer_jetonordi(grille, grillepuissanceN, symbole, colonne_bloquee);
            }
        } while (action_effectuer == 0);
    } else if (presence_jeton == 0)
    {
        action_effectuer = positionner_jetonordi(grille, grillepuissanceN, symbole, colonne_bloquee,
                                                 dernierjeton_xy);
    }
    afficher_grille(grille, grillepuissanceN);
    vainqueur = checkwinner(grille, grillepuissanceN, symbole, dernierjeton_xy);
    return vainqueur;
}

void tour_avecia(char grillepuissanceN[50][50], grid grille, int charger_partie, int NB_joueur)
{
    int colonne_bloquee = grille.largeur + 1; //la colonne bloquee n'as aucun impacte sur la grille de jeu
    int vainqueur = 0;
    int dernierjeton_xy[2];                   //tableau avec la position du dernier jeton posé, ex {1,5}
    // donc le jeton est posé en x=1 et y=5 dans le tableau
    int erreur_chargement = 0;    //si erreur_chargement == 0, le jeu se démarre
    // sinon si erreur_chargement == le jeu ne démarre pas
    int nouvelle_partie = 1;
    do {
        int joueur1or2 = 0;
        if (charger_partie == 0) {
            grille = def_grille(grille);  //taille de la grille
            initialisation_grille(grille, grillepuissanceN);
            joueur1or2 = choixjoueur(joueur1or2);
        } else if(charger_partie == 1){
            charger_partie = 0;
            erreur_chargement = load(&joueur1or2, &colonne_bloquee, &grille, "projet.txt", grillepuissanceN);
        }

        if (joueur1or2 == 1 && erreur_chargement == 0) {
            afficher_grille(grille, grillepuissanceN);
            do {
                printf("C'est au tour du joueur 1...\n");
                vainqueur = tour_joueur1(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy, NB_joueur);
                if (vainqueur == 0) {
                    printf("\nC'est au tour de l'ordi...\n\n");
                    vainqueur = tour_ordi(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy);
                }
            } while (vainqueur == 0);
        } else if (joueur1or2 == 2 && erreur_chargement == 0) {
            afficher_grille(grille, grillepuissanceN);
            do {
                printf("\nC'est au tour de l'oridinateur...\n\n");
                vainqueur = tour_ordi(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy);
                if (vainqueur == 0) {
                    printf("C'est au tour du joueur 1...\n");
                    vainqueur = tour_joueur1(grille, grillepuissanceN, &colonne_bloquee, dernierjeton_xy, NB_joueur);
                }
            } while (vainqueur == 0);
        }
        nouvelle_partie = vainqueur;
    } while (nouvelle_partie ==1);  //si vainqueur == 1 alors on recommence une partie
    // si vainqueur == 3 alors fin du programme
}