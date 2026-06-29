#include <engine.h>

Engine create_engine() {
    Engine e;
    e.winCtx = create_window(1500, 900);
    e.running = false;
    return e;
}

void run_engine(Engine *e) {
    e->running = true;
    SDL_Event event;

    while (e->running) {    
        while (SDL_PollEvent(&event)) {
            handle_event(e, event.type); 
        }

        SDL_Delay(16);
    }

    destroy_window(&e->winCtx);
}

void handle_event(Engine *e, uint32_t type) {
    switch (type) {
        case SDL_QUIT:
            e->running = false;
            break;
    }
}
