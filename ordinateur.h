#ifndef PROJET_PUISSANCE_N_ORDINATEUR_H
#define PROJET_PUISSANCE_N_ORDINATEUR_H

#include "header_principal.h"

/**
 * @file ordinateur.h
 * @brief fichier header contenant les prototypes des fonctions gérant les actions de l'IA de l'ordinateur
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Détermine le numéro de la colonne où l'ordinateur souhaite effectuer une action
 * @param Grille : la grille de jeu et ses dimensions
 * @return le numéro de la colonne où jouer
 */
int colonne_ordi(Grid Grille);

/**
 * Détermine le choix de l'ordinateur : ajouter ou retirer un jeton
 * @param Grille : la grille de jeu et ses dimensions
 * @return le choix de l'ordinateur
 */
int choix_action_ordi(Grid Grille);

#endif //PROJET_PUISSANCE_N_ORDINATEUR_H
