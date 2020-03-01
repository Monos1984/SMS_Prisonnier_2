// **************
// *** game.h ***
// **************

#ifndef GAME_H
#define GAME_H

// -------------------------------------------------
// ** Déclaration des Prototype du fichier game.c **
// -------------------------------------------------
void scene_game();
void init_game();
unsigned char test_mvt(unsigned char id_joueur);
unsigned char test_lost(unsigned char id_joueur);
void draw_wall(unsigned char Px, unsigned char Py);
extern unsigned char ram_board[132];
void ia_wall();
#endif