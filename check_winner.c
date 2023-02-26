#include "header_principal.h"

/**
 * @file check_winner.c
 * @brief fichier source contenant les fonctions relatives au test d'un gagnant
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
int check_winner(Grid Grille, int colonne, Joueur joueur) {
    int N = Grille.largeur - 2;

    // détermine le nombre de jetons alignés verticalement consécutifs
    int verticale_joueur = check_verticale(Grille, colonne, joueur);

    // retourne 0 si le joueur jaune gagne, 1 si c'est le joueur rouge
    if (verticale_joueur == N && joueur.couleur == 'j') {
        return 0;
    } else if (verticale_joueur == N && joueur.couleur == 'r') {
        return 1;
    }

    // détermine le nombre de jetons alignés horizontalement consécutifs
    int horizontal_joueur = check_horizontal(Grille, colonne, joueur);

    // retourne 0 si le joueur jaune gagne, 1 si c'est le joueur rouge
    if (horizontal_joueur == N && joueur.couleur == 'j') {
        return 0;
    } else if (horizontal_joueur == N && joueur.couleur == 'r') {
        return 1;
    }

    // détermine le nombre de jetons alignés en diagonale consécutifs
    int diagonale_joueur = check_diagonale(Grille, colonne, joueur);

    // retourne 0 si le joueur jaune gagne, 1 si c'est le joueur rouge
    if (diagonale_joueur == N && joueur.couleur == 'j') {
        return 0;
    } else if (diagonale_joueur == N && joueur.couleur == 'r') {
        return 1;
    }

    // retourne -1 si aucun joueur gagne
    return -1;

}

/**
 * Check si N jetons sont alignés verticalement dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_verticale(Grid Grille, int colonne, Joueur joueur) {
    int N = Grille.largeur-2;
    int verticale_joueur = 0;

    int j = 0;

    // Parcourt la grille de haut en bas
    // Détermine le nombre de jetons alignés verticalement consécutifs de même type
    while (j <= Grille.largeur - 1 && verticale_joueur != N) {
        if (Grille.grille[colonne][j] == joueur.jeton) {
            verticale_joueur++;
        } else {
            verticale_joueur = 0;
        }
        j++;
    }

    // retourne le nombre de jeton alignés verticalement consécutifs de même type
    return verticale_joueur;
}

/**
 * Check si N jetons sont alignés horizontalement dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_horizontal(Grid Grille, int colonne, Joueur joueur) {
    int N = Grille.largeur-2;
    int horizontal_joueur = 0;
    int indice_ligne = 0;

    // Détermine l'indice de la ligne du jeton ajouté
    while (Grille.grille[colonne][indice_ligne] != joueur.jeton && indice_ligne <= Grille.largeur - 1){
        indice_ligne++;
    }

    int i = 0;

    // Parcourt la grille de gauche à droite
    // Détermine le nombre de jetons alignés horizontalement consécutifs de même type
    while (i <= Grille.largeur - 1 && horizontal_joueur != N) {
        if (Grille.grille[i][indice_ligne] == joueur.jeton) {
            horizontal_joueur++;
        } else {
            horizontal_joueur = 0;
        }
        i++;
    }

    // retourne le nombre de jeton alignés horizontalement consécutifs de même type
    return horizontal_joueur;
}

/**
 * Check si N jetons sont alignés en diagonale dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_diagonale(Grid Grille, int colonne, Joueur joueur) {
    // Détermine le nombre de jetons alignés en diagonale du haut gauche vers bas droit consécutifs de même type
    int diagonale_joueur = check_diagonale_croissante(Grille, colonne, joueur);

    // si le premier check retourne 0, on check la diagonale du bas gauche vers haut droit
    if (diagonale_joueur == 0) {
        diagonale_joueur = check_diagonale_decroissante(Grille, colonne, joueur);
    }

    // retourne le nombre de jeton alignés en diagonale consécutifs de même type
    return diagonale_joueur;
}

/**
 * Check si N jetons sont alignés en diagonale croissante (haut gauche vers bas droit) dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_diagonale_croissante(Grid Grille, int colonne, Joueur joueur) {
    int N = Grille.largeur - 2;
    int diagonale_joueur = 0;

    // détermine les cordonnées du point de départ à l'origine de la diagonale
    Origine point_depart = origine_diagonale_croissante(Grille, colonne, joueur);

    // fixe les coordonnées de l'origine
    int i = point_depart.abscisse;
    int j = point_depart.ordonnee;

    // parcourt la diagonale du haut vers le bas et détermine le nombre de jetons consécutifs de même type
    while (i <= Grille.largeur-1 && j <= Grille.largeur-1 && diagonale_joueur != N) {
        if (Grille.grille[i][j] == joueur.jeton) {
            diagonale_joueur++;
        } else {
            diagonale_joueur = 0;
        }
        j++;
        i++;
    }

    // retourne N si N jetons sont alignés, 0 sinon
    if (diagonale_joueur == N) {
        return diagonale_joueur;
    } else {
        return 0;
    }

}

/**
 * Détermine le point à l'origine de la diagonale croissante dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return les coordonnées du point d'origine
 */
Origine origine_diagonale_croissante (Grid Grille, int colonne, Joueur joueur) {
    Origine point_depart;
    int b;
    int indice_ligne = 0;

    // détermine l'indice de la ligne du jeton ajouté
    while (Grille.grille[colonne][indice_ligne] != joueur.jeton && indice_ligne <= Grille.largeur - 1) {
        indice_ligne++;
    }

    // détermine la valeur de l'ordonnée à l'origine (fonction affine)
    b = indice_ligne - colonne;

    // détermine les coordonnées du point de départ de la diagonale
    if (b <= 0) {
        point_depart.abscisse = -b;
        point_depart.ordonnee = 0;
        return point_depart;
    } else {
        point_depart.abscisse = 0;
        point_depart.ordonnee = b;
        return point_depart;
    }

}

/**
 * Check si N jetons sont alignés en diagonale décroissante (bas gauche vers haut droit) dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return le nombre de jeton alignés identiques consécutifs
 */
int check_diagonale_decroissante(Grid Grille, int colonne, Joueur joueur) {
    int N = Grille.largeur - 2;
    int diagonale_joueur = 0;

    // détermine les cordonnées du point de départ à l'origine de la diagonale
    Origine point_depart = origine_diagonale_decroissante(Grille, colonne, joueur);

    // fixe les coordonnées de l'origine
    int i = point_depart.abscisse;
    int j = point_depart.ordonnee;

    // parcourt la diagonale du bas vers le haut et détermine le nombre de jetons consécutifs de même type
    while (i <= Grille.largeur - 1 && j <= Grille.largeur -1 && diagonale_joueur != N) {
        if (Grille.grille[i][j] == joueur.jeton) {
            diagonale_joueur++;
        } else {
            diagonale_joueur = 0;
        }
        j--;
        i++;
    }

    // retourne N si N jetons sont alignés, 0 sinon
    if (diagonale_joueur == N) {
        return diagonale_joueur;
    } else {
        return 0;
    }
}

/**
 * Détermine le point à l'origine de la diagonale décroissante dans la grille
 * @param Grille : la grille de jeu et ses dimensions
 * @param colonne : numéro de colonne du dernier jeton ajouté
 * @param joueur : caractéristiques du joueur venant de poser un jeton, couleur, initiative et type de jeton
 * @return les coordonnées du point d'origine
 */
Origine origine_diagonale_decroissante (Grid Grille, int colonne, Joueur joueur) {
    Origine point_depart;
    int N = Grille.largeur - 2;
    int b;
    int indice_ligne = 0;

    // détermine l'indice de la ligne du jeton ajouté
    while (Grille.grille[colonne][indice_ligne] != joueur.jeton && indice_ligne <= Grille.largeur - 1) {
        indice_ligne++;
    }

    // détermine la valeur de l'ordonnée à l'origine (fonction affine)
    b = indice_ligne + colonne;

    // détermine les coordonnées du point de départ de la diagonale
    if (b <= (N+1)) {
        point_depart.abscisse = 0;
        point_depart.ordonnee = b;
        return point_depart;
    } else {
        point_depart.abscisse = b - (N+1);
        point_depart.ordonnee = N + 1;
        return point_depart;
    }

}
