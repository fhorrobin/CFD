#include <math.h>
#include "Initialize.h"

void Initialize::initialize_solution (Cell *cells, int N) {
    const int rk_step = 0;

    for (int i = 0; i < N; i++) {
        cells[i].u[rk_step] = sin(M_PI * cells[i].cx);
    }
}