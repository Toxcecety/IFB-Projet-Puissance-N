#include "header_principal.h"

/**
 * @file gestion_grille.c
 * @brief fichier source contenant les fonctions relatives à la gestion de la grille
 * @author Celiane A. & Loic B. & Mathis B.
 * @version v1.0
 * @date Juin 2021
 */

/**
 * Propose au lancement du programme 3 options : nouvelle partie, lancer sauvegarde ou quitter
 * @return le numéro de l'action désirée
 */
int menu() {
    int rep_menu;

    // affichage de la page d'accueil du jeu
    color(15, 0);
    printf("\nBienvenue dans le jeu\n");


    color(14, 0);
    printf("----------------------------\n\n");
    color(0, 15);
    printf("        Puissance N         \n\n");
    color(14, 0);
    printf("----------------------------\n");
    color(15, 0);

    printf("R%calis%c par C%cliane Allaire, Lo%cc Bouriel et Mathis Burger\n\n", 130, 130, 130, 139);


    // affichage du menu, avec l'utilisation de couleurs
    color(14, 0);
    printf("\n\t\t  ===== MENU =====\n\n");
    color(11, 0);
    printf("1. D%cmarrer une nouvelle partie\n2. Charger une partie existante\n3. Quitter\n\n", 130);
    color(15, 0);
    printf("Veuillez entrer le num%cro de l'action que vous souhaitez effectuer : \n", 130);
    fflush(stdin);
    scanf("%d", &rep_menu);
    fflush(stdin);

    // boucle avec message d'erreur, pour avoir un choix d'action valable
    while (rep_menu <= 0 || rep_menu > 3) {
        color(12, 0);
        printf("ERREUR !\n");
        color(15, 0);
        printf("Veuillez saisir le num%cro de l'action que vous souhaitez effectuer :\n", 130);
        scanf("%d", &rep_menu);
        fflush(stdin);
    }

    // retourne choix d'action utilisateur
    return rep_menu;
}

/**
 * Détermine la taille de la grille de jeu et initialise la grille avec des '_'
 * @param Grille :la grille de jeu et ses dimensions
 */
void initialisation (Grid* Grille) {
    int N;

    // saisie du nombre de jetons N à aligner
    printf("Combien de jetons N voulez-vous aligner (2 <= N <= 10) ?\n");
    fflush(stdin);
    scanf("%d", &N);
    fflush(stdin);

    // boucle avec message d'erreur, pour avoir un nombre de jetons à aligner valable
    while (N < 2 || N > 10) {
        printf("Saisie incorrecte : 2 <= N <= 10 \n");
        printf("Combien de jetons N voulez-vous aligner ?");
        scanf("%d", &N);
        fflush(stdin);
    }

    // allocation dynamique de mémoire pour la grille
    Grille->grille = (char**) malloc(sizeof(char*) * (N+2));

    // initialisation de la grille avec des '_'
    for (int i = 0; i < N + 2; i++) {
        Grille->grille[i] = (char*) malloc(sizeof(char) * (N+2));
        for (int j = 0; j < N + 2; j++) {
            Grille->grille[i][j] = '_';
        }
    }

    // définition des dimensions de la grille
    Grille->largeur = N + 2;
    Grille->longueur = N + 2;

}

/**
 * Permet d'afficher la grille de jeu
 * @param Grille : la grille de jeu et ses dimensions
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 */
void show_grid (Grid Grille, Joueur joueur_rouge) {

    color(11, 0);
    printf("\nGRILLE :\n");
    color(15, 0);

    // affichage du "Haut" de la grille, on utilise des caractères spéciaux pour former le cadre de la grille
    color(1, 0);
    printf("%c", 201);
    for (int i = 0; i <= Grille.largeur - 2; i++) {
        printf("%c%c%c%c", 205, 205, 205, 203);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 187);
    color(15, 0);

    // "Milieu" de la grille, on utilise des caractères spéciaux pour former le cadre de la grille
    for (int i = 0; i < Grille.largeur; i++) {
        color(1, 0);
        printf("%c", 186);
        color(15, 0);
        for (int j = 0; j < Grille.largeur; j++) {
            // on attribue la couleur correcte du jeton en fonction des choix effectués par les joueurs
            if (Grille.grille[j][i] == 'X' && joueur_rouge.jeton == 'X') {
                color(12, 0);
                printf(" %c ", Grille.grille[j][i]);
            } else if (Grille.grille[j][i] == 'X' && joueur_rouge.jeton == 'O') {
                color(14, 0);
                printf(" %c ", Grille.grille[j][i]);
            } else if (Grille.grille[j][i] == 'O' && joueur_rouge.jeton == 'X') {
                color(14, 0);
                printf(" %c ", Grille.grille[j][i]);
            } else if (Grille.grille[j][i] == 'O' && joueur_rouge.jeton == 'O' ) {
                color(12, 0);
                printf(" %c ", Grille.grille[j][i]);
            } else {
                color(1, 0);
                printf(" %c ",Grille.grille[j][i]);
            }
            color(1, 0);
            printf("%c", 186);
            color(15,0);
        }

        color(1, 0);
        if (i < Grille.largeur - 1) {
            printf("\n%c", 204);
            for (int k = 0; k <= Grille.largeur - 2; k++) {
                printf("%c%c%c%c", 205, 205, 205, 206);
            }
            printf("%c%c%c%c", 205, 205, 205, 185);
        }
        color(15, 0);
        printf("\n");
    }

    // "Bas" de la grille, on utilise des caractères spéciaux pour former le cadre de la grille
    color(1, 0);
    printf("%c", 200);
    for (int i = 0; i <= Grille.largeur - 2; i++) {
        printf("%c%c%c%c", 205, 205, 205, 202);
    }
    printf("%c%c%c%c\n", 205, 205, 205, 188);
    color(15, 0);

    // numérote les colonnes de 1 à N+2
    for (int i = 0; i <= Grille.largeur - 1; i++) {
        if (i < 10){
            printf("  %d ", i+1);
        } else {
            printf(" %d ", i+1);
        }
    }
}

/**
 * Demande à l'utilisateur le nombre de joueurs, en cas d'une nouvelle partie
 * @return le nombre de joueurs
 */
int choix_nbjoueur() {
    int rep;

    color(14, 0);
    printf("\nCHOIX NOMBRE DE JOUEURS");
    color(11, 0);

    // boucle sans message d'erreur, demande à l'utilisateur le nombre de joueurs
    do {
        printf("\n1. Jouer contre l'ordinateur\n2. Jouer %c deux\n", 133);
        scanf("%d", &rep);
        fflush(stdin);
    } while (rep != 1 && rep != 2);
    color(15, 0);

    // retourne le nombre de joueurs qui jouent
    return rep;
}

/**
 * Initialise les caractéristiques des joueurs au lancement d'une partie
 * @param joueur_jaune : les caractéristiques du joueur jaune, couleur, initiative et type de jeton
 * @param joueur_rouge : les caractéristiques du joueur rouge, couleur, initiative et type de jeton
 * @param nbjoueur : nombre de joueurs (hors ordinateur)
 */
void selection_joueur(Joueur* joueur_jaune, Joueur* joueur_rouge, int nbjoueur) {

    // permet le choix du type de jetons aux joueurs
    joueur_jaune->couleur = 'j';
    joueur_rouge->couleur = 'r';

    srand(time(NULL));
    color(6, 0);
    printf("\nLe joueur qui aura l'initiative de la partie est d%ctermin%c par tirage au sort\n\n", 130, 130);
    printf("\t\t*** Tirage au sort en cours... ***\n\n");
    color(15, 0);

    // tirage au sort, si 0 alors initiative jaune, sinon initiative rouge
    joueur_jaune->initiative = rand() % 2;

    // on informe quel joueur commence et on effectue l'attribution des jetons
    // toutes ces informations sont enregristrées dans les structures joueur_jaune et joueur_rouge
    switch (nbjoueur) {
        case 1 :
            // s'il n'y a qu'un seul joueur, l'ordi est automatiquement le joueur jaune
            if (joueur_jaune->initiative == 0) {
                printf("C'est l'ordinateur qui a l'initiative. Bonne chance !\n\n");
                joueur_rouge->initiative = 1;
            } else {
                printf("Vous avez l'initiative. Bonne chance !\n\n");
                joueur_rouge->initiative = 0;
            }

            // boucle sans message d'erreur, le joueur choisit son jeton
            do {
                printf("\nJeton joueur (X ou O) : ");
                fflush(stdin);
                joueur_rouge->jeton = getch();
            } while (joueur_rouge->jeton != 'X' && joueur_rouge->jeton != 'O');

            // indique les jetons attribués aux joueurs
            if (joueur_rouge->jeton == 'X') {
                printf("Jeton ordinateur : O\n");
                joueur_jaune->jeton = 'O';
            } else {
                printf("Jeton ordinateur : X\n");
                joueur_jaune->jeton = 'X';
            }

            break;

        case 2 :
            // en fonction de l'initiative le joueur rouge ou jaune aura le droit de choisir son jeton
            if (joueur_jaune->initiative == 0) {
                printf("C'est le joueur jaune qui a l'initiative. Bonne chance !\n\n");
                joueur_rouge->initiative = 1;

                // boucle sans message d'erreur, le joueur jaune choisit son jeton
                do {
                    printf("\nJeton joueur JAUNE (X ou O) : ");
                    fflush(stdin);
                    joueur_jaune->jeton = getch();
                } while (joueur_jaune->jeton != 'X' && joueur_jaune->jeton != 'O');

                // attribution du deuxième jeton en fonction de la réponse du joueur jaune et affichage du jeton attribué au joueur rouge
                if (joueur_jaune->jeton == 'X') {
                    printf("Jeton joueur ROUGE : O\n");
                    joueur_rouge->jeton = 'O';
                } else {
                    printf("Jeton joueur ROUGE : X\n");
                    joueur_rouge->jeton = 'X';
                }
            } else {
                printf("C'est le joueur rouge qui a l'initiative. Bonne chance !\n\n");
                joueur_rouge->initiative = 0;

                // boucle sans message d'erreur, le joueur rouge choisit son jeton
                do {
                    printf("\nJeton joueur ROUGE (X ou O) : ");
                    fflush(stdin);
                    joueur_rouge->jeton = getch();
                } while (joueur_rouge->jeton != 'X' && joueur_rouge->jeton != 'O');

                // attribution du deuxième jeton en fonction de la réponse du joueur rouge et affichage du jeton attribué au joueur jaune
                if (joueur_rouge->jeton == 'X') {
                    printf("Jeton joueur JAUNE : O\n");
                    joueur_jaune->jeton = 'O';
                } else {
                    printf("Jeton joueur JAUNE : X\n");
                    joueur_jaune->jeton = 'X';
                }
            }

            break;

        default : printf("\nERREUR ! [selection_joueur]\n");
    }
}

/**
 * Permet de charger une partie sauvegardée
 * @param Grille : la grille et ses dimensions
 * @param j1 : les caractéristiques du premier joueur, couleur, initiative et type de jeton
 * @param j2 : les caractéristiques du deuxième joueur, couleur, initiative et type de jeton
 * @param nbjoueur : nombre de joueurs (hors ordinateur)
 */
void load(Grid* Grille, Joueur* j1, Joueur* j2, int* nbjoueur) {
    int N;

    j1->couleur = 'r';
    j2->couleur = 'j';

    // on ouvre le fichier en mode lecture
    FILE *f = fopen("save.txt", "r");

    if (f != NULL) { // on vérifie la bonne ouverture du fichier
        fscanf(f, "%d\n", &N); // lecture du nombre de jetons à aligner
        fscanf(f,"%d\n", nbjoueur); // lecture du nombre de joueurs dans la partie

        // définition des dimensions de la grille avec la valeur de N récupérée plus haut
        Grille->largeur = N + 2;
        Grille->longueur = N + 2;

        // lecture et attribution des jetons et initiatives aux joueurs
        fscanf(f,"%c\t%d\n", &j1->jeton, &j1->initiative);
        fscanf(f,"%c\t%d\n", &j2->jeton, &j2->initiative);

        // attribue de l'espace mémoire pour la grille
        Grille->grille = (char **) malloc(sizeof(char *) * Grille->largeur);
        for (int i = 0; i < Grille->largeur; i++) {
            Grille->grille[i] = (char *) malloc(sizeof(char) * Grille->longueur);
        }

        // remplie la grille avec les données sauvegardées
        for (int i = 0; i < N + 2; i++) {
            for (int j = 0; j < N + 2; j++) {
                fscanf(f, "%c", &(Grille->grille[j][i]));
            }
            fscanf(f, "\n");
        }
    } else {
        printf("\nERREUR ouverture fichier sauvegarde !\n");
        printf("\nVeuillez relancer le programme !\n");
    }

    // ferme le fichier précedemment ouvert
    fclose(f);
}

/**
 * Permet de sauvergarder une partie
 * @param Grille : la grille et ses dimensions
 * @param j1 : les caractéristiques du premier joueur, couleur, initiative et type de jeton
 * @param j2 : les caractéristiques du deuxième joueur, couleur, initiative et type de jeton
 * @param nbjoueur : nombre de joueurs (hors ordinateur)
 */
void save(Grid Grille, Joueur j1, Joueur j2, int nbjoueur) {

    // on ouvre le fichier en mode lecture/écriture, suppression du contenu pré-existant
    FILE *f = fopen("save.txt", "w+");

    if (f != NULL) { // on vérifie la bonne ouverture du fichier
        // sauvegarde le nombre N de jetons à aligner
        fprintf(f, "%d\n", (Grille.largeur) - 2);
        // sauvegarde le nombre de joueurs de la partie
        fprintf(f,"%d\n", nbjoueur);

        // sauvegarde les jetons et initiatives de chaque joueur
        fprintf(f,"%c\t%d\n", j1.jeton, j1.initiative);
        fprintf(f,"%c\t%d\n", j2.jeton, j2.initiative);

        // sauvegarde la grille
        for (int i = 0; i < Grille.largeur; i++) {
            for (int j = 0; j < Grille.largeur; j++) {
                fprintf(f, "%c", Grille.grille[j][i]);
            }
            fprintf(f, "\n");
        }
    } else {
        printf("\nERREUR ouverture fichier sauvegarde !\n");
        printf("\nVeuillez relancer le programme !\n");
    }

    // ferme le fichier précedemment ouvert
    fclose(f);
}

/**
 * Permet de régler la couleur d'affichage des textes
 * @param couleur_texte : code (prédéfini) de la couleur du texte
 * @param couleur_fond : code (prédéfini) de la couleur du fond
 */
void color(int couleur_texte, int couleur_fond) {
    // permet de changer la couleur du fond/texte des messages affichés
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleur_fond*16+couleur_texte);
}

/**
 * Libère l'espace mémoire occupé par la grille en fin de programme
 * @param Grille : la grille de jeu et ses dimensions
 */
void free_memory(Grid* Grille) {
    // libère l'espace mémoire occupé par la grille
    for (int i = 0; i < Grille->longueur; ++i) {
        free(Grille->grille[i]);
    }
    free(Grille->grille);
}