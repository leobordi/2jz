#include "window.h"

void init_window(WindowCtx *ctx, int w, int h) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        exit(-1);
    }
    
    if (!SDL_CreateWindowAndRenderer("Test engine", w, h, SDL_WINDOW_RESIZABLE, &ctx->window, &ctx->renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        exit(-1);
    }

    ctx->texture = SDL_CreateTexture(ctx->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, w, h);
    if (!ctx->texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s", SDL_GetError());
        exit(-1);
    }

    SDL_SetRenderTarget(ctx->renderer, ctx->texture);
    SDL_SetRenderDrawColor(ctx->renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(ctx->renderer);
    SDL_RenderPresent(ctx->renderer);
}

void destroy_window(WindowCtx *ctx) {
    SDL_DestroyTexture(ctx->texture);
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    SDL_Quit(); 
}
