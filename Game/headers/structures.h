#ifndef STRUCTURES
#define STRUCTURES

#include "param.h"

//*** Les structures seront regroupées ici ***

//Input : gérer le clavier
typedef struct Input{

    int left, right, jump, quitter, jouer;

} Input;

//Map : gérer la map
typedef struct Map{

    SDL_Texture *background;
    SDL_Texture *tileSet;
    SDL_Texture *padH;

    // Coordonnées de départ du thief
    int beginx, beginy;


    // Tableau contenant les infos du fichier
    char tile[MAP_Y][MAP_X];

} Map;



// Structure pour gérer nos sprites
typedef struct GameObject{
    // Coordonnees du sprite
    int x, y;

    // Largeur, hauteur du sprite
    int h, w;

    // Pour l'animation
    int frameNumber, frameTimer, frameMax;
    // etat : FREEZ, WALK etc...
    int etat, direction;

    //s'il est vivant/mort
    int alive;
    //s'il est sur le sol
    int onGround, timerSaut;
    //Vecteurs de deplacement temporaires (pour collision)
    float dirX, dirY;


    //Pour le score
    int score;
    struct GameObject* next;


} GameObject;



#endif
