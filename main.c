#include "headers/parametre.h"




int main()
{
    //initialisation SDL 
    if (SDL_Init(SDL_INIT_VIDEO)!= 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;

    }
    
    // Création de la fenêtre et du renderer
    SDL_Window *fenetre = SDL_CreateWindow("Défis des Mystères", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_DE_FENETRE, HAUTEUR_DE_FENETRE, 0);
    if (!fenetre) {
        fprintf(stderr, "Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 1;
    }

     // Initialisation de SDL_image pour charger des images (si nécessaire)
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 1;
    }

    
    //boucle du jeu 
    int quit = 0;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                quit = 1;
                    break;

                default: {}
            }
        }
        
        // Effacer l'écran (peindre en noir)
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);

    }

    
    // Libération des ressources SDL et sortie du programme
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;

}
