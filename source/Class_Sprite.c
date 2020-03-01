/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : Class_Sprite.c
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

// --------------------------------------
// Routine d'affichage des sprites du jeu
// --------------------------------------
void draw_sprite()
{

    // Initiation des sprites
    SMS_initSprites();

    // Affichage du curseur
    // Tiles 272 => 275
    SMS_addSprite(curseur.PX, curseur.PY, 272);
    SMS_addSprite(curseur.PX + 8, curseur.PY, 273);

    SMS_addSprite(curseur.PX, curseur.PY + 8, 274);
    SMS_addSprite(curseur.PX + 8, curseur.PY + 8, 275);

    // Affichage des sprites du joueur 1
    // Tiles 256 => 263
    SMS_addSprite(player[0].PX, player[0].PY - 24 + DECALAGE_Y, 256);
    SMS_addSprite(player[0].PX + 8, player[0].PY - 24 + DECALAGE_Y, 257);

    SMS_addSprite(player[0].PX, player[0].PY - 16 + DECALAGE_Y, 258);
    SMS_addSprite(player[0].PX + 8, player[0].PY - 16 + DECALAGE_Y, 259);

    SMS_addSprite(player[0].PX, player[0].PY - 8 + DECALAGE_Y, 260);
    SMS_addSprite(player[0].PX + 8, player[0].PY - 8 + DECALAGE_Y, 261);

    SMS_addSprite(player[0].PX, player[0].PY + DECALAGE_Y, 262);
    SMS_addSprite(player[0].PX + 8, player[0].PY + DECALAGE_Y, 263);

    // Affichage des sprites du joueur 2
    // Tiles 264=>271
    SMS_addSprite(player[1].PX, player[1].PY - 24 + DECALAGE_Y, 264);
    SMS_addSprite(player[1].PX + 8, player[1].PY - 24 + DECALAGE_Y, 265);

    SMS_addSprite(player[1].PX, player[1].PY - 16 + DECALAGE_Y, 266);
    SMS_addSprite(player[1].PX + 8, player[1].PY - 16 + DECALAGE_Y, 267);

    SMS_addSprite(player[1].PX, player[1].PY - 8 + DECALAGE_Y, 268);
    SMS_addSprite(player[1].PX + 8, player[1].PY - 8 + DECALAGE_Y, 269);

    SMS_addSprite(player[1].PX, player[1].PY + DECALAGE_Y, 270);
    SMS_addSprite(player[1].PX + 8, player[1].PY + DECALAGE_Y, 271);

    // Mise en mémoire vidéo
    SMS_copySpritestoSAT();
}