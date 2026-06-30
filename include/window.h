#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "common.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
} WindowCtx;

void init_window(WindowCtx *ctx, int w, int h);
void destroy_window(WindowCtx *ctx);
