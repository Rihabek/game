#include "../headers/prototypes.h"
#include "../headers/audio.h"

/* Déclaration des variables / structures utilisées par le jeu */
Input input;


int main(int argc, char *argv[])
{
unsigned int frameLimit = SDL_GetTicks() + 16;
int go;

// Initialisation de la SDL
init("Défis des mystères");

// Initialisation de l'Audio
initAudio();
// Musique du jeu
playMusic("../audio/melody.wav", 10);

// Chargement des ressources (graphismes, sons)
loadGame();

/* On initialise le joueur */
initializePlayer();

// Appelle la fonction cleanup � la fin du programme
atexit(cleanup);

go = 1;

// Boucle infinie, principale, du jeu
while (go == 1)
{
    //Gestion des inputs clavier
    getInput(&input);

    //On dessine tout
    drawMenu();

    while(input.jouer == 1){
        //Gestion des inputs clavier
        getInput(&input);

        // On met � jour le jeu, en commen�ant par le joueur
        updatePlayer(&input);

        drawGame();
    }

    // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
    delay(frameLimit);
    frameLimit = SDL_GetTicks() + 16;
}
endAudio();
// On quitte
exit(0);

}
