#include <SDL2/SDL.h>
int main()
{
    SDL_Window *window;
    SDL_Event e;
    unsigned int i = 0, t = 0;
    const char *titles[] = {
        "                       ",
        ">                      ",
        "t>                     ",
        "th>                    ",
        "thi>                   ",
        "this>                  ",
        "this >                 ",
        "this w>                ",
        "this wi>               ",
        "this win>              ",
        "this wind>             ",
        "this windo>            ",
        "this window>           ",
        "this window'>          ",
        "this window's>         ",
        "this window's >        ",
        "this window's t>       ",
        "this window's ti>      ",
        "this window's tit>     ",
        "this window's titl>    ",
        "this window's title>   ",
        "this window's title >  ",
        "this window's title i> ",
        "this window's title is>",
        "this window's title is!",
        "this window's title i<!",
        "this window's title <g!",
        "this window's title< g!",
        "this window's titl<  g!",
        "this window's tit<n  g!",
        "this window's ti< n  g!",
        "this window's t<  n  g!",
        "this window's <i  n  g!",
        "this window's< i  n  g!",
        "this window'<  i  n  g!",
        "this window<g  i  n  g!",
        "this windo< g  i  n  g!",
        "this wind<  g  i  n  g!",
        "this win<n  g  i  n  g!",
        "this wi< n  g  i  n  g!",
        "this w<  n  g  i  n  g!",
        "this <a  n  g  i  n  g!",
        "this< a  n  g  i  n  g!",
        "thi<  a  n  g  i  n  g!",
        "th<h  a  n  g  i  n  g!",
        "t< h  a  n  g  i  n  g!",
        "<  h  a  n  g  i  n  g!",
        "c  h  a  n  g  i  n  g!",
        "c  h  a  n  g  i  n  g!",
        "                       ",
        "                       ",
        "c  h  a  n  g  i  n  g!",
        "                       ",
        "                       ",
        "c  h  a  n  g  i  n  g!",
        "                       ",
        "                       ",
        "c  h  a  n  g  i  n  g!",
        "                       ",
        "                       ",
        "                       "
    };
    const int titlecount=(sizeof(titles)/sizeof(titles[0]));

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(titles[0],
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            320, 240, SDL_WINDOW_RESIZABLE);
    while ( e.type!=SDL_QUIT && e.type!=SDL_KEYDOWN ) {
        SDL_PollEvent(&e);
        if (!(++t%9)) {
            SDL_SetWindowTitle(window, titles[(i++)%titlecount]);
        }
        SDL_Delay(20);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
