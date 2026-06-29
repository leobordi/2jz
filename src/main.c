#include <stdio.h>
#include "../include/engine.h"

int main() {
    Engine e = create_engine();
    run_engine(&e);

    return 0;
}
