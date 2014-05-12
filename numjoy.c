#include <stdio.h>

#include <SDL2/SDL.h>

int main()
{
    int num_joy, i;

    // Init SDL2
    SDL_Init(SDL_INIT_JOYSTICK
            | SDL_INIT_HAPTIC
            | SDL_INIT_GAMECONTROLLER);

    num_joy=SDL_NumJoysticks();
    printf("%d joysticks found\n",num_joy);
    for (i=0; i<num_joy; ++i) {
        SDL_Joystick *joystick=SDL_JoystickOpen(i);
        printf("%d: %s (Haptic: %s)\n",i,SDL_JoystickName(joystick),SDL_JoystickIsHaptic(joystick)?"Yes":"No");
    }
    for (i=0; i<SDL_NumHaptics(); ++i) {
        SDL_Haptic* hapt=SDL_HapticOpen(i);
        int axes = SDL_HapticNumAxes(hapt);
        int effects = SDL_HapticNumEffects(hapt);
        printf("%d: %s : %d axis : %d effects\n",i,SDL_HapticName(i),axes,effects);
        SDL_HapticRumbleInit(hapt);
        SDL_HapticRumblePlay(hapt,0.1f,1000);
        SDL_Delay(1500);
        SDL_HapticRumbleStop(hapt);
    }

    SDL_Quit();
    return 0;
}
