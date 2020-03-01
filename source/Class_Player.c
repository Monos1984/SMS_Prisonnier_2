/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : Class_Player.c
* Role ........ : Les fonctions qui sont liés au joueur.
* Auteur ...... : Jean Monos
* Version ..... : V1.0 du 8/2/2018
* Licence ..... : Propriétaire
* Compilation.. : SDCC pour la Master System
********************************************************/

// ---------------------
// * Fichier d'include
// ---------------------
#include "header/prisonnier_2.h"


// -------------------------------------------------------
// * Fonction qui permet de réinitialiser les deux joueurs
// -------------------------------------------------------

void reset_player()
{
    // * Joueur numéros 1 *
    player[0].PX = 80;
    player[0].PY = 32;
    player[0].Case_X=5;
    player[0].Case_Y=1;

    // * Joueur numéros 2 *
    player[1].PX = 80;
    player[1].PY = 160;
    player[1].Case_X=5;
    player[1].Case_Y=9;
}

void mvt_ia(signed char px,signed char py)
{
   ram_board[((player[1].PY >> 4) * 11) + (player[1].PX >> 4)] = 0;
                player[1].PX = player[1].PX +px;
                player[1].PY = player[1].PY +py;
                ram_board[((player[1].PY >> 4) * 11) + (player[1].PX >> 4)] = 1;
                

}