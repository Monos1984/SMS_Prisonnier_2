/** ============================================================
 ** Class_Scene.c
 ------------------------------------------------------------
 ** Role .......... : Gestion du Workflow
 ** Auteur ........ : Loïc Lété sur une idée de Michel Louvet
 ** Mise à jour ... : 25/01/2018
 ===============================================================
 ** Note du Fichier :
 ---------------------------------------------------------------


 =============================================================== **/

// ----------------------
// * Fichier d'include
// ---------------------
#include "header/prisonnier_2.h"

// ---------------------------
// * Déclaration des variables

// ---------------------------
unsigned char scene;

// ----------------------------------
// * scene_set()
//     Chargement du nom de la scène
// ----------------------------------

void scene_set(unsigned char value)
{
    scene = value;
}


// ------------------------------------
// * scene_get()
//     Récupération du nom de la scène
// ------------------------------------
int scene_get()
{
    return scene;
}
