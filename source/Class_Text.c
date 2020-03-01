/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : Class_Text.c
* Role ........ : Les fonctions des sprites.
* Auteur ...... : Jean Monos
* Version ..... : V1.0 du 8/2/2018
* Licence ..... : Propriétaire
* Compilation.. : SDCC pour la Master System
********************************************************/
// ----------------------
// * Fichier d'include
// ---------------------
#include "header/prisonnier_2.h"

// --------------------------------------------------------------
// instruction joueur
// --------------------------------------------------------------

void instruction_player(unsigned char id)
{
    // Player 1 Moved
    if ((id == 0) || (id == 3))
    {
        // Player
        SMS_setTileatXY(23, 3, 99);
        SMS_setTileatXY(24, 3, 95);
        SMS_setTileatXY(25, 3, 84);
        SMS_setTileatXY(26, 3, 108);
        SMS_setTileatXY(27, 3, 88);
        SMS_setTileatXY(28, 3, 101);
        SMS_setTileatXY(29, 3, 0);

        // 1 ou 2
        if (id == 0)
        {
            SMS_setTileatXY(30, 3, 92);
        }
        else
        {
            SMS_setTileatXY(30, 3, 111);
        }

        // Moved
        SMS_setTileatXY(23, 5, 0);
        SMS_setTileatXY(24, 5, 96);
        SMS_setTileatXY(25, 5, 98);
        SMS_setTileatXY(26, 5, 105);
        SMS_setTileatXY(27, 5, 88);
        SMS_setTileatXY(28, 5, 87);
        SMS_setTileatXY(29, 5, 0);
        SMS_setTileatXY(30, 5, 0);

        // Blanck
        SMS_setTileatXY(23, 7, 0);
        SMS_setTileatXY(24, 7, 0);
        SMS_setTileatXY(25, 7, 0);
        SMS_setTileatXY(26, 7, 0);
        SMS_setTileatXY(27, 7, 0);
        SMS_setTileatXY(28, 7, 0);
        SMS_setTileatXY(29, 7, 0);
        SMS_setTileatXY(30, 7, 0);
    }

    // Player 1 Place wall
    else if ((id == 1) || (id == 4))
    {

        // Player
        SMS_setTileatXY(23, 3, 99);
        SMS_setTileatXY(24, 3, 95);
        SMS_setTileatXY(25, 3, 84);
        SMS_setTileatXY(26, 3, 108);
        SMS_setTileatXY(27, 3, 88);
        SMS_setTileatXY(28, 3, 101);
        SMS_setTileatXY(29, 3, 0);

        // 1 ou 2
        if (id == 1)
        {
            SMS_setTileatXY(30, 3, 92);
        }
        else
        {
            SMS_setTileatXY(30, 3, 111);
        }

        // Place
        SMS_setTileatXY(23, 5, 0);

        SMS_setTileatXY(24, 5, 99);
        SMS_setTileatXY(25, 5, 95);
        SMS_setTileatXY(26, 5, 84);
        SMS_setTileatXY(27, 5, 86);
        SMS_setTileatXY(28, 5, 88);
        SMS_setTileatXY(29, 5, 0);
        SMS_setTileatXY(30, 5, 0);

        // Wall
        SMS_setTileatXY(23, 7, 0);
        SMS_setTileatXY(24, 7, 0);
        SMS_setTileatXY(25, 7, 106);
        SMS_setTileatXY(26, 7, 84);
        SMS_setTileatXY(27, 7, 95);
        SMS_setTileatXY(28, 7, 95);
        SMS_setTileatXY(29, 7, 0);
        SMS_setTileatXY(30, 7, 0);
    }
}

void game_over(unsigned char id_win)
{

    SMS_setTileatXY(4, 12, 9 | TILE_PRIORITY);
    SMS_setTileatXY(5, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(6, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(7, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(8, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(9, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(10, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(11, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(12, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(13, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(14, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(15, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(16, 12, 10 | TILE_PRIORITY);
    SMS_setTileatXY(17, 12, 11 | TILE_PRIORITY);

    SMS_setTileatXY(4, 13, 12 | TILE_PRIORITY);
    SMS_setTileatXY(5, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(6, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(7, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(8, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(9, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(10, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(11, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(12, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(13, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(14, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(15, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(16, 13, 0 | TILE_PRIORITY);
    SMS_setTileatXY(17, 13, 21 | TILE_PRIORITY);

    SMS_setTileatXY(4, 14, 32 | TILE_PRIORITY);
    SMS_setTileatXY(5, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(6, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(7, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(8, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(9, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(10, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(11, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(12, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(13, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(14, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(15, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(16, 14, 33 | TILE_PRIORITY);
    SMS_setTileatXY(17, 14, 34 | TILE_PRIORITY);

    if (id_win == 0)
    {
        // Draw
        SMS_setTileatXY(8, 13, 87 | TILE_PRIORITY);
        SMS_setTileatXY(9, 13, 101 | TILE_PRIORITY);
        SMS_setTileatXY(10, 13, 84 | TILE_PRIORITY);
        SMS_setTileatXY(11, 13, 106 | TILE_PRIORITY);
    }
    else
    {

        // Player
        SMS_setTileatXY(5, 13, 99 | TILE_PRIORITY);
        SMS_setTileatXY(6, 13, 95 | TILE_PRIORITY);
        SMS_setTileatXY(7, 13, 84 | TILE_PRIORITY);
        SMS_setTileatXY(8, 13, 108 | TILE_PRIORITY);
        SMS_setTileatXY(9, 13, 88 | TILE_PRIORITY);
        SMS_setTileatXY(10, 13, 101 | TILE_PRIORITY);
        SMS_setTileatXY(11, 13, 0 | TILE_PRIORITY);

        // 1 ou 2
        if (id_win == 1)
        {
            SMS_setTileatXY(12, 13, 92 | TILE_PRIORITY);
            SMS_setTileatXY(13, 13, 0 | TILE_PRIORITY);
        }
        else
        {
            SMS_setTileatXY(12, 13, 111 | TILE_PRIORITY);
            SMS_setTileatXY(13, 13, 0 | TILE_PRIORITY);
        }
        //win
        SMS_setTileatXY(14, 13, 106 | TILE_PRIORITY);
        SMS_setTileatXY(15, 13, 92 | TILE_PRIORITY);
        SMS_setTileatXY(16, 13, 97 | TILE_PRIORITY);
    }

    while ((SMS_getKeysPressed() & PORT_A_KEY_2) == 0)
    {
        SMS_waitForVBlank();
    }
    SMS_waitForVBlank();

    SMS_displayOff();
    scene_set(SCENE_TITLE_SCREEN);
}
