#include "window.h"

WindowCtx create_window(int w, int h) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        printf("Errore di inizializzazione: %s\n", SDL_GetError());
        exit(-1);
    }
    
    WindowCtx ctx;
    ctx.window = SDL_CreateWindow("Test engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN); 
    if (!ctx.window) {
        printf("Errore di creazione finestra!\n");
        exit(-1);
    } 
    
    return ctx;
}

void destroy_window(WindowCtx *ctx) {
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    SDL_Quit(); 
}
