#include "header_principal.h"

/**
 * @file main.c
 * @brief fichier source gérant l'intégralité du jeu Puissance N
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

int main() {
    Grid Grille;
    int rep_menu = menu(); // affiche le menu et retourne le choix de l'utilisateur
    int nb_joueurs;
    Joueur joueur_jaune, joueur_rouge; // joueur jaune est le premier joueur et joueur rouge est le deuxième

    switch (rep_menu) {
        case 1 :
            // démarrage d'une nouvelle partie avec initialisation du tableau, des scores, etc.
            printf("\n\t\t~~ Lancement nouvelle partie ~~\n\n");
            initialisation(&Grille);

            nb_joueurs = choix_nbjoueur(); // demande le nombre de joueurs (joueur contre ordinateur ou joueur contre joueur)
            selection_joueur(&joueur_jaune, &joueur_rouge, nb_joueurs); // initialise les infos des joueurs

            if (nb_joueurs == 1) {
                jeu_solo(Grille, joueur_rouge, joueur_jaune); // lance une partie joueur vs ordinateur
            } else if (nb_joueurs == 2) {
                jeu_multi(Grille, joueur_rouge, joueur_jaune); // lance une partie joueur vs joueur
            }

            break;

        case 2 :
            // on charge une partie existante, on récupère les informations sur la partie sauvegardée
            printf("\n\t\t~~ Chargement partie existante ~~\n\n");
            load(&Grille, &joueur_rouge, &joueur_jaune, &nb_joueurs);

            if (nb_joueurs == 1) {
                jeu_solo(Grille, joueur_rouge, joueur_jaune); // relance partie joueur vs ordinateur
            } else if (nb_joueurs == 2) {
                jeu_multi(Grille, joueur_rouge, joueur_jaune); // relance partie joueur vs joueur
            }

            break;

        case 3:
            // on quitte le jeu
            printf("\n\t\t~~ Vous quittez ~~\n\n");

            break;

        default:
            // en cas d'erreur, affichage d'un msg d'erreur + localisation du problème
            printf("ERREUR ! Veuillez relancer le programme [main]\n");
    }

    // on libère la mémoire occupée par la grille (cette mémoire est seulement attribuée dans les cas 1 et 2)
    if (rep_menu != 3) {
        free_memory(&Grille);
    }

    return EXIT_SUCCESS;
}
