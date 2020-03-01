/*******************************************************
* Projet ...... : Prisonnier 2
* Nom ......... : Class_Input.c
* Role ........ : Les fonctions gamepad.
* Auteur ...... : Jean Monos
* Version ..... : V1.0 du 9/2/2018
* Licence ..... : Propriétaire
* Compilation.. : SDCC pour la Master System
********************************************************/

// ---------------------
// * Fichier d'include
// ---------------------
#include "header/prisonnier_2.h"

// -----------------------------------------------------------
// * Fonction pour récupérer la touche utilisé par le joueur *
// -----------------------------------------------------------
unsigned char get_input(unsigned char id_player)
{

    // ***********************************
    // * Gestion du pad pour le joueur 1 *
    // ***********************************
    if (id_player == 0)
    {
        if (SMS_getKeysPressed() & PORT_A_KEY_LEFT)
        {
            return 4;
        }
        else if (SMS_getKeysPressed() & PORT_A_KEY_RIGHT)
        {
            return 6;
        }
        else if (SMS_getKeysPressed() & PORT_A_KEY_UP)
        {
            return 8;
        }
        else if (SMS_getKeysPressed() & PORT_A_KEY_DOWN)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    // ***********************************
    // * Gestion du pad pour le joueur 2 *
    // ***********************************
    else if (id_player == 1)
    {
        if (SMS_getKeysPressed() & PORT_B_KEY_LEFT)
        {
            return 4;
        }
        else if (SMS_getKeysPressed() & PORT_B_KEY_RIGHT)
        {
            return 6;
        }
        else if (SMS_getKeysPressed() & PORT_B_KEY_UP)
        {
            return 8;
        }
        else if (SMS_getKeysPressed() & PORT_B_KEY_DOWN)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    // ***********************
    // * Renvois 0 en cas ou *
    // ***********************
    else
    {
        return 0;
    }
}
