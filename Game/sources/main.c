#include "../headers/prototypes.h"
#include "../headers/audio.h"

Input input;


int main()
{
unsigned int frameLimit = SDL_GetTicks() + 16;
int game;

// Initialisation de la SDL
init("Défis des mystères");

// Initialisation de l'Audio
initAudio();
// Musique du jeu
playMusic("../audio/melody.wav", 10);

// Chargement des graphismes, sons...etc
loadGame();

/*  initialisation du player  */
initializePlayer();

// Appelle la fonction free a la fin du programme
atexit(free);

game = 1;

// Boucle infinie, principale, du jeu
while (game == 1)
{
    //Gestion des clavier
    getInput(&input);

    //On dessine tout
    drawMenu();

    while(input.jouer == 1){
        //Gestion des inputs clavier
        getInput(&input);

        
        // On met a jour le jeu, en commencant par le joueur
        updatePlayer(&input);

        desGame();
    }

    // 60 fps (1000ms/60 = 16.6 -> 16
    delay(frameLimit);
    frameLimit = SDL_GetTicks() + 16;
}
endAudio();
// On quitte
exit(0);

}
