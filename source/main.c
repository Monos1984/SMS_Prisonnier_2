/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : main.c
* Role ........ : Fichier main pour lancer le programme.
* Auteur ...... : Jean Monos
* Version ..... : V1.0 du 8/2/2018
* Licence ..... : Propriétaire
* Compilation.. : SDCC pour la Master System
********************************************************/

// ---------------------
// * Fichier d'include *
// ---------------------
#include "header/prisonnier_2.h"

// ------------------------------------------------------------------
// * En tête de la rom pour que cela soit lisible sur Master System *
// ------------------------------------------------------------------
SMS_EMBED_SEGA_ROM_HEADER(0, 1);
SMS_EMBED_SDSC_HEADER(1, 1, 2019, 06, 15, "Offgame", "Prisonnier2", "Game");

// ****************************************************************
// ** Fonction main qui est la fonction initiale du programme... **
// ****************************************************************
void main(void)
{

	scene_set(INTRODUCTION);

	// *************************
	// ** Boucle du programme **
	// *************************
	while (1)
	{
		unsigned char t = 0;
		if (scene_get() == INTRODUCTION)
		{

			// * Palette pour le Bakcground
			SMS_loadBGPalette(credit_palette__bin);

			// * Tiles Background
			SMS_loadPSGaidencompressedTiles(credit_psgcompr, 0);

			// * Affichage de la Tilemap pour le background
			SMS_loadTileMap(0, 0, (unsigned int *)credit_bin, credit_bin_size);
			// * Syncrhonisation Vertical
			SMS_waitForVBlank();

			// * Affichage de l'écran
			SMS_displayOn();

			while (t < 200)
			{
				SMS_waitForVBlank();
				t++;
			}
			SMS_displayOff();
			SMS_waitForVBlank();
			scene_set(SCENE_TITLE_SCREEN);
		}

		else if (scene_get() == SCENE_TITLE_SCREEN)
		{

			scene_title_screen();
		}
		else if (scene_get() == SCENE_GAME)
		{
			scene_game();
		}
	}
}
