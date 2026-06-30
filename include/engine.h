#pragma once

#include "common.h"
#include "window.h" 

typedef struct {
    WindowCtx winCtx;
    bool running; 
} Engine;

void create_engine(Engine *e);
void run_engine(Engine *e);
void handle_event(Engine *e, uint32_t type);
