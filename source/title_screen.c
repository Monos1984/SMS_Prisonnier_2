/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : Title_screen.c
* Role ........ : Ecran titre du jeu
* Auteur ...... : Jean Monos
* Version ..... : V1.0 du 22/2/2018
* Licence ..... : Propriétaire
* Compilation.. : SDCC pour la Master System
********************************************************/

// ---------------------
// * Fichier d'include
// ---------------------
#include "header/prisonnier_2.h"

// ---------------------
// * Ecran Titre du jeu
// ---------------------

void scene_title_screen()
{
    unsigned char x;

    // --------------------------------------------
    // * Chargement des graphismes de l'écran titre
    // --------------------------------------------
    SMS_waitForVBlank();
     SMS_initSprites ();
     for (x=0;x<64;x++)
     {
         SMS_hideSprite (x);
     }
     SMS_copySpritestoSAT ();
    // * Palette pour le Bakcground
    SMS_loadBGPalette(tille_screen_palette__bin);

    // * Tiles Background
    SMS_loadPSGaidencompressedTiles(tille_screen_psgcompr, 0);

    // * Affichage de la Tilemap pour le background
    SMS_loadTileMap(0, 0, (unsigned int *)tille_screen_bin, tille_screen_bin_size);
    // * Syncrhonisation Vertical
    SMS_waitForVBlank();
    // * Musique *
    PSGPlay(title_screen_music_psg);
    // * Affichage de l'écran
    SMS_displayOn();

    while (scene_get() == SCENE_TITLE_SCREEN)
    {
        SMS_waitForVBlank();
        PSGFrame();
        if (SMS_getKeysPressed() & PORT_A_KEY_1)
        {
            mode_game = 1;
             srand(SMS_getVCount ());
            SMS_waitForVBlank();
            PSGStop();
            SMS_displayOff();
            SMS_waitForVBlank();
            scene_set(SCENE_GAME);
        }
        else if (SMS_getKeysPressed() & PORT_B_KEY_1)
        {
            mode_game = 2;
            SMS_waitForVBlank();
            PSGStop();
            SMS_displayOff();
            SMS_waitForVBlank();
            scene_set(SCENE_GAME);
        }
    }
}

