#include <engine.h>

void create_engine(Engine *e) {
    init_window(&e->winCtx, 1500, 900);
    e->running = false;
}

void run_engine(Engine *e) {
    e->running = true;
    SDL_Event event;

    while (e->running) {    
        while (SDL_PollEvent(&event)) {
            handle_event(e, event.type); 
        }

        SDL_RenderClear(e->winCtx.renderer);
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
