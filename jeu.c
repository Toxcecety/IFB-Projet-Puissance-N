#include "header_principal.h"

/**
 * @file jeu.c
 * @brief fichier source contenant les fonctions relatives à la gestion du jeu solo/multi
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Permet l'affichage d'un trophée en cas de victoire d'un joueur réel
 */
void affichage_trophee() {
    int trophee;

    srand(time(0));

    trophee = rand() % 2;

    if (trophee == 0) {
        printf(" '._==_==_=_.'\n"
               " .-\\:      /-.\n"
               "| (|:.     |) |\n"
               " '-|:.     |-'\n"
               "   \\::.    /\n"
               "    '::. .'\n"
               "      ) (\n"
               "    _.' '._\n");
    } else {
        printf(" .-=========-.\n"
               " \\'-=======-'/\n"
               " _|   .=.   |_\n"
               "((|  {{1}}  |))\n"
               " \\|   /|\\   |/\n"
               "  \\__ '`' __/\n"
               "    _`) (`_\n"
               "  _/_______\\_\n"
               " /___________\\\n");
    }

}

/**
 * Assure le déroulement du jeu à 2 joueurs
 * @param Grille : la grille de jeu et ses dimensions
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 * @param joueur_jaune : les caractéristiques du joueur jaune, couleur, initiative et type de jeton
 */
void jeu_multi(Grid Grille, Joueur joueur_rouge, Joueur joueur_jaune) {
    int winner = -1;
    int add, remove;
    int indice_colonne; // colonne où souhaite agir l'utilisateur
    int colonne_remove = -1; // si un utilisateur retire un jeton, la variable contient l'indice de la colonne où a été retiré le jeton
    int choix_action;

    while (winner == -1 && choix_action != 3 && grille_pleine(Grille) != 1) {
        // affichage de la grille
        show_grid(Grille, joueur_rouge);

        // affiche à qui est le tour
        if (joueur_jaune.initiative == 0) {
            color(14, 0);
            printf("\nTOUR JOUEUR JAUNE :");
            color(15, 0);
        } else {
            color(12, 0);
            printf("\nTOUR JOUEUR ROUGE :");
            color(15, 0);
        }

        // si la dernière ligne est vide, le joueur n'a plus que deux choix d'actions possibles, sinon il a accès aux trois choix
        if (ligne_vide(Grille) == 1) {
            // boucle sans message d'erreur, pour obtenir un choix d'action valable
            do {
                printf("\n1. Ajouter un jeton\n2. Sauvegarder et quitter\n");
                fflush(stdin);
                scanf("%d", &choix_action);
            } while (choix_action != 1 && choix_action != 2);

            // on modifie le choix d'action pour que cela corresponde bien aux valeurs/actions des ifs qui vont suivre
            if (choix_action == 2) {
                choix_action = 3;
            }

        } else {

            // boucle sans message d'erreur, pour obtenir un choix d'action valable
            do {
                printf("\n1. Ajouter un jeton\n2. Retirer un jeton\n3. Sauvegarder et quitter\n");
                fflush(stdin);
                scanf("%d", &choix_action);
            } while (choix_action != 1 && choix_action != 2 && choix_action != 3);
        }

        if (choix_action == 1) {
            do {
                indice_colonne = colonne(Grille); // demande colonne où on souhaite agir
                // boucle avec message d'erreur, on verifie que la colonne choisie n'a pas eu de jeton de retiré le tour précédent
                while (indice_colonne == colonne_remove) {
                    printf("\nLe joueur pr%cc%cdent a retir%c un jeton de cette colonne vous ne pouvez pas y ajouter votre jeton\n", 130, 130, 130);
                    indice_colonne = colonne(Grille); // demande colonne où on souhaite agir
                }
                if (joueur_jaune.initiative == 0) { // en fonction de qui à l'initiative un jeton jaune ou rouge est ajoutée
                    add = add_token(&Grille, indice_colonne, joueur_jaune);
                } else {
                    add = add_token(&Grille, indice_colonne, joueur_rouge);
                }
                colonne_remove = -1; // le changement de colonne_remove permet d'indiquer qu'aucun jeton n'a été retiré lors de ce tour
            } while (add == 0);
        } else if (choix_action == 2) {
            do {
                indice_colonne = colonne(Grille); // demande colonne où on souhaite agir
                if (joueur_jaune.initiative == 0) { // en fonction de qui à l'initiative un jeton jaune ou rouge est ajoutée
                    remove = remove_token(&Grille, indice_colonne, joueur_jaune, 2);
                } else {
                    remove = remove_token(&Grille, indice_colonne, joueur_rouge, 2);
                }
                colonne_remove = indice_colonne; // colonne_remove prend la valeur de la colonne où à été retiré un jeton
            } while (remove == 0);
        } else {
            // sauvegarde la partie
            printf("\n\nPartie sauvegard%ce", 130);
            save(Grille, joueur_rouge, joueur_jaune, 2);
        }

        // check si N jetons sont alignés et alterne les initiatives entre les joueurs
        if (joueur_jaune.initiative == 0) {
            winner = check_winner(Grille, indice_colonne, joueur_jaune);
            joueur_jaune.initiative = 1;
            joueur_rouge.initiative = 0;
        } else {
            winner = check_winner(Grille, indice_colonne, joueur_rouge);
            joueur_jaune.initiative = 0;
            joueur_rouge.initiative = 1;
        }

        fflush(stdin);
    }

    // affichage de la grille
    show_grid(Grille, joueur_rouge);

    // indique, en cas de victoire, quel joueur remporte la partie
    if (winner == 0) {
        color(0, 14);
        printf("\nBravo au joueur jaune\n");
        color(15, 0);
        affichage_trophee();
    } else if (winner == 1) {
        color(0, 12);
        printf("\nBravo au joueur rouge\n");
        color(15, 0);
       affichage_trophee();
    }
}

/**
 * Assure le déroulement du jeu joueur vs ordinateur
 * @param Grille : la Grille de jeu et ses dimensions
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 * @param joueur_jaune : les caractéristiques du joueur "ordinateur", couleur, initiative et type de jeton
 */
void jeu_solo(Grid Grille, Joueur joueur_rouge, Joueur joueur_jaune) {
    int winner = -1;
    int add, remove;
    int indice_colonne;
    int colonne_remove = -1;
    int choix_action;

    // lorsque l'utilisateur joue contre l'ordinateur il est obligatoirement le joueur rouge et l'ordinateur est le joueur jaune
    while (winner == -1 && choix_action != 3 && grille_pleine(Grille) != 1) {
        // affichage de la grille
        show_grid(Grille, joueur_rouge);
        if (joueur_jaune.initiative == 0) {
            color(14, 0);
            printf("\nTOUR ORDINATEUR :");
            color(15, 0);

            choix_action = choix_action_ordi(Grille);

            // effectue et affiche l'action choisie par l'ordinateur
            if (choix_action == 1) {
                do {
                    // boucle sans message d'erreur pour s'assurer que l'ordinateur n'ajoute pas
                    // un jeton dans une colonne où un jeton vient d'être retiré
                    do {
                        indice_colonne = colonne_ordi(Grille);
                    } while (indice_colonne == colonne_remove);

                    add = add_token(&Grille, indice_colonne, joueur_jaune); // ajout du jeton
                    colonne_remove = -1;
                } while (add == 0);

                color(14, 0);
                printf("\nL'ordinateur a ajout%c un jeton en colonne %d\n", 130, indice_colonne + 1);
                color(15, 0);

            } else if (choix_action == 2) {
                // boucle sans message d'erreur pour s'assurer que l'ordinateur retire correctement un jeton dans une colonne valable
                do {
                    indice_colonne = colonne_ordi(Grille);
                    remove = remove_token(&Grille, indice_colonne, joueur_rouge, 1);
                    colonne_remove = indice_colonne;
                } while (remove == 0);

                color(14, 0);
                printf("\nL'ordinateur a retir%c un jeton en colonne %d", 130, indice_colonne + 1);
                color(15, 0);
            }

            // alterne les initiatives de l'ordinateur et du joueur
            winner = check_winner(Grille, indice_colonne, joueur_jaune);
            joueur_rouge.initiative = 0;
            joueur_jaune.initiative = 1;

        } else {
            // demande au joueur de choisir une action
            color(12, 0);
            printf("\nTOUR JOUEUR :");
            color(15, 0);

            // affichage des choix d'action
            if (ligne_vide(Grille) == 1) {
                // boucle sans message d'erreur pour obtenir un choix d'action valable
                do {
                    printf("\n1. Ajouter un jeton\n2. Sauvegarder et quitter\n");
                    fflush(stdin);
                    scanf("%d", &choix_action);
                } while (choix_action != 1 && choix_action != 2);

                // on modifie le choix d'action pour que cela corresponde bien aux valeurs/actions des tests qui vont suivre
                if (choix_action == 2) {
                    choix_action = 3;
                }
            } else {
                // boucle sans message d'erreur pour obtenir un choix d'action valable
                do {
                    printf("\n1. Ajouter un jeton\n2. Retirer un jeton\n3. Sauvegarder et quitter\n");
                    fflush(stdin);
                    scanf("%d", &choix_action);
                } while (choix_action != 1 && choix_action != 2 && choix_action != 3);
            }

            // effectue l'action choisie par l'utilisateur
            if (choix_action == 1) {
                do {
                    indice_colonne = colonne(Grille);
                    while (indice_colonne == colonne_remove) {
                        printf("\nL'ordinateur a retir%c un jeton de cette colonne vous ne pouvez pas y ajouter votre jeton\n", 130);
                        indice_colonne = colonne(Grille);
                    }

                    add = add_token(&Grille, indice_colonne, joueur_rouge);
                    colonne_remove = -1;
                } while (add == 0);
            } else if (choix_action == 2) {
                do {
                    indice_colonne = colonne(Grille);
                    remove = remove_token(&Grille, indice_colonne, joueur_rouge, 2);
                    colonne_remove = indice_colonne;
                } while (remove == 0);
            } else {
                // sauvegarde la partie
                printf("\n\nPartie sauvegard%ce", 130);
                save(Grille, joueur_rouge, joueur_jaune, 1);
            }

            winner = check_winner(Grille, indice_colonne, joueur_rouge);

            // alterne les initiatives des joueurs
            joueur_rouge.initiative = 1;
            joueur_jaune.initiative = 0;

        }
    }

    // affichage de la grille
    show_grid(Grille, joueur_rouge);

    // indique, en cas de victoire, quel joueur remporte la partie
    if (winner == 0) {
        color(15, 5);
        printf("\nPerdu, l'ordinateur a gagn%c...\n", 130);
        color(15, 0);
    } else if (winner == 1) {
        color(0, 12);
        printf("\nBRAVO A VOUS\n");
        color(15, 0);
        affichage_trophee();
    }

}







