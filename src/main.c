#include <SDL2/SDL.h>

#include <time.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600


int main(int argc, char *argv[])
{
    const char* title = "Bonsoir.";
    SDL_Init(SDL_INIT_EVERYTHING);  

    SDL_Window* window = SDL_CreateWindow(title, 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, 
        HEIGHT,
        SDL_WINDOW_OPENGL);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    int is_closed = 0;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    while(!is_closed){
        clock_t start = clock();
        //SDL_RenderClear(renderer);

        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT){
                is_closed = 1;
            }
        }
        //SDL_RenderPresent(renderer);
        
        // SDL_Delay(16);
        clock_t end = clock();
        float millis = (float)(end - start) / CLOCKS_PER_SEC * 1000;
        printf("%f ms\n", millis);
    }

}



