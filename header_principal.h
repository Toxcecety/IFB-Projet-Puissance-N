#ifndef PROJET_PUISSANCE_N_HEADER_PRINCIPAL_H
#define PROJET_PUISSANCE_N_HEADER_PRINCIPAL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/**
 * @file header_principal.h
 * @brief fichier header contenant les bibliothèques standards, les structures et les autres headers du projet
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Structure définissant notre Grille : la grille (tableau 2D de caractères), sa largeur et sa longueur
 */
typedef struct {
    char** grille;
    int largeur;
    int longueur;
}Grid;

/**
 * Structure définissant les coordonnées du point d'origine des diagonales : abscisse et ordonnée
 */
typedef struct {
    int abscisse;
    int ordonnee;
}Origine;

/**
 * Structure définissant les caractéristiques des joueurs : couleur, initiative et type de jeton
 */
typedef struct {
    char couleur;
    int initiative;
    char jeton;
}Joueur;

#include "gestion_grille.h"
#include "ajout_retrait_jetons.h"
#include "jeu.h"
#include "ordinateur.h"
#include "check_winner.h"

#endif //PROJET_PUISSANCE_N_HEADER_PRINCIPAL_H
