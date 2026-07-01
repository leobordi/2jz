#include <engine.h>

void create_engine(Engine *e) {
    init_window(&e->winCtx, 1500, 900);
    e->running = false;
}

void run_engine(Engine *e) {
    e->running = true;
    SDL_Event event;

    uint64_t last_time = SDL_GetPerformanceCounter();
    double freq = (double)SDL_GetPerformanceFrequency();

    while (e->running) {    
        uint64_t cur_time = SDL_GetPerformanceCounter();
        double delta = (cur_time - last_time) / freq;
        last_time = cur_time;

        while (SDL_PollEvent(&event)) {
            handle_event(e, event.type); 
        }
        
        SDL_SetRenderDrawColor(e->winCtx.renderer, 20, 20, 30, 255);
        SDL_RenderClear(e->winCtx.renderer);

        SDL_SetRenderDrawColor(e->winCtx.renderer, 255, 0, 0, 255);
        SDL_FRect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = 600;
        rect.h = 500;
        SDL_RenderFillRect(e->winCtx.renderer, &rect);

        SDL_RenderPresent(e->winCtx.renderer);
        SDL_Delay(16);
    }

    destroy_window(&e->winCtx);
}

void handle_event(Engine *e, uint32_t type) {
    switch (type) {
        case SDL_EVENT_QUIT:
            e->running = false;
            break;
    }
}
