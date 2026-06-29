#pragma once

#include "window.h" 
#include <stdbool.h>

typedef struct {
    WindowCtx winCtx;
    bool running; 
} Engine;

Engine create_engine();
void run_engine(Engine *e);
void handle_event(Engine *e, uint32_t type);
