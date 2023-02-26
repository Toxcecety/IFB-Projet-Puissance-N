#ifndef PROJET_PUISSANCE_N_GESTION_GRILLE_H
#define PROJET_PUISSANCE_N_GESTION_GRILLE_H

#include "header_principal.h"

/**
 * @file gestion_grille.h
 * @brief fichier header contenant les prototypes des fonctions relatives à la gestion de la grille
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Détermine la taille de la grille de jeu et initialise la grille avec des '_'
 * @param Grille : la grille de jeu et ses dimensions
 */
void initialisation (Grid* Grille);

/**
 * Permet d'afficher la grille de jeu
 * @param Grille : la grille de jeu et ses dimensions
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 */
void show_grid (Grid Grille, Joueur joueur_rouge);

/**
 * Propose au lancement du programme 3 options : nouvelle partie, lancer sauvegarde ou quitter
 * @return le numéro de l'action désirée
 */
int menu();

/**
 * Demande à l'utilisateur le nombre de joueurs, en cas d'une nouvelle partie
 * @return le nombre de joueurs
 */
int choix_nbjoueur();

/**
 * Initialise les caractéristiques des joueurs au lancement d'une partie
 * @param joueur_jaune : les caractéristiques du joueur jaune, couleur, initiative et type de jeton
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 * @param nbjoueur : nombre de joueurs (hors ordinateur)
 */
void selection_joueur(Joueur* joueur_jaune, Joueur* joueur_rouge, int nbjoueur);

/**
 * Permet de régler la couleur d'affichage des textes
 * @param couleur_texte : code (prédéfini) de la couleur du texte
 * @param couleur_fond : code (prédéfini) de la couleur du fond
 */
void color(int couleur_texte, int couleur_fond);

/**
 * Permet de sauvergarder une partie
 * @param Grille : la grille et ses dimensions
 * @param j1 : les caractéristiques du premier joueur, couleur, initiative et type de jeton
 * @param j2 : les caractéristiques du deuxième joueur, couleur, initiative et type de jeton
 * @param nbjoueur : nombre de joueurs (hors ordinateur)
 */
void save(Grid Grille, Joueur j1, Joueur j2, int nbjoueur);

/**
 * Permet de charger une partie sauvegardée
 * @param Grille : la grille et ses dimensions
 * @param j1 : les caractéristiques du premier joueur, couleur, initiative et type de jeton
 * @param j2 : les caractéristiques du deuxième joueur, couleur, initiative et type de jeton
 * @param nbjoueur : nombre de joueurs (hors ordinateur)
 */
void load(Grid* Grille, Joueur* j1, Joueur* j2, int* nbjoueur);

/**
 * Libère l'espace mémoire occupé par la grille en fin de programme
 * @param Grille : la grille de jeu et ses dimensions
 */
void free_memory(Grid* Grille);

#endif //PROJET_PUISSANCE_N_GESTION_GRILLE_H
