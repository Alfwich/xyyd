#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO) == -1)
    {
        printf("Failed to init SDL\n");
        return -1;
    }

    SDL_Window *const window = SDL_CreateWindow("Test Window!", 640, 480, 0);
    SDL_Renderer *const renderer = SDL_CreateRenderer(window, NULL, 0);

    SDL_Rect viewport = {
        .x = 0,
        .y = 0,
        .w = 640,
        .h = 480,
    };
    SDL_SetRenderViewport(renderer, &viewport);

    int running = 1;
    while (running)
    {
        SDL_Event event;

        // SDL_PumpEvents();
        static float width = 0.f;
        static float height = 0.f;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                printf("Key Down: %d\n", event.key.keysym.scancode);

                if (event.key.keysym.scancode == SDL_SCANCODE_Q)
                {
                    running = 0;
                }
            }
            else if (event.type == SDL_EVENT_MOUSE_MOTION)
            {
                width = event.motion.x;
                height = event.motion.y;
            }
        }
        SDL_FRect rect = {
            .x = 0.f,
            .y = 0.f,
            .w = width,
            .h = height,
        };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, 0xFF);
        SDL_RenderRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}