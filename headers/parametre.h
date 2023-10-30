#ifndef PARAMETRE_H
#define PARAMETRE_H


#include <SDL.h>
#include <SDL_image.h>

// Structures
typedef struct {
    int x, y;
    int largeur, hauteur;
} Joueur;

typedef struct {
    int x, y;
    int largeur, hauteur;
} Obstacle;

typedef struct {
    int numero;
    Joueur joueur;
    Obstacle obstacles[10];
} Niveau;

// Paramètres du jeu
#define NOMBRE_DE_NIVEAUX 10
#define LARGEUR_DE_FENETRE 800
#define HAUTEUR_DE_FENETRE 600

#endif