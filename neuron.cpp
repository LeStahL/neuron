#include <Windows.h>
#include <SDL.h>

#include <iostream>

using namespace std;

#define CHECK(PTR, SYMBOL, CLEANUP) \
if(PTR == nullptr) \
{ \
    cout << "ERROR: " << SYMBOL << SDL_GetError() << endl; \
    CLEANUP; \
    return 1; \
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    CHECK(window, "SDL_CreateWindow", SDL_Quit());

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    CHECK(renderer, "SDL_CreateRenderer", SDL_DestroyWindow(window); SDL_Quit());

    

    return 0;
}