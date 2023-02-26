#ifndef PROJET_PUISSANCE_N_AJOUT_RETRAIT_JETONS_H
#define PROJET_PUISSANCE_N_AJOUT_RETRAIT_JETONS_H

#include "header_principal.h"

/**
 * @file ajout_retrait_jetons.h
 * @brief fichier header contenant les prototypes des fonctions relatives à la gestion des jetons
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Détermine le numéro de la colonne où le joueur souhaite effectuer une action
 * @param Grille : la grille de jeu et ses dimensions
 * @return le numéro de la colonne où jouer
 */
int colonne(Grid Grille);

/**
 * Permet d'ajouter, si possible, un jeton dans une colonne
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne où jouer
 * @param joueur : les caractéristiques du joueur actif, couleur, initiative et type de jeton
 * @return 1 si un jeton est correctement ajouté, 0 sinon
 */
int add_token(Grid* Grille, int colonne, Joueur joueur);

/**
 * Permet de retirer, si possible, un jeton dans une colonne
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne où jouer
 * @param joueur : les caractéristiques du joueur actif, couleur, initiative et type de jeton
 * @return 1 si un jeton est correctement retiré, 0 sinon
 */
int remove_token(Grid* Grille, int colonne, Joueur joueur, int nbjoueur);

/**
 * Permet de verifier si la grille est vide
 * @param Grille : la grille de jeu et ses dimensions
 * @return 1 si la grille est vide, 0 sinon
 */
int ligne_vide(Grid Grille);

/**
 * Permet de verifier si la grille est pleine
 * @param Grille : la grille de jeu et ses dimensions
 * @return 1 si la grille est pleine, 0 sinon
 */
int grille_pleine(Grid Grille);

#endif //PROJET_PUISSANCE_N_AJOUT_RETRAIT_JETONS_H
