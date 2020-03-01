/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : Sound.c
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

void play_sound(unsigned char id_sound)
{
    unsigned char t;

    if (id_sound == 0)
    {
        PSGSFXPlay(moved_fx_psg, SFX_CHANNEL3);
    }
    else if (id_sound == 1)
    {
        PSGSFXPlay(wall_psg, SFX_CHANNEL3);
    }

    for (t = 0; t < 10; t++)
    {
        SMS_waitForVBlank();
        PSGSFXFrame();
    }
    PSGSFXStop();
}