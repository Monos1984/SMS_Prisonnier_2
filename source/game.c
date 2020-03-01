/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : Game.c
* Role ........ : Fonction du jeu en lui même
* Auteur ...... : Jean Monos
* Version ..... : V1.0 du 8/2/2018
* Licence ..... : Propriétaire
* Compilation.. : SDCC pour la Master System
********************************************************/

// ---------------------
// * Fichier d'include
// ---------------------
#include "header/prisonnier_2.h"

// -----------------------------------------
// * scene_game : Boucle principale du jeu *
// -----------------------------------------

void scene_game()
{

    // *****************************
    // * Déclaration des variables *
    // *****************************
    static unsigned char compteur_cycle;
    extern unsigned char rom_board[];
    unsigned char id_action = 0;
    unsigned char id_player = 0;
    unsigned char lost_p1 = 0;
    unsigned char lost_p2 = 0;
    unsigned char alleatoire = 0;
    unsigned char x;

    // ************************
    // * Initiation de la ram *
    // ************************
    for (x = 0; x < 132; x++)
    {
        ram_board[x] = rom_board[x];
    }

    // *************************
    // * Initiation du plateau *
    // *************************

    init_game();
    curseur.PX = player[0].PX;
    curseur.PY = player[0].PY;

    while (scene_get() == SCENE_GAME)
    {
        // **********************************
        // * Decomposition d'un tour de jeu *
        // **********************************
        // Mouvement du joueur 1
        // Pose du mur du joueur 1
        // Test de défaite
        // Mouvement du joueur 2
        // Pose du mur du joueur 2
        // Test de défaite

        // Texte
        instruction_player(id_action);

        // **********************
        // * Gestion du curseur *
        // **********************

        if ((get_input(id_player) == 4) && (curseur.PX > 16))
        {
            curseur.PX = curseur.PX - 16;
        }
        else if ((get_input(id_player) == 6) && (curseur.PX < 144))
        {
            curseur.PX = curseur.PX + 16;
        }
        else if ((get_input(id_player) == 8) && (curseur.PY > 32))
        {
            curseur.PY = curseur.PY - 16;
        }
        else if ((get_input(id_player) == 2) && (curseur.PY < 160))
        {
            curseur.PY = curseur.PY + 16;
        }

        // ***************************
        // * Deplacement du joueur 1 *
        // ***************************
        if ((id_action == 0) && (SMS_getKeysPressed() & PORT_A_KEY_2))
        {
            if (ram_board[((curseur.PY >> 4) * 11) + (curseur.PX >> 4)] == 0)
            {
                if (test_mvt(0) == 1)
                {

                    play_sound(0);

                    id_action = 1;
                }
            }
        }

        // **************************************
        // * Création de l'obstacle du joueur 1 *
        // **************************************
        else if ((id_action == 1) && (SMS_getKeysPressed() & PORT_A_KEY_2))
        {
            if (ram_board[((curseur.PY >> 4) * 11) + (curseur.PX >> 4)] == 0)
            {

                // Création de l'obstacle du joueur 1

                draw_wall(curseur.PX, curseur.PY);

                id_action = 2;

                // Passage au joueur suivant en fonction si c'est un humain ou ordinateur
                if (mode_game == 2)
                {
                    id_player = 1;
                }
                else
                {
                    id_player = 3;
                }

                curseur.PX = player[1].PX;
                curseur.PY = player[1].PY;
            }
        }

        // *************************
        // * Test de fin de partie *
        // *************************

        else if (id_action == 2 || id_action == 5)
        {

            //Test de fin de partie
            lost_p1 = test_lost(0);
            lost_p2 = test_lost(1);

            // Egalité
            if ((lost_p1 == 1) && (lost_p2 == 1))
            {

                game_over(0);
            }
            // Victoire P1
            else if ((lost_p1 == 0) && (lost_p2 == 1))
            {

                game_over(1);
            }
            // Victoire P2
            else if ((lost_p1 == 1) && (lost_p2 == 0))
            {
                game_over(2);
            }
            // Joueur suivant
            else if ((lost_p1 == 0) && (lost_p2 == 0))
            {
                if (id_action == 5)
                {
                    id_action = 0;
                }
                else
                {
                    id_action = 3;
                }
            }
        }

        // ***************************
        // * Deplacement du joueur 2 *
        // ***************************
        else if ((id_action == 3) && (SMS_getKeysPressed() & PORT_B_KEY_2) && (mode_game == 2))
        {
            if (ram_board[((curseur.PY >> 4) * 11) + (curseur.PX >> 4)] == 0)
            {
                // Déplacement du jou eur 2
                if (test_mvt(1) == 1)
                {
                    play_sound(0);
                    id_action = 4;
                }
            }
        }

        // ***********************
        // * Déplacement de l'ia *
        // ***********************
        else if ((id_action == 3) && (mode_game == 1))
        {
            alleatoire = rand() % 8;

            if ((alleatoire == 0) && (ram_board[((player[1].PY >> 4) * 11) + ((player[1].PX - 16) >> 4)] == 0))
            {
                mvt_ia(-16, 0);
                id_action = 5;
            }
            else if ((alleatoire == 1) && (ram_board[((player[1].PY >> 4) * 11) + ((player[1].PX + 16) >> 4)] == 0))
            {
                mvt_ia(16, 0);
                id_action = 5;
            }
            else if ((alleatoire == 2) && (ram_board[(((player[1].PY - 16) >> 4) * 11) + (player[1].PX >> 4)] == 0))
            {
                mvt_ia(0, -16);
                id_action = 5;
            }

            else if ((alleatoire == 3) && (ram_board[(((player[1].PY + 16) >> 4) * 11) + (player[1].PX >> 4)] == 0))
            {
                mvt_ia(0, 16);
                id_action = 5;
            }

            else if ((alleatoire == 4) && (ram_board[(((player[1].PY + 16) >> 4) * 11) + ((player[1].PX + 16) >> 4)] == 0))
            {
                mvt_ia(16, 16);
                id_action = 5;
            }

            else if ((alleatoire == 5) && (ram_board[(((player[1].PY - 16) >> 4) * 11) + ((player[1].PX + 16) >> 4)] == 0))
            {
                mvt_ia(16, -16);
                id_action = 5;
            }

            else if ((alleatoire == 6) && (ram_board[(((player[1].PY + 16) >> 4) * 11) + ((player[1].PX - 16) >> 4)] == 0))
            {
                mvt_ia(-16, 16);

                id_action = 5;
            }

            else if ((alleatoire == 7) && (ram_board[(((player[1].PY - 16) >> 4) * 11) + ((player[1].PX - 16) >> 4)] == 0))
            {
                mvt_ia(-16, -16);
                id_action = 5;
            }

            else if (alleatoire == 8)
            {
                srand(SMS_getVCount());
            }

            if (id_action == 5)
            {
                id_player = 0;
                curseur.PX = player[0].PX;
                curseur.PY = player[0].PY;
                SMS_waitForVBlank();
                draw_sprite();
                ia_wall();
            }
        }

        // **************************************
        // * Création de l'obstacle du joueur 2 *
        // **************************************
        else if ((id_action == 4) && (SMS_getKeysPressed() & PORT_B_KEY_2) && (mode_game == 2))
        {
            if (ram_board[((curseur.PY >> 4) * 11) + (curseur.PX >> 4)] == 0)
            {
                play_sound(1);
                // Création de l'obstacle du joueur 2
                draw_wall(curseur.PX, curseur.PY);
                id_action = 5;
                id_player = 0;
                curseur.PX = player[0].PX;
                curseur.PY = player[0].PY;
            }
        }

        // *********
        // * Autre *
        // *********
        compteur_cycle = compteur_cycle + 1;
        // * Syncrhonisation Vertical *
        SMS_waitForVBlank();

        // Modification des annimations
        if (compteur_cycle == 20)
        {
            // Inversion des sprites pour le test
            SMS_loadPSGaidencompressedTiles(p1_B_psgcompr, 256);
        }
        if (compteur_cycle == 21)
        {
            // Inversion des sprites pour le test

            SMS_loadPSGaidencompressedTiles(p2_B_psgcompr, 264);
        }
        else if (compteur_cycle == 40)
        {
            SMS_loadPSGaidencompressedTiles(p1_A_psgcompr, 256);
        }
        else if (compteur_cycle == 41)
        {

            SMS_loadPSGaidencompressedTiles(p2_A_psgcompr, 264);
            compteur_cycle = 0;
        }

        // * Update des sprites et tiles *
        draw_sprite();
    }
}

// -----------------------------
// initiation du jeu en lui même
// -----------------------------
void init_game()
{
    // Mise en mémoire des palettes de couleur
    // Mise en mémoire de tiles
    // Affichage de background
    // Initiation de la mémoire d'emplacement des obstacles
    // Initiation  des deux joueurs

    reset_player();
    // * Syncrhonisation Vertical
    SMS_waitForVBlank();
    // * Palette pour le Bakcground
    SMS_loadBGPalette(mokup_palette__bin);

    // * Tiles Background
    SMS_loadPSGaidencompressedTiles(mokup_psgcompr, 1);
    // * Tiles Font
    SMS_loadPSGaidencompressedTiles(policefuturiste_psgcompr, 83);

    // * Chargement des sprites de départ en mémoire
    SMS_loadSpritePalette(sprite_palette__bin);
    SMS_setSpritePaletteColor (0, 0x00);
    SMS_loadPSGaidencompressedTiles(p1_A_psgcompr, 256);
    SMS_loadPSGaidencompressedTiles(p2_A_psgcompr, 264);

    SMS_loadPSGaidencompressedTiles(curseur_psgcompr, 272);

    // * Affichage de la Tilemap pour le background
    SMS_loadTileMap(0, 0, (unsigned int *)tilemap_bin, tilemap_bin_size);
    // * Syncrhonisation Vertical
    SMS_waitForVBlank();
    // * Affichage de l'écran
    SMS_displayOn();
}

// -------------------------------------------
// Mouvement d'un jouer avec test de collision
// -------------------------------------------
unsigned char test_mvt(unsigned char id_joueur)
{

    if (

        // Case de droite
        ((curseur.PX == player[id_joueur].PX + 16) && (curseur.PY == player[id_joueur].PY)) ||

        // Case de gauche
        ((curseur.PX == player[id_joueur].PX - 16) && (curseur.PY == player[id_joueur].PY)) ||

        // Case Haut
        ((curseur.PX == player[id_joueur].PX) && (curseur.PY == player[id_joueur].PY - 16)) ||

        // Case Bas
        ((curseur.PX == player[id_joueur].PX) && (curseur.PY == player[id_joueur].PY + 16)) ||

        // Haut/Droite
        ((curseur.PX == player[id_joueur].PX + 16) && (curseur.PY == player[id_joueur].PY - 16)) ||

        // Haut/Gauche
        ((curseur.PX == player[id_joueur].PX - 16) && (curseur.PY == player[id_joueur].PY - 16)) ||

        // Bas/Droite
        ((curseur.PX == player[id_joueur].PX + 16) && (curseur.PY == player[id_joueur].PY + 16)) ||

        // Bas/Gauche
        ((curseur.PX == player[id_joueur].PX - 16) && (curseur.PY == player[id_joueur].PY + 16)))
    {

        ram_board[((player[id_joueur].PY >> 4) * 11) + (player[id_joueur].PX >> 4)] = 0;
        player[id_joueur].PX = curseur.PX;
        player[id_joueur].PY = curseur.PY;
        ram_board[((player[id_joueur].PY >> 4) * 11) + (player[id_joueur].PX >> 4)] = 1;
        return 1;
    }
    return 0;
}

// --------------------------------------------------------------
// Test pour savoir si un joueur est bloqué dans les 8 directions
// --------------------------------------------------------------
unsigned char test_lost(unsigned char id_joueur)
{
    if (

        // Bas
        (ram_board[((((player[id_joueur].PY >> 4) + 1) * 11)) + (player[id_joueur].PX >> 4)]) +
            // Haut
            (ram_board[((((player[id_joueur].PY >> 4) - 1) * 11)) + (player[id_joueur].PX >> 4)]) +
            // Gauche
            (ram_board[(((player[id_joueur].PY >> 4) * 11)) + ((player[id_joueur].PX >> 4) - 1)]) +
            // Droite
            (ram_board[(((player[id_joueur].PY >> 4) * 11)) + ((player[id_joueur].PX >> 4) + 1)]) +
            // Haut-Gauche
            (ram_board[((((player[id_joueur].PY >> 4) - 1) * 11)) + ((player[id_joueur].PX >> 4) - 1)]) +
            // Haut-Droite
            (ram_board[((((player[id_joueur].PY >> 4) - 1) * 11)) + ((player[id_joueur].PX >> 4) + 1)]) +
            // Bas-Gauche
            (ram_board[((((player[id_joueur].PY >> 4) + 1) * 11)) + ((player[id_joueur].PX >> 4) - 1)]) +
            // Bas-Droite
            (ram_board[((((player[id_joueur].PY >> 4) + 1) * 11)) + ((player[id_joueur].PX >> 4) + 1)]) ==
        8)

    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void draw_wall(unsigned char Px, unsigned char Py)
{
    ram_board[((Py >> 4) * 11) + (Px >> 4)] = 1;
    SMS_setTileatXY(Px >> 3, Py >> 3, 1);
    SMS_setTileatXY((Px >> 3) + 1, Py >> 3, 2);
    SMS_setTileatXY(Px >> 3, (Py >> 3) + 1, 3);
    SMS_setTileatXY((Px >> 3) + 1, (Py >> 3) + 1, 4);
    play_sound(1);
}

void ia_wall()
{
    unsigned char x;
    unsigned char y;
    unsigned char id_joueur =0;
    unsigned char ok = 0;

    while (ok == 0)
    {
        // Tuile à coté du joueur 1
        // Bas

        if ((ram_board[((((player[id_joueur].PY >> 4) + 1) * 11)) + (player[id_joueur].PX >> 4)] == 0) && (rand() % 20 == 1) )
        {
            draw_wall(player[id_joueur].PX , player[id_joueur].PY  + 16);
            ok = 1;
        }
          
        else if // Haut
            ((ram_board[((((player[id_joueur].PY >> 4) - 1) * 11)) + (player[id_joueur].PX >> 4)] == 0) && (rand() % 20 == 1)&& (player[id_joueur].PY>>4 > 3))
        {
            draw_wall(player[id_joueur].PX , player[id_joueur].PY  - 16);
            ok = 1;
        }
        // Gauche
      
        else if ((ram_board[(((player[id_joueur].PY >> 4) * 11)) + ((player[id_joueur].PX >> 4) - 1)] == 0) && (rand() % 20 == 1))
        {
            draw_wall(player[id_joueur].PX  - 16, player[id_joueur].PY );
            ok = 1;
        }
        else if
            // Droite
            ((ram_board[(((player[id_joueur].PY >> 4) * 11)) + ((player[id_joueur].PX >> 4) + 1)] == 0) && (rand() % 20 == 1))
        {
            draw_wall(player[id_joueur].PX  + 16, player[id_joueur].PY );
            ok = 1;
        }
        // Haut-Gauche
        else if ((ram_board[((((player[id_joueur].PY >> 4) - 1) * 11)) + ((player[id_joueur].PX >> 4) - 1)] == 0) && (rand() % 20 == 1))
        {
           if ((player[0].PY)>49)
           {draw_wall(player[id_joueur].PX - 16, player[id_joueur].PY  - 16);
           ok = 1;}
        }
        
        
        // Haut-Droite
        else if ((ram_board[((((player[id_joueur].PY >> 4) - 1) * 11)) + ((player[id_joueur].PX >> 4) + 1)] == 0) && (rand() % 20 == 1))
        {
            draw_wall(player[id_joueur].PX  + 16, player[id_joueur].PY  - 16);
            ok = 1;
        }
        // Bas-Gauche
        else if ((ram_board[((((player[id_joueur].PY >> 4) + 1) * 11)) + ((player[id_joueur].PX >> 4) - 1)] == 0) && (rand() % 20 == 1))
        {
            draw_wall(player[id_joueur].PX - 16, player[id_joueur].PY  + 16);
            ok = 1;
        }
        // Bas-Droite
        else if ((ram_board[((((player[id_joueur].PY >> 4) + 1) * 11)) + ((player[id_joueur].PX >> 4) + 1)] == 0) && (rand() % 20 == 1))
        {
            draw_wall(player[id_joueur].PX  - 16, player[id_joueur].PY  - 16);
            ok = 1;
        }
        
    }
    // pose aléatoire de tuile
    /*
    for (y = 1; y < 11; y++)
    {
        for (x = 1; x < 10; x++)
        {

            if ((rand() % 20 == 1) && (ram_board[((y)*11) + (x)] == 0))
            {
                draw_wall(x * 16, y * 16);
            }
        }
    }
    */
}