#include <stdio.h>

#include <SDL2/SDL.h>

int main()
{
    SDL_Window* win;
    SDL_Window* oldwin=NULL;

    // Init SDL2
    SDL_Init(SDL_INIT_JOYSTICK
            | SDL_INIT_HAPTIC
            | SDL_INIT_GAMECONTROLLER);

    while (SDL_QuitRequested()==SDL_FALSE) {
        win=SDL_GetMouseFocus();
        if (win==oldwin)
            continue;
        printf("Focus: %lx\n",(unsigned long int)win);
        oldwin=win;
    }

    SDL_Quit();
    return 0;
}
