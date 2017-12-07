#include "Initialize.h"

void Initialize::initialize_solution(Cell cells[][Config::NY], int NX, int NY) {
    const int rk_step = 0;

    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            if (cells[i][j].cx > -0.25 && cells[i][j].cx < 0.25 && cells[i][j].cy > -0.25 && cells[i][j].cy < 0.25) {
                cells[i][j].u[rk_step] = 1.0;
            } else {
                cells[i][j].u[rk_step] = 0.0;
            }
        }
    }
}
