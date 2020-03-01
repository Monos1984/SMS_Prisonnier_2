/** ============================================================
 ** Class_Scene.h
 ------------------------------------------------------------
 ** Role .......... : Fichier d'entête des Scenes
 ** Auteur ........ : Loïc Lété sur une idée de Michel Louvet
 ** Mise à jour ... : 31/12/2017
 ===============================================================
 ** Note du Fichier :
 ---------------------------------------------------------------


 ===============================================================
 **/


#ifndef CLASS_SCENE_H
    #define CLASS_SCENE_H

    // ------------------------------
    // * Les Defines des Scenes
    // ------------------------------
    #define SCENE_INIT 0
    #define SCENE_TITLE_SCREEN 1
    #define SCENE_GAME 2
	
	#define SCENE_GAME_OVER 3 
	#define SCENE_DEBUG 18
    #define INTRODUCTION 20



    // ----------------------------------
    // * Déclaration des prototypes
    // ----------------------------------

    void scene_set(unsigned char value);
    int scene_get();

#endif
