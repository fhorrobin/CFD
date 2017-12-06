#include "Initialize.h"

void Initialize::initialize_solution (Cell *cells, int N) {
    const int rk_step = 0;

    for (int i = 0; i < N; i++) {
        if (cells[i].cx > -0.25 && cells[i].cx < 0.25) {
            cells[i].u[rk_step] = 1.0;
        } else {
            cells[i].u[rk_step] = 0.0;
        }
    }
}
