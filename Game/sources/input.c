#include "../headers/prototypes.h"


void getInput(Input *input){
    SDL_Event event;

    //Keymapping : pour les touche du clavier

    //SDL_PollEvent : test s'il y a des Evenements en attente ou non
    while (SDL_PollEvent(&event)){
        //Test du type d'evenement
        switch (event.type){
            case SDL_QUIT:
                exit(0);
            break;

            //Quand une touche est enfoncee, on active l'evenement correspondant
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        input->jouer = 0;
                    break;

                    case SDLK_SPACE:
                        input->jump = 1;
                    break;

                    case SDLK_LEFT:
                        input->left = 1;
                    break;

                    case SDLK_RIGHT:
                        input->right = 1;
                    break;

                    case SDLK_UP:
                        input->jump = 1;
                    break;

                    default:
                    break;
                }
            break;

            //Quand la touche est relevee, on desactive l'evenement correspondant
            case SDL_KEYUP:
                switch (event.key.keysym.sym){
                    case SDLK_SPACE:
                        input->jump = 0;
                    break;

                    case SDLK_LEFT:
                        input->left = 0;
                    break;

                    case SDLK_RIGHT:
                        input->right = 0;
                    break;

                    case SDLK_UP:
                        input->jump = 0;
                    break;

                    default:
                    break;
                }
            break;
            case SDL_MOUSEBUTTONUP: /* Clic de la souris */
                if (input->jouer == 0){
                    if (event.button.button == SDL_BUTTON_LEFT){
                        if((event.button.x >= 180)&&(event.button.x <= 360)&&(event.button.y >= 240)&&(event.button.y <= 330))
                            input->jouer = 1;
                        else if((event.button.x >= 480)&&(event.button.x <= 660)&&(event.button.y >= 240)&&(event.button.y <= 330))
                            exit(0);
                    }
                }
                break;
        }

    }
}
