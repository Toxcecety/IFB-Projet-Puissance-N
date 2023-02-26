#ifndef PROJET_PUISSANCE_N_JEU_H
#define PROJET_PUISSANCE_N_JEU_H

#include "header_principal.h"

/**
 * @file jeu.h
 * @brief fichier header contenant les prototypes des fonctions relatives à la gestion du jeu solo/multi
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Permet l'affichage d'un trophée en cas de victoire d'un joueur réel
 */
void affichage_trophee();

/**
 * Assure le déroulement du jeu à 2 joueurs
 * @param Grille : la grille de jeu et ses dimensions
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 * @param joueur_jaune : les caractéristiques du joueur jaune, couleur, initiative et type de jeton
 */
void jeu_multi(Grid Grille, Joueur joueur_rouge, Joueur joueur_jaune);

/**
 * Assure le déroulement du jeu joueur vs ordinateur
 * @param Grille : la Grille de jeu et ses dimensions
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 * @param joueur_jaune : les caractéristiques du joueur "ordinateur", couleur, initiative et type de jeton
 */
void jeu_solo(Grid Grille, Joueur joueur_rouge, Joueur joueur_jaune);

#endif //PROJET_PUISSANCE_N_JEU_H
