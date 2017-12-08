/**
 * Configuration constants for CFD code
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include <string>

enum ReconstructorTypes {FIRST_ORDER, LAX_WENDROFF, BEAM_WARMING, FROMM, LIMITED_LW};

class Config {
    public:
        static const int NUM_X_CELLS = 150;
        static const int NUM_Y_CELLS = 200;
        static const int NUM_GHOST_CELLS = 4;
        static const int NUM_RK_STEPS = 3;
        static const double STOPPING_TIME = 2.0;
        static const int MAX_TIME_ITER = 100000;
        static const double MIN_X = -1.0;
        static const double MIN_Y = -1.0;
        static const double MAX_X = 1.0;
        static const double MAX_Y = 1.0;
        static const double ADVECTION_VELOCITY_X = 1.0;
        static const double ADVECTION_VELOCITY_Y = 1.0;
        static const double COURANT_NUMBER = 0.5;
        static const ReconstructorTypes RECONST_TYPE = LIMITED_LW;

        static const int NX = Config::NUM_X_CELLS + 2 * Config::NUM_GHOST_CELLS;
        static const int NY = Config::NUM_Y_CELLS + 2 * Config::NUM_GHOST_CELLS;
};

#endif
