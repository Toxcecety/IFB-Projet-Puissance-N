cmake_minimum_required(VERSION 3.19)
project(Projet_Puissance_N C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_Puissance_N main.c gestion_grille.c gestion_grille.h check_winner.c check_winner.h ajout_retrait_jetons.c ajout_retrait_jetons.h jeu.c jeu.h ordinateur.c ordinateur.h header_principal.h)