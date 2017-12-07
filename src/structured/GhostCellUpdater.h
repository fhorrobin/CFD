#ifndef GHOSTCELLUPDATER_H_
#define GHOSTCELLUPDATER_H_
#include "Cell.h"

class GhostCellUpdater {
    public:
        static void updateGhostCells(Cell cells[][Config::NY], int rk_step);
};

#endif
