#ifndef PROJET_PUISSANCE_N_CHECK_WINNER_H
#define PROJET_PUISSANCE_N_CHECK_WINNER_H

#include "header_principal.h"

/**
 * @file check_winner.h
 * @brief fichier header contenant les prototypes des fonctions relatives au test d'un gagnant
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Check si N jetons sont alignés dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return 1 si le joueur rouge gagne, 0 si c'est le joueur jaune, -1 sinon
 */
int check_winner(Grid Grille, int colonne, Joueur joueur);

/**
 * Check si N jetons sont alignés verticalement dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_verticale(Grid Grille, int colonne, Joueur joueur);

/**
 * Check si N jetons sont alignés horizontalement dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_horizontal(Grid Grille, int colonne, Joueur joueur);

/**
 * Check si N jetons sont alignés en diagonale dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_diagonale(Grid Grille, int colonne, Joueur joueur);

/**
 * Check si N jetons sont alignés en diagonale croissante (haut gauche vers bas droit) dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_diagonale_croissante(Grid Grille, int colonne, Joueur joueur);

/**
 * Détermine le point à l'origine de la diagonale croissante dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return les coordonnées du point d'origine
 */
Origine origine_diagonale_croissante (Grid Grille, int colonne, Joueur joueur);

/**
 * Check si N jetons sont alignés en diagonale décroissante (bas gauche vers haut droit) dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_diagonale_decroissante(Grid Grille, int colonne, Joueur joueur);

/**
 * Détermine le point à l'origine de la diagonale décroissante dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return les coordonnées du point d'origine
 */
Origine origine_diagonale_decroissante (Grid Grille, int colonne, Joueur joueur);

#endif //PROJET_PUISSANCE_N_CHECK_WINNER_H
