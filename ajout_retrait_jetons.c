#include "header_principal.h"

/**
 * @file ajout_retrait_jetons.c
 * @brief fichier source contenant les fonctions relatives à la gestion des jetons
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Détermine le numéro de la colonne où le joueur souhaite effectuer une action
 * @param Grille : la grille de jeu et ses dimensions
 * @return le numéro de la colonne où jouer
 */
int colonne(Grid Grille) {
    int indice_colonne;

    // boucle sans message d'erreur, on s'assure que la colonne indiquée existe
    do {
        fflush(stdin);
        printf("\nDans quelle colonne souhaitez-vous agir : ");
        scanf("%d", &indice_colonne);
    } while (indice_colonne < 1 || indice_colonne > Grille.largeur);

    // on suppose que l'utilisateur compte les colonnes de 1 à N+2
    indice_colonne--;

    return indice_colonne;
}

/**
 * Permet d'ajouter, si possible, un jeton dans une colonne
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne où jouer
 * @param joueur : les caractéristiques du joueur actif, couleur, initiative et type de jeton
 * @return 1 si un jeton est correctement ajouté, 0 sinon
 */
int add_token(Grid* Grille, int colonne, Joueur joueur) {
    int i = Grille->largeur - 1; // i = N + 1

    // on parcourt toute une colonne, jusqu'à trouver une case vide ou jusqu'à avoir parcouru toute la colonne
    while (Grille->grille[colonne][i] != '_' && i >= 0 ) {
        i--;
    }

    // affiche si le jeton est ajouté ou pas
    if (Grille->grille[colonne][i] == '_') {
        printf("\nJeton correctement ajout%c\n", 130);
        Grille->grille[colonne][i] = joueur.jeton;
        return 1;
    } else {
        color(12, 0);
        printf("\n/!%c Vous ne pouvez pas ajouter de jeton dans cette colonne car elle est remplie /!%c \n", 92, 92);
        color(15, 0);
        return 0;
    }
}

/**
 * Permet de retirer, si possible, un jeton dans une colonne
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne où jouer
 * @param joueur : les caractéristiques du joueur actif, couleur, initiative et type de jeton
 * @return 1 si un jeton est correctement retiré, 0 sinon
 */
int remove_token(Grid* Grille, int colonne, Joueur joueur, int nbjoueur) {
    int indice_ligne = 0;

    // détermine l'indice de la ligne du dernier jeton posé dans une certaine colonne
    while (Grille->grille[colonne][indice_ligne] == '_' && indice_ligne < Grille->largeur-1) {
        indice_ligne++;
    }

    // affiche si le jeton est enlevé ou pas (pas si l'ordinateur joue)
    if (Grille->grille[colonne][indice_ligne-1] == '_' && Grille->grille[colonne][indice_ligne] != '_') {
        printf("\nJeton enlev%c\n", 130);
        Grille->grille[colonne][indice_ligne] = '_';
        return 1;
    } else {
        if (nbjoueur == 2) {
            color(12, 0);
            printf("\n/!%c Vous ne pouvez pas enlever de jeton dans cette colonne /!%c\n", 92, 92);
            color(15, 0);
        }
        return 0;
    }
}

/**
 * Permet de verifier si la grille est vide
 * @param Grille : la grille de jeu et ses dimensions
 * @return 1 si la grille est vide, 0 sinon
 */
int ligne_vide(Grid Grille) {
    int ligne_vide = 0;

    // passe à 1 la variable "ligne_vide" si au moins une case est occupée dans la grille
    for (int i = 0; i < (Grille.largeur-1); i++) {
        if (Grille.grille[i][Grille.largeur-1] != '_') {
            ligne_vide = 1;
        }
    }

    // retourne 1 si la ligne est vide, 0 sinon
    if (ligne_vide == 0) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Permet de verifier si la grille est pleine
 * @param Grille : la grille de jeu et ses dimensions
 * @return 1 si la grille est pleine, 0 sinon
 */
int grille_pleine(Grid Grille) {
    int grille_pleine = 1;

    // passe à 0 la variable "grille_pleine" si au moins une case est libre dans la grille
    for (int i = 0; i < Grille.largeur; i++) {
        if (Grille.grille[i][0] == '_') {
            grille_pleine = 0;
        }
    }

    // retourne 1 si la grille est pleine, 0 sinon
    if (grille_pleine == 0) {
        return 0;
    } else {
        printf("\nLa grille de jeu est pleine, match nul !\n");
        return 1;
    }
}

