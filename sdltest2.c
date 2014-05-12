#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"

int main()
{
  SDL_Init(0);
  SDL_Window* window = SDL_CreateWindow("",0,0,0,0,SDL_WINDOW_HIDDEN);

  SDL_SysWMinfo info;

  SDL_VERSION(&info.version); // initialize info structure with SDL version info

  if (SDL_GetWindowWMInfo(window,&info)) { // the call returns true on success
    // success
    const char *subsystem = "an unknown system!";
    switch (info.subsystem) {
      case SDL_SYSWM_WINDOWS:   subsystem = "Microsoft Windows(TM)";  break;
      case SDL_SYSWM_X11:       subsystem = "X Window System";        break;
      case SDL_SYSWM_DIRECTFB:  subsystem = "DirectFB";               break;
      case SDL_SYSWM_COCOA:     subsystem = "Apple OS X";             break;
      case SDL_SYSWM_UIKIT:     subsystem = "UIKit";                  break;
      case SDL_SYSWM_UNKNOWN:   break;
      default:                  break;
    }

    SDL_Log("This program is running SDL version %d.%d.%d on %s\n",
        (int)info.version.major,
        (int)info.version.minor,
        (int)info.version.patch,
        subsystem);

  } else {
    // call failed
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Couldn't get window information: %s\n", SDL_GetError());
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
