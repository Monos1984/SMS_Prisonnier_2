/** ============================================================
 ** Class_Player.h
 ------------------------------------------------------------
 ** Role .......... : Gestion des joueurs
 ** Auteur ........ : Loïc Lété
 ** Mise à jour ... : 8/02/2018
 ===============================================================
 ** Note du Fichier :
 ---------------------------------------------------------------


 ===============================================================
 **/

#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H


// --------------------
// * Structure Player *
// --------------------
typedef struct
{
    unsigned char PX;
    unsigned char PY;
    unsigned char Case_X;
    unsigned char Case_Y;
  
} s_player;

typedef struct
{
    unsigned char PX;
    unsigned char PY;
    unsigned char Case_X;
    unsigned char Case_Y;
} s_curseur;

// -------------------
// * Variable Global *
// -------------------
extern s_player player[2];
extern s_curseur curseur;
extern unsigned char mode_game;

// ----------------------------------
// * Déclaration des prototypes
// ----------------------------------
void reset_player();
void mvt_ia(signed char px,signed char py);
#endif
