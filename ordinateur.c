#include "header_principal.h"

/**
 * @file ordinateur.c
 * @brief fichier source contenant les fonctions gérant les actions de l'IA de l'ordinateur
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Détermine le numéro de la colonne où l'ordinateur souhaite effectuer une action
 * @param Grille : la grille de jeu et ses dimensions
 * @return le numéro de la colonne où jouer
 */
int colonne_ordi(Grid Grille) {
    int indice_colonne;

    // l'ordinateur retire ou ajoute un jeton dans une colonne aléatoire définie ici
    srand(time(NULL));
    indice_colonne = rand() % (Grille.largeur-1) + 1;

    // retourne l'indice de la colonne dans laquelle l'ordinateur souhaite jouer
    return indice_colonne;
}

/**
 * Détermine le choix de l'ordinateur : ajouter ou retirer un jeton
 * @param Grille : la grille de jeu et ses dimensions
 * @return le choix de l'ordinateur
 */
int choix_action_ordi(Grid Grille) {
    int choix, temp;

    // si la dernière ligne est vide, l'ordinateur effectue automatiquement un ajout de jeton
    // sinon il effectue une action aléatoire
    if (ligne_vide(Grille) == 1) {
        temp = 1;
    } else {
        srand(time(NULL));
        temp = rand() % 5;
    }

    // il est plus probable que l'ordinateur ajoute un jeton, c'est pour rendre le jeu plus équilibré
    if (temp == 4) {
        choix = 2;
    } else {
        choix = 1;
    }

    // retourne l'action que va effectuer l'ordinateur
    return choix;
}
