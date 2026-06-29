#pragma once

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} WindowCtx;

WindowCtx create_window(int w, int h);
void destroy_window(WindowCtx *ctx);
